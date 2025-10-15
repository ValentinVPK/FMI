"use strict";
var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
var __generator = (this && this.__generator) || function (thisArg, body) {
    var _ = { label: 0, sent: function() { if (t[0] & 1) throw t[1]; return t[1]; }, trys: [], ops: [] }, f, y, t, g = Object.create((typeof Iterator === "function" ? Iterator : Object).prototype);
    return g.next = verb(0), g["throw"] = verb(1), g["return"] = verb(2), typeof Symbol === "function" && (g[Symbol.iterator] = function() { return this; }), g;
    function verb(n) { return function (v) { return step([n, v]); }; }
    function step(op) {
        if (f) throw new TypeError("Generator is already executing.");
        while (g && (g = 0, op[0] && (_ = 0)), _) try {
            if (f = 1, y && (t = op[0] & 2 ? y["return"] : op[0] ? y["throw"] || ((t = y["return"]) && t.call(y), 0) : y.next) && !(t = t.call(y, op[1])).done) return t;
            if (y = 0, t) op = [op[0] & 2, t.value];
            switch (op[0]) {
                case 0: case 1: t = op; break;
                case 4: _.label++; return { value: op[1], done: false };
                case 5: _.label++; y = op[1]; op = [0]; continue;
                case 7: op = _.ops.pop(); _.trys.pop(); continue;
                default:
                    if (!(t = _.trys, t = t.length > 0 && t[t.length - 1]) && (op[0] === 6 || op[0] === 2)) { _ = 0; continue; }
                    if (op[0] === 3 && (!t || (op[1] > t[0] && op[1] < t[3]))) { _.label = op[1]; break; }
                    if (op[0] === 6 && _.label < t[1]) { _.label = t[1]; t = op; break; }
                    if (t && _.label < t[2]) { _.label = t[2]; _.ops.push(op); break; }
                    if (t[2]) _.ops.pop();
                    _.trys.pop(); continue;
            }
            op = body.call(thisArg, _);
        } catch (e) { op = [6, e]; y = 0; } finally { f = t = 0; }
        if (op[0] & 5) throw op[1]; return { value: op[0] ? op[1] : void 0, done: true };
    }
};
Object.defineProperty(exports, "__esModule", { value: true });
var readline = require("readline");
var perf_hooks_1 = require("perf_hooks");
var ITERATION_LIMIT = 100000;
var N = 0;
var queenRowIndexByColumn = []; // Stores the row index of the queen in each column.
var queensInRow = []; // Tracks how many queens are in each row.
var queensInDiagonal1 = []; // Tracks queens on diagonals sloping from top-left to bottom-right
var queensInDiagonal2 = []; // Tracks queens on diagonals sloping from top-right to bottom-left
var conflictsPerQueen = []; // Stores the number of conflicts for each queen. The index of this array corresponds to the column of the queen.
function getRandomInteger(min, max) {
    return Math.floor(Math.random() * (max - min + 1)) + min;
}
function updateConflicts() {
    var totalConflicts = 0;
    for (var i = 0; i < N; i++) {
        conflictsPerQueen[i] = getConflictsForQueen(i);
        totalConflicts += conflictsPerQueen[i];
    }
    return totalConflicts;
}
function moveQueenToNewRow(col, newRow) {
    var oldRow = queenRowIndexByColumn[col];
    queensInRow[oldRow]--;
    queensInRow[newRow]++;
    queensInDiagonal1[N - 1 + col - oldRow]--;
    queensInDiagonal2[col + oldRow]--;
    queensInDiagonal1[N - 1 + col - newRow]++;
    queensInDiagonal2[col + newRow]++;
    queenRowIndexByColumn[col] = newRow;
}
function getRowWithLeastConflicts(col) {
    var potentialConflicts = new Array(N).fill(0);
    for (var i = 0; i < N; i++) {
        if (i === col) {
            continue;
        }
        var row = queenRowIndexByColumn[i];
        potentialConflicts[row]++;
        var diagonal1 = row + Math.abs(i - col);
        var diagonal2 = row - Math.abs(i - col);
        if (diagonal1 >= 0 && diagonal1 < N) {
            potentialConflicts[diagonal1]++;
        }
        if (diagonal2 >= 0 && diagonal2 < N) {
            potentialConflicts[diagonal2]++;
        }
    }
    var possibleRows = [];
    var minConflicts = N + 1;
    for (var i = 0; i < N; i++) {
        if (potentialConflicts[i] < minConflicts) {
            minConflicts = potentialConflicts[i];
            possibleRows = [i];
        }
        else if (potentialConflicts[i] === minConflicts) {
            possibleRows.push(i);
        }
    }
    if (possibleRows.length === 1) {
        return possibleRows[0];
    }
    return possibleRows[getRandomInteger(0, possibleRows.length - 1)];
}
function getColumnOfQueenWIthMostConflicts() {
    var possiblePositions = [];
    var maxConflicts = -1;
    for (var i = 0; i < N; i++) {
        if (conflictsPerQueen[i] > maxConflicts) {
            maxConflicts = conflictsPerQueen[i];
            possiblePositions = [i];
        }
        else if (conflictsPerQueen[i] === maxConflicts) {
            possiblePositions.push(i);
        }
    }
    if (possiblePositions.length === 1) {
        return possiblePositions[0];
    }
    return possiblePositions[getRandomInteger(0, possiblePositions.length - 1)];
}
function getConflictsForQueen(queenColIndex) {
    var row = queenRowIndexByColumn[queenColIndex];
    return (queensInRow[row] +
        queensInDiagonal1[N - 1 + queenColIndex - row] +
        queensInDiagonal2[queenColIndex + row] -
        3);
}
function generateStartingQueens() {
    // place the queens on rows that alternate (e.g. 1, 3, 5,...,0, 2, 4,...)
    var row = 1;
    for (var col = 0; col < N; col++) {
        queenRowIndexByColumn[col] = row;
        row += 2;
        if (row >= N) {
            row = 0;
        }
    }
}
function generateStartingConflicts() {
    conflictsPerQueen = new Array(N).fill(0);
    for (var col = 0; col < N; col++) {
        var row = queenRowIndexByColumn[col];
        queensInDiagonal1[N - 1 + col - row]++;
        queensInDiagonal2[col + row]++;
    }
    for (var col = 0; col < N; col++) {
        conflictsPerQueen[col] = getConflictsForQueen(col);
    }
}
function solveNQueens() {
    var performedIteration = 0;
    generateStartingQueens();
    generateStartingConflicts();
    var totalConflicts = conflictsPerQueen.reduce(function (sum, value) { return sum + value; }, 0);
    while (performedIteration++ <= ITERATION_LIMIT) {
        if (totalConflicts === 0) {
            return queenRowIndexByColumn;
        }
        var col = getColumnOfQueenWIthMostConflicts();
        var newRow = getRowWithLeastConflicts(col);
        moveQueenToNewRow(col, newRow);
        totalConflicts = updateConflicts();
    }
    return null;
}
function main() {
    return __awaiter(this, arguments, void 0, function (printBoard) {
        var rl, ask, _a, startTime, result, endTime, duration, transposedResult, i, _i, transposedResult_1, colIndex, rowString, spacedRowString;
        if (printBoard === void 0) { printBoard = false; }
        return __generator(this, function (_b) {
            switch (_b.label) {
                case 0:
                    rl = readline.createInterface({
                        input: process.stdin,
                        output: process.stdout,
                    });
                    ask = function (question) {
                        return new Promise(function (resolve) { return rl.question(question, resolve); });
                    };
                    _a = Number;
                    return [4 /*yield*/, ask("Enter N: ")];
                case 1:
                    N = _a.apply(void 0, [(_b.sent())]);
                    rl.close();
                    queenRowIndexByColumn = new Array(N).fill(0);
                    queensInRow = new Array(N).fill(1);
                    queensInDiagonal1 = new Array(2 * N - 1).fill(0);
                    queensInDiagonal2 = new Array(2 * N - 1).fill(0);
                    startTime = perf_hooks_1.performance.now();
                    result = solveNQueens();
                    endTime = perf_hooks_1.performance.now();
                    duration = (endTime - startTime) / 1000;
                    if (N > 100) {
                        console.log("".concat(duration.toFixed(2)));
                        return [2 /*return*/];
                    }
                    if (result) {
                        if (!printBoard) {
                            console.log(result);
                        }
                        else {
                            transposedResult = new Array(N);
                            for (i = 0; i < N; i++) {
                                transposedResult[result[i]] = i;
                            }
                            for (_i = 0, transposedResult_1 = transposedResult; _i < transposedResult_1.length; _i++) {
                                colIndex = transposedResult_1[_i];
                                rowString = "_".repeat(N).split("");
                                rowString[colIndex] = "*";
                                spacedRowString = rowString.join(" ");
                                console.log(spacedRowString);
                            }
                        }
                    }
                    else {
                        console.log(-1);
                    }
                    return [2 /*return*/];
            }
        });
    });
}
main(true);
