import * as readline from "readline";
import * as fs from "fs";

const X = "X";
const O = "0";
const BOARD_SIZE = 3;
const EMPTY_CELL = "_";

let steps = 0;
let playerSymbol: string;
let computerSymbol: string;

let board: string[][] = Array.from({ length: BOARD_SIZE }, () =>
  Array(BOARD_SIZE).fill(EMPTY_CELL)
);

function displayBoard(): void {
  for (let i = 0; i < BOARD_SIZE; ++i) {
    console.log(board[i].join(" "));
  }
}

function isGameOver(): boolean {
  // Checking rows and cols
  for (let i = 0; i < BOARD_SIZE; ++i) {
    if (
      board[i][0] !== EMPTY_CELL &&
      board[i][0] === board[i][1] &&
      board[i][0] === board[i][2]
    ) {
      return true;
    }

    if (
      board[0][i] !== EMPTY_CELL &&
      board[0][i] === board[1][i] &&
      board[0][i] === board[2][i]
    ) {
      return true;
    }
  }

  // Checking main diagonal
  if (
    board[0][0] !== EMPTY_CELL &&
    board[0][0] === board[1][1] &&
    board[0][0] === board[2][2]
  ) {
    return true;
  }

  // Checking top-right to bottom-left diagonal
  if (
    board[0][2] !== EMPTY_CELL &&
    board[0][2] === board[1][1] &&
    board[0][2] === board[2][0]
  ) {
    return true;
  }

  for (let i = 0; i < BOARD_SIZE; ++i) {
    for (let j = 0; j < BOARD_SIZE; ++j) {
      if (board[i][j] === EMPTY_CELL) {
        return false;
      }
    }
  }

  // Draw
  return true;
}

function calculateMinMaxScore(
  depth: number,
  alpha: number,
  beta: number,
  isMaximizer: boolean
): number {
  const score = evaluateBoardScore(depth);

  if (score !== 0 || isGameOver()) {
    return score;
  }

  if (isMaximizer) {
    let best = Number.MIN_SAFE_INTEGER;

    for (let i = 0; i < BOARD_SIZE; ++i) {
      for (let j = 0; j < BOARD_SIZE; ++j) {
        if (board[i][j] === EMPTY_CELL) {
          board[i][j] = computerSymbol;

          best = Math.max(
            best,
            calculateMinMaxScore(depth + 1, alpha, beta, false)
          );

          board[i][j] = EMPTY_CELL;

          alpha = Math.max(alpha, best);
          if (beta <= alpha) {
            break;
          }
        }
      }
    }
    return best;
  } else {
    let best = Number.MAX_SAFE_INTEGER;

    for (let i = 0; i < BOARD_SIZE; ++i) {
      for (let j = 0; j < BOARD_SIZE; ++j) {
        if (board[i][j] === EMPTY_CELL) {
          board[i][j] = playerSymbol;

          best = Math.min(
            best,
            calculateMinMaxScore(depth + 1, alpha, beta, true)
          );

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

function evaluateBoardScore(depth: number): number {
  for (let i = 0; i < BOARD_SIZE; ++i) {
    if (
      board[i][0] !== EMPTY_CELL &&
      board[i][0] === board[i][1] &&
      board[i][0] === board[i][2]
    ) {
      return board[i][0] === computerSymbol ? 10 - depth : depth - 10;
    }

    if (
      board[0][i] !== EMPTY_CELL &&
      board[0][i] === board[1][i] &&
      board[0][i] === board[2][i]
    ) {
      return board[0][i] === computerSymbol ? 10 - depth : depth - 10;
    }
  }

  if (
    board[0][0] !== EMPTY_CELL &&
    board[0][0] === board[1][1] &&
    board[0][0] === board[2][2]
  ) {
    return board[0][0] === computerSymbol ? 10 - depth : depth - 10;
  }

  if (
    board[0][2] !== EMPTY_CELL &&
    board[0][2] === board[1][1] &&
    board[0][2] === board[2][0]
  ) {
    return board[0][2] === computerSymbol ? 10 - depth : depth - 10;
  }

  return 0;
}

function determineBestMove(): void {
  let bestVal = Number.MIN_SAFE_INTEGER;
  let bestMoveRow = -1;
  let bestMoveCol = -1;
  let alpha = Number.MIN_SAFE_INTEGER;
  let beta = Number.MAX_SAFE_INTEGER;

  for (let i = 0; i < BOARD_SIZE; ++i) {
    for (let j = 0; j < BOARD_SIZE; ++j) {
      if (board[i][j] === EMPTY_CELL) {
        board[i][j] = computerSymbol;
        const moveVal = calculateMinMaxScore(0, alpha, beta, false);
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

async function main(isPlayerFirst = false) {
  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
  });

  const ask = (question: string): Promise<string> =>
    new Promise((resolve) => rl.question(question, resolve));

  let playerTurn = isPlayerFirst;

  playerSymbol = X;
  computerSymbol = O;

  if (!playerTurn) {
    computerSymbol = X;
    playerSymbol = O;
    determineBestMove();
    steps++;
    displayBoard();
  }

  while (!isGameOver()) {
    let validMove = false;
    let row = -1;
    let col = -1;

    while (!validMove) {
      const input = await ask("Enter your move (row and column): ");
      const parsedInput = input.split(" ").map((num) => parseInt(num, 10) - 1);

      if (parsedInput.length === 2) {
        [row, col] = parsedInput;
        validMove =
          row >= 0 &&
          col >= 0 &&
          row < BOARD_SIZE &&
          col < BOARD_SIZE &&
          board[row][col] === EMPTY_CELL;
      }

      if (!validMove) {
        console.log(
          "Invalid move. Please enter two numbers for an empty cell within the board's range."
        );
      }
    }

    board[row][col] = playerSymbol;
    steps++;

    if (isGameOver()) {
      break;
    }

    determineBestMove();
    steps++;
    displayBoard();
  }

  const result = evaluateBoardScore(steps);

  if (result > 0) {
    console.log("Computer wins!");
  } else if (result < 0) {
    console.log("Player wins!");
  } else {
    console.log("Tie!");
  }

  rl.close();
}

main(true);
