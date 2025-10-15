"use strict";
// Manhattan state
Object.defineProperty(exports, "__esModule", { value: true });
exports.Direction = void 0;
exports.getDirectionString = getDirectionString;
exports.createManhattanState = createManhattanState;
exports.createManhattanStateFromPrevious = createManhattanStateFromPrevious;
exports.areStatesEqual = areStatesEqual;
exports.getNeighbours = getNeighbours;
var board_1 = require("./board");
var Direction;
(function (Direction) {
    Direction[Direction["LEFT"] = 0] = "LEFT";
    Direction[Direction["RIGHT"] = 1] = "RIGHT";
    Direction[Direction["TOP"] = 2] = "TOP";
    Direction[Direction["DOWN"] = 3] = "DOWN";
    Direction[Direction["NONE"] = 4] = "NONE";
})(Direction || (exports.Direction = Direction = {}));
function getDirectionString(direction) {
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
function createManhattanState(board, direction, g) {
    if (direction === void 0) { direction = Direction.NONE; }
    if (g === void 0) { g = 0; }
    return {
        board: board,
        direction: direction,
        g: g,
        h: (0, board_1.manhattanDistance)(board),
    };
}
function createManhattanStateFromPrevious(board, direction, g, h, previousEmptyTileIndex) {
    return {
        board: board,
        direction: direction,
        g: g,
        h: h +
            (0, board_1.manhattanByIndex)(board, previousEmptyTileIndex) +
            (0, board_1.manhattanByIndex)(board, board.emptyTileIndex),
    };
}
function areStatesEqual(state1, state2) {
    return (0, board_1.areBoardsEqual)(state1.board, state2.board);
}
function getNeighbours(currentState) {
    var neighbours = [];
    var left = (0, board_1.getLeft)(currentState.board);
    var right = (0, board_1.getRight)(currentState.board);
    var top = (0, board_1.getTop)(currentState.board);
    var down = (0, board_1.getBottom)(currentState.board);
    if (left) {
        neighbours.push(createManhattanStateFromPrevious(left, Direction.LEFT, currentState.g + 1, currentState.h -
            (0, board_1.manhattanByIndex)(currentState.board, currentState.board.emptyTileIndex) -
            (0, board_1.manhattanByIndex)(currentState.board, left.emptyTileIndex), currentState.board.emptyTileIndex));
    }
    if (right) {
        neighbours.push(createManhattanStateFromPrevious(right, Direction.RIGHT, currentState.g + 1, currentState.h -
            (0, board_1.manhattanByIndex)(currentState.board, currentState.board.emptyTileIndex) -
            (0, board_1.manhattanByIndex)(currentState.board, right.emptyTileIndex), currentState.board.emptyTileIndex));
    }
    if (top) {
        neighbours.push(createManhattanStateFromPrevious(top, Direction.TOP, currentState.g + 1, currentState.h -
            (0, board_1.manhattanByIndex)(currentState.board, currentState.board.emptyTileIndex) -
            (0, board_1.manhattanByIndex)(currentState.board, top.emptyTileIndex), currentState.board.emptyTileIndex));
    }
    if (down) {
        neighbours.push(createManhattanStateFromPrevious(down, Direction.DOWN, currentState.g + 1, currentState.h -
            (0, board_1.manhattanByIndex)(currentState.board, currentState.board.emptyTileIndex) -
            (0, board_1.manhattanByIndex)(currentState.board, down.emptyTileIndex), currentState.board.emptyTileIndex));
    }
    return neighbours;
}
