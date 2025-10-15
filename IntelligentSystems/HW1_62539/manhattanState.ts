// Manhattan state

import {
  areBoardsEqual,
  Board,
  getBottom,
  getLeft,
  getRight,
  getTop,
  manhattanByIndex,
  manhattanDistance,
} from "./board";

export enum Direction {
  LEFT,
  RIGHT,
  TOP,
  DOWN,
  NONE,
}

export interface ManhattanState {
  board: Board;
  direction: Direction;
  g: number;
  h: number;
}

export function getDirectionString(direction: Direction) {
  switch (direction) {
    case Direction.LEFT:
      return "right";
    case Direction.RIGHT:
      return "left";
    case Direction.TOP:
      return "down";
    case Direction.DOWN:
      return "up";
    default:
      return "";
  }
}

export function createManhattanState(
  board: Board,
  direction = Direction.NONE,
  g = 0
): ManhattanState {
  return {
    board,
    direction,
    g,
    h: manhattanDistance(board),
  };
}

export function createManhattanStateFromPrevious(
  board: Board,
  direction: Direction,
  g: number,
  h: number,
  previousEmptyTileIndex: number
): ManhattanState {
  return {
    board,
    direction,
    g,
    h:
      h +
      manhattanByIndex(board, previousEmptyTileIndex) +
      manhattanByIndex(board, board.emptyTileIndex),
  };
}

export function areStatesEqual(state1: ManhattanState, state2: ManhattanState) {
  return areBoardsEqual(state1.board, state2.board);
}

export function getNeighbours(currentState: ManhattanState) {
  const neighbours: ManhattanState[] = [];
  const left = getLeft(currentState.board);
  const right = getRight(currentState.board);
  const top = getTop(currentState.board);
  const down = getBottom(currentState.board);

  if (left) {
    neighbours.push(
      createManhattanStateFromPrevious(
        left,
        Direction.LEFT,
        currentState.g + 1,
        currentState.h -
          manhattanByIndex(
            currentState.board,
            currentState.board.emptyTileIndex
          ) -
          manhattanByIndex(currentState.board, left.emptyTileIndex),
        currentState.board.emptyTileIndex
      )
    );
  }

  if (right) {
    neighbours.push(
      createManhattanStateFromPrevious(
        right,
        Direction.RIGHT,
        currentState.g + 1,
        currentState.h -
          manhattanByIndex(
            currentState.board,
            currentState.board.emptyTileIndex
          ) -
          manhattanByIndex(currentState.board, right.emptyTileIndex),
        currentState.board.emptyTileIndex
      )
    );
  }

  if (top) {
    neighbours.push(
      createManhattanStateFromPrevious(
        top,
        Direction.TOP,
        currentState.g + 1,
        currentState.h -
          manhattanByIndex(
            currentState.board,
            currentState.board.emptyTileIndex
          ) -
          manhattanByIndex(currentState.board, top.emptyTileIndex),
        currentState.board.emptyTileIndex
      )
    );
  }

  if (down) {
    neighbours.push(
      createManhattanStateFromPrevious(
        down,
        Direction.DOWN,
        currentState.g + 1,
        currentState.h -
          manhattanByIndex(
            currentState.board,
            currentState.board.emptyTileIndex
          ) -
          manhattanByIndex(currentState.board, down.emptyTileIndex),
        currentState.board.emptyTileIndex
      )
    );
  }

  return neighbours;
}
