import * as readline from "readline";
import Stack from "./stack";
import { performance } from "perf_hooks";
import {
  areBoardsEqual,
  Board,
  boardToString,
  createBoard,
  goalBoard,
  isSolvable,
} from "./board";
import {
  createManhattanState,
  Direction,
  getDirectionString,
  getNeighbours,
  ManhattanState,
} from "./manhattanState";

const path = new Stack<ManhattanState>();
const visited = new Set<string>();
export let goal: Board = { tiles: [], dimension: 0, emptyTileIndex: 0 };
export const goalIndexes: Record<number, number> = {};

function searchFromRoot(root: ManhattanState) {
  let bound = root.h;
  path.push(root);
  visited.add(boardToString(root.board));

  while (true) {
    const t = search(bound);
    if (t === Number.MAX_SAFE_INTEGER) {
      return { path: new Stack<ManhattanState>(), steps: -1 };
    }

    if (t === 0) {
      return { path: path, steps: path.size() - 1 };
    }

    bound = t;
  }
}

function search(bound: number) {
  const node = path.peek();
  const f = node.g + node.h;

  if (f > bound) {
    return f;
  }

  if (areBoardsEqual(node.board, goal)) {
    return 0;
  }

  let min = Number.MAX_SAFE_INTEGER;

  for (const child of getNeighbours(node)) {
    const childBoardString = boardToString(child.board);
    if (!visited.has(childBoardString)) {
      path.push(child);
      visited.add(childBoardString);
      const t = search(bound);

      if (t === 0) {
        return 0;
      }

      if (t < min) {
        min = t;
      }

      path.pop();
      visited.delete(childBoardString);
    }
  }

  return min;
}

async function main(printTime = false) {
  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
  });

  const ask = (question: string) =>
    new Promise((resolve) => rl.question(question, resolve));

  const size = Number((await ask("Enter the board size: ")) as string);
  const emptyTileIndex = Number(
    (await ask("Enter the empty tile index: ")) as string
  );

  const inputTiles = (
    (await ask(
      "Enter board tiles in row-major order (0 for the empty tile): "
    )) as string
  )
    .split(" ")
    .map(Number);
  rl.close();

  const board = createBoard(size, inputTiles, inputTiles.indexOf(0));
  goal = goalBoard(size, emptyTileIndex);
  for (let i = 0; i < goal.tiles.length; i++) {
    goalIndexes[goal.tiles[i]] = i;
  }
  const startState = createManhattanState(board, Direction.NONE, 0);

  const startTime = performance.now();
  if (!isSolvable(board)) {
    console.log("The board is not solvable");
    console.log(-1);
    return;
  }

  const result = searchFromRoot(startState);

  console.log(result.steps);
  if (result.steps !== -1) {
    while (result.path.size() !== 0) {
      console.log(getDirectionString(result.path.peek().direction));
      result.path.pop();
    }
  }

  if (printTime) {
    const endTime = performance.now();
    const duration = (endTime - startTime) / 1000; // Convert to seconds
    console.log(`${duration.toFixed(2)} seconds`);
  }
}

main(true);
