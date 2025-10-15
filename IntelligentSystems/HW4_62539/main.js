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
var X = "X";
var O = "0";
var BOARD_SIZE = 3;
var EMPTY_CELL = "_";
var steps = 0;
var playerSymbol;
var computerSymbol;
var board = Array.from({ length: BOARD_SIZE }, function () {
    return Array(BOARD_SIZE).fill(EMPTY_CELL);
});
function displayBoard() {
    for (var i = 0; i < BOARD_SIZE; ++i) {
        console.log(board[i].join(" "));
    }
}
function isGameOver() {
    // Checking rows and cols
    for (var i = 0; i < BOARD_SIZE; ++i) {
        if (board[i][0] !== EMPTY_CELL &&
            board[i][0] === board[i][1] &&
            board[i][0] === board[i][2]) {
            return true;
        }
        if (board[0][i] !== EMPTY_CELL &&
            board[0][i] === board[1][i] &&
            board[0][i] === board[2][i]) {
            return true;
        }
    }
    // Checking main diagonal
    if (board[0][0] !== EMPTY_CELL &&
        board[0][0] === board[1][1] &&
        board[0][0] === board[2][2]) {
        return true;
    }
    // Checking top-right to bottom-left diagonal
    if (board[0][2] !== EMPTY_CELL &&
        board[0][2] === board[1][1] &&
        board[0][2] === board[2][0]) {
        return true;
    }
    for (var i = 0; i < BOARD_SIZE; ++i) {
        for (var j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] === EMPTY_CELL) {
                return false;
            }
        }
    }
    // Draw
    return true;
}
function calculateMinMaxScore(depth, alpha, beta, isMaximizer) {
    var score = evaluateBoardScore(depth);
    if (score !== 0 || isGameOver()) {
        return score;
    }
    if (isMaximizer) {
        var best = Number.MIN_SAFE_INTEGER;
        for (var i = 0; i < BOARD_SIZE; ++i) {
            for (var j = 0; j < BOARD_SIZE; ++j) {
                if (board[i][j] === EMPTY_CELL) {
                    board[i][j] = computerSymbol;
                    best = Math.max(best, calculateMinMaxScore(depth + 1, alpha, beta, false));
                    board[i][j] = EMPTY_CELL;
                    alpha = Math.max(alpha, best);
                    if (beta <= alpha) {
                        break;
                    }
                }
            }
        }
        return best;
    }
    else {
        var best = Number.MAX_SAFE_INTEGER;
        for (var i = 0; i < BOARD_SIZE; ++i) {
            for (var j = 0; j < BOARD_SIZE; ++j) {
                if (board[i][j] === EMPTY_CELL) {
                    board[i][j] = playerSymbol;
                    best = Math.min(best, calculateMinMaxScore(depth + 1, alpha, beta, true));
                    board[i][j] = EMPTY_CELL;
                    beta = Math.min(beta, best);
                    if (beta <= alpha) {
                        break;
                    }
                }
            }
        }
        return best;
    }
}
function evaluateBoardScore(depth) {
    for (var i = 0; i < BOARD_SIZE; ++i) {
        if (board[i][0] !== EMPTY_CELL &&
            board[i][0] === board[i][1] &&
            board[i][0] === board[i][2]) {
            return board[i][0] === computerSymbol ? 10 - depth : depth - 10;
        }
        if (board[0][i] !== EMPTY_CELL &&
            board[0][i] === board[1][i] &&
            board[0][i] === board[2][i]) {
            return board[0][i] === computerSymbol ? 10 - depth : depth - 10;
        }
    }
    if (board[0][0] !== EMPTY_CELL &&
        board[0][0] === board[1][1] &&
        board[0][0] === board[2][2]) {
        return board[0][0] === computerSymbol ? 10 - depth : depth - 10;
    }
    if (board[0][2] !== EMPTY_CELL &&
        board[0][2] === board[1][1] &&
        board[0][2] === board[2][0]) {
        return board[0][2] === computerSymbol ? 10 - depth : depth - 10;
    }
    return 0;
}
function determineBestMove() {
    var bestVal = Number.MIN_SAFE_INTEGER;
    var bestMoveRow = -1;
    var bestMoveCol = -1;
    var alpha = Number.MIN_SAFE_INTEGER;
    var beta = Number.MAX_SAFE_INTEGER;
    for (var i = 0; i < BOARD_SIZE; ++i) {
        for (var j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] === EMPTY_CELL) {
                board[i][j] = computerSymbol;
                var moveVal = calculateMinMaxScore(0, alpha, beta, false);
                board[i][j] = EMPTY_CELL;
                if (moveVal > bestVal) {
                    bestVal = moveVal;
                    bestMoveRow = i;
                    bestMoveCol = j;
                }
            }
        }
    }
    if (bestMoveRow !== -1 && bestMoveCol !== -1) {
        board[bestMoveRow][bestMoveCol] = computerSymbol;
    }
}
function main() {
    return __awaiter(this, arguments, void 0, function (isPlayerFirst) {
        var rl, ask, playerTurn, validMove, row, col, input, parsedInput, result;
        if (isPlayerFirst === void 0) { isPlayerFirst = false; }
        return __generator(this, function (_a) {
            switch (_a.label) {
                case 0:
                    rl = readline.createInterface({
                        input: process.stdin,
                        output: process.stdout,
                    });
                    ask = function (question) {
                        return new Promise(function (resolve) { return rl.question(question, resolve); });
                    };
                    playerTurn = isPlayerFirst;
                    playerSymbol = X;
                    computerSymbol = O;
                    if (!playerTurn) {
                        computerSymbol = X;
                        playerSymbol = O;
                        determineBestMove();
                        steps++;
                        displayBoard();
                    }
                    _a.label = 1;
                case 1:
                    if (!!isGameOver()) return [3 /*break*/, 5];
                    validMove = false;
                    row = -1;
                    col = -1;
                    _a.label = 2;
                case 2:
                    if (!!validMove) return [3 /*break*/, 4];
                    return [4 /*yield*/, ask("Enter your move (row and column): ")];
                case 3:
                    input = _a.sent();
                    parsedInput = input.split(" ").map(function (num) { return parseInt(num, 10) - 1; });
                    if (parsedInput.length === 2) {
                        row = parsedInput[0], col = parsedInput[1];
                        validMove =
                            row >= 0 &&
                                col >= 0 &&
                                row < BOARD_SIZE &&
                                col < BOARD_SIZE &&
                                board[row][col] === EMPTY_CELL;
                    }
                    if (!validMove) {
                        console.log("Invalid move. Please enter two numbers for an empty cell within the board's range.");
                    }
                    return [3 /*break*/, 2];
                case 4:
                    board[row][col] = playerSymbol;
                    steps++;
                    if (isGameOver()) {
                        return [3 /*break*/, 5];
                    }
                    determineBestMove();
                    steps++;
                    displayBoard();
                    return [3 /*break*/, 1];
                case 5:
                    result = evaluateBoardScore(steps);
                    if (result > 0) {
                        console.log("Computer wins!");
                    }
                    else if (result < 0) {
                        console.log("Player wins!");
                    }
                    else {
                        console.log("Tie!");
                    }
                    rl.close();
                    return [2 /*return*/];
            }
        });
    });
}
main(true);
