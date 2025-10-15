"use strict";
var __assign = (this && this.__assign) || function () {
    __assign = Object.assign || function(t) {
        for (var s, i = 1, n = arguments.length; i < n; i++) {
            s = arguments[i];
            for (var p in s) if (Object.prototype.hasOwnProperty.call(s, p))
                t[p] = s[p];
        }
        return t;
    };
    return __assign.apply(this, arguments);
};
var __spreadArray = (this && this.__spreadArray) || function (to, from, pack) {
    if (pack || arguments.length === 2) for (var i = 0, l = from.length, ar; i < l; i++) {
        if (ar || !(i in from)) {
            if (!ar) ar = Array.prototype.slice.call(from, 0, i);
            ar[i] = from[i];
        }
    }
    return to.concat(ar || Array.prototype.slice.call(from));
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.boardToString = boardToString;
exports.createBoard = createBoard;
exports.areBoardsEqual = areBoardsEqual;
exports.isSolvable = isSolvable;
exports.goalBoard = goalBoard;
exports.manhattanDistance = manhattanDistance;
exports.manhattanByIndex = manhattanByIndex;
exports.getLeft = getLeft;
exports.getRight = getRight;
exports.getTop = getTop;
exports.getBottom = getBottom;
var main_1 = require("./main");
function boardToString(board) {
    return JSON.stringify(board);
}
function createBoard(size, tiles, emptyTileIndex) {
    size = size + 1;
    return {
        tiles: tiles,
        dimension: Math.sqrt(size),
        emptyTileIndex: emptyTileIndex,
    };
}
function areBoardsEqual(board1, board2) {
    return board1.tiles.every(function (tile, index) { return tile === board2.tiles[index]; });
}
function isSolvable(board) {
    var tiles = board.tiles, dimension = board.dimension, emptyTileIndex = board.emptyTileIndex;
    var inversions = 0;
    for (var i = 0; i < tiles.length - 1; i++) {
        for (var j = i + 1; j < tiles.length; j++) {
            if (tiles[i] > 0 && tiles[j] > 0 && tiles[i] > tiles[j]) {
                inversions++;
            }
        }
    }
    if (dimension % 2 !== 0) {
        return inversions % 2 === 0;
    }
    else {
        var emptyRowIndex = Math.floor(emptyTileIndex / dimension);
        var sum = emptyRowIndex + inversions;
        return sum === 0 || (inversions + emptyRowIndex) % 2 !== 0;
    }
}
function goalBoard(size, endEmptyTileIndex) {
    if (endEmptyTileIndex == -1) {
        endEmptyTileIndex = size;
    }
    size = size + 1;
    var goalBoard = {
        tiles: new Array(size + 1),
        dimension: Math.sqrt(size),
        emptyTileIndex: endEmptyTileIndex,
    };
    var i = 0;
    for (; i < endEmptyTileIndex; i++) {
        goalBoard.tiles[i] = i + 1;
    }
    for (; i <= size; i++) {
        goalBoard.tiles[i] = i;
    }
    goalBoard.tiles[endEmptyTileIndex] = 0;
    return goalBoard;
}
function manhattanDistance(currentBoard) {
    var currentPositions = {};
    var goalPositions = {};
    var size = currentBoard.tiles.length;
    for (var i = 0; i < size; i++) {
        currentPositions[currentBoard.tiles[i]] = {
            row: Math.floor(i / currentBoard.dimension),
            column: i % currentBoard.dimension,
        };
        goalPositions[main_1.goal.tiles[i]] = {
            row: Math.floor(i / main_1.goal.dimension),
            column: i % main_1.goal.dimension,
        };
    }
    var sum = 0;
    for (var tile in currentPositions) {
        sum +=
            Math.abs(currentPositions[tile].row - goalPositions[tile].row) +
                Math.abs(currentPositions[tile].column - goalPositions[tile].column);
    }
    return sum;
}
function manhattanByIndex(currentBoard, index) {
    return (Math.abs(Math.floor(index / currentBoard.dimension) -
        Math.floor(main_1.goalIndexes[currentBoard.tiles[index]] / currentBoard.dimension)) +
        Math.abs((index % currentBoard.dimension) -
            (main_1.goalIndexes[currentBoard.tiles[index]] % currentBoard.dimension)));
}
function isValidDimension(tileRowOrCol, boardDimension) {
    return tileRowOrCol >= 0 && tileRowOrCol < boardDimension;
}
function getLeft(currentBoard) {
    var dimension = currentBoard.dimension, emptyTileIndex = currentBoard.emptyTileIndex;
    var emptyTileColumn = emptyTileIndex % dimension;
    if (isValidDimension(emptyTileColumn - 1, dimension)) {
        var tempBoard = __assign(__assign({}, currentBoard), { tiles: __spreadArray([], currentBoard.tiles, true) });
        var temp = tempBoard.tiles[emptyTileIndex - 1];
        tempBoard.tiles[emptyTileIndex - 1] = tempBoard.tiles[emptyTileIndex];
        tempBoard.tiles[emptyTileIndex] = temp;
        tempBoard.emptyTileIndex = emptyTileIndex - 1;
        return tempBoard;
    }
    return null;
}
function getRight(currentBoard) {
    var dimension = currentBoard.dimension, emptyTileIndex = currentBoard.emptyTileIndex;
    var emptyTileColumn = emptyTileIndex % dimension;
    if (isValidDimension(emptyTileColumn + 1, dimension)) {
        var tempBoard = __assign(__assign({}, currentBoard), { tiles: __spreadArray([], currentBoard.tiles, true) });
        var temp = tempBoard.tiles[emptyTileIndex + 1];
        tempBoard.tiles[emptyTileIndex + 1] = tempBoard.tiles[emptyTileIndex];
        tempBoard.tiles[emptyTileIndex] = temp;
        tempBoard.emptyTileIndex = emptyTileIndex + 1;
        return tempBoard;
    }
    return null;
}
function getTop(currentBoard) {
    var dimension = currentBoard.dimension, emptyTileIndex = currentBoard.emptyTileIndex;
    var emptyTileRow = Math.floor(emptyTileIndex / dimension);
    if (isValidDimension(emptyTileRow - 1, dimension)) {
        var tempBoard = __assign(__assign({}, currentBoard), { tiles: __spreadArray([], currentBoard.tiles, true) });
        var temp = tempBoard.tiles[emptyTileIndex - dimension];
        tempBoard.tiles[emptyTileIndex - dimension] =
            tempBoard.tiles[emptyTileIndex];
        tempBoard.tiles[emptyTileIndex] = temp;
        tempBoard.emptyTileIndex = emptyTileIndex - dimension;
        return tempBoard;
    }
    return null;
}
function getBottom(currentBoard) {
    var dimension = currentBoard.dimension, emptyTileIndex = currentBoard.emptyTileIndex;
    var emptyTileRow = Math.floor(emptyTileIndex / dimension);
    if (isValidDimension(emptyTileRow + 1, dimension)) {
        var tempBoard = __assign(__assign({}, currentBoard), { tiles: __spreadArray([], currentBoard.tiles, true) });
        var temp = tempBoard.tiles[emptyTileIndex + dimension];
        tempBoard.tiles[emptyTileIndex + dimension] =
            tempBoard.tiles[emptyTileIndex];
        tempBoard.tiles[emptyTileIndex] = temp;
        tempBoard.emptyTileIndex = emptyTileIndex + dimension;
        return tempBoard;
    }
    return null;
}
