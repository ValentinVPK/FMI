import { goal, goalIndexes } from "./main";

export interface Board {
  tiles: number[];
  dimension: number;
  emptyTileIndex: number;
}

interface TilePosition {
  [key: number]: { row: number; column: number };
}

export function boardToString(board: Board): string {
  return JSON.stringify(board);
}

export function createBoard(
  size: number,
  tiles: number[],
  emptyTileIndex: number
): Board {
  size = size + 1;
  return {
    tiles,
    dimension: Math.sqrt(size),
    emptyTileIndex,
  };
}

export function areBoardsEqual(board1: Board, board2: Board) {
  return board1.tiles.every((tile, index) => tile === board2.tiles[index]);
}

export function isSolvable(board: Board) {
  const { tiles, dimension, emptyTileIndex } = board;
  let inversions = 0;
  for (let i = 0; i < tiles.length - 1; i++) {
    for (let j = i + 1; j < tiles.length; j++) {
      if (tiles[i] > 0 && tiles[j] > 0 && tiles[i] > tiles[j]) {
        inversions++;
      }
    }
  }

  if (dimension % 2 !== 0) {
    return inversions % 2 === 0;
  } else {
    const emptyRowIndex = Math.floor(emptyTileIndex / dimension);
    const sum = emptyRowIndex + inversions;
    return sum === 0 || (inversions + emptyRowIndex) % 2 !== 0;
  }
}

export function goalBoard(size: number, endEmptyTileIndex: number): Board {
  if (endEmptyTileIndex == -1) {
    endEmptyTileIndex = size;
  }
  size = size + 1;

  const goalBoard: Board = {
    tiles: new Array<number>(size + 1),
    dimension: Math.sqrt(size),
    emptyTileIndex: endEmptyTileIndex,
  };

  let i = 0;
  for (; i < endEmptyTileIndex; i++) {
    goalBoard.tiles[i] = i + 1;
  }

  for (; i <= size; i++) {
    goalBoard.tiles[i] = i;
  }

  goalBoard.tiles[endEmptyTileIndex] = 0;

  return goalBoard;
}

export function manhattanDistance(currentBoard: Board) {
  const currentPositions: TilePosition = {};
  const goalPositions: TilePosition = {};
  const size = currentBoard.tiles.length;

  for (let i = 0; i < size; i++) {
    currentPositions[currentBoard.tiles[i]] = {
      row: Math.floor(i / currentBoard.dimension),
      column: i % currentBoard.dimension,
    };

    goalPositions[goal.tiles[i]] = {
      row: Math.floor(i / goal.dimension),
      column: i % goal.dimension,
    };
  }

  let sum = 0;
  for (const tile in currentPositions) {
    sum +=
      Math.abs(currentPositions[tile].row - goalPositions[tile].row) +
      Math.abs(currentPositions[tile].column - goalPositions[tile].column);
  }

  return sum;
}

export function manhattanByIndex(currentBoard: Board, index: number) {
  return (
    Math.abs(
      Math.floor(index / currentBoard.dimension) -
        Math.floor(
          goalIndexes[currentBoard.tiles[index]] / currentBoard.dimension
        )
    ) +
    Math.abs(
      (index % currentBoard.dimension) -
        (goalIndexes[currentBoard.tiles[index]] % currentBoard.dimension)
    )
  );
}

function isValidDimension(tileRowOrCol: number, boardDimension: number) {
  return tileRowOrCol >= 0 && tileRowOrCol < boardDimension;
}

export function getLeft(currentBoard: Board): Board | null {
  const { dimension, emptyTileIndex } = currentBoard;
  const emptyTileColumn = emptyTileIndex % dimension;

  if (isValidDimension(emptyTileColumn - 1, dimension)) {
    const tempBoard = { ...currentBoard, tiles: [...currentBoard.tiles] };
    const temp = tempBoard.tiles[emptyTileIndex - 1];
    tempBoard.tiles[emptyTileIndex - 1] = tempBoard.tiles[emptyTileIndex];
    tempBoard.tiles[emptyTileIndex] = temp;
    tempBoard.emptyTileIndex = emptyTileIndex - 1;

    return tempBoard;
  }

  return null;
}

export function getRight(currentBoard: Board): Board | null {
  const { dimension, emptyTileIndex } = currentBoard;
  const emptyTileColumn = emptyTileIndex % dimension;

  if (isValidDimension(emptyTileColumn + 1, dimension)) {
    const tempBoard = { ...currentBoard, tiles: [...currentBoard.tiles] };
    const temp = tempBoard.tiles[emptyTileIndex + 1];
    tempBoard.tiles[emptyTileIndex + 1] = tempBoard.tiles[emptyTileIndex];
    tempBoard.tiles[emptyTileIndex] = temp;
    tempBoard.emptyTileIndex = emptyTileIndex + 1;

    return tempBoard;
  }

  return null;
}

export function getTop(currentBoard: Board): Board | null {
  const { dimension, emptyTileIndex } = currentBoard;
  const emptyTileRow = Math.floor(emptyTileIndex / dimension);

  if (isValidDimension(emptyTileRow - 1, dimension)) {
    const tempBoard = { ...currentBoard, tiles: [...currentBoard.tiles] };
    const temp = tempBoard.tiles[emptyTileIndex - dimension];
    tempBoard.tiles[emptyTileIndex - dimension] =
      tempBoard.tiles[emptyTileIndex];
    tempBoard.tiles[emptyTileIndex] = temp;
    tempBoard.emptyTileIndex = emptyTileIndex - dimension;

    return tempBoard;
  }

  return null;
}

export function getBottom(currentBoard: Board): Board | null {
  const { dimension, emptyTileIndex } = currentBoard;
  const emptyTileRow = Math.floor(emptyTileIndex / dimension);

  if (isValidDimension(emptyTileRow + 1, dimension)) {
    const tempBoard = { ...currentBoard, tiles: [...currentBoard.tiles] };
    const temp = tempBoard.tiles[emptyTileIndex + dimension];
    tempBoard.tiles[emptyTileIndex + dimension] =
      tempBoard.tiles[emptyTileIndex];
    tempBoard.tiles[emptyTileIndex] = temp;
    tempBoard.emptyTileIndex = emptyTileIndex + dimension;

    return tempBoard;
  }

  return null;
}
