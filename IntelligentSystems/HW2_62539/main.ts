import * as readline from "readline";
import { performance } from "perf_hooks";

const ITERATION_LIMIT = 100000;
let N: number = 0;
let queenRowIndexByColumn: number[] = []; // Stores the row index of the queen in each column.
let queensInRow: number[] = []; // Tracks how many queens are in each row.
let queensInDiagonal1: number[] = []; // Tracks queens on diagonals sloping from top-left to bottom-right
let queensInDiagonal2: number[] = []; // Tracks queens on diagonals sloping from top-right to bottom-left
let conflictsPerQueen: number[] = []; // Stores the number of conflicts for each queen. The index of this array corresponds to the column of the queen.

function getRandomInteger(min: number, max: number) {
  return Math.floor(Math.random() * (max - min + 1)) + min;
}

function updateConflicts() {
  let totalConflicts = 0;
  for (let i = 0; i < N; i++) {
    conflictsPerQueen[i] = getConflictsForQueen(i);
    totalConflicts += conflictsPerQueen[i];
  }

  return totalConflicts;
}

function moveQueenToNewRow(col: number, newRow: number) {
  const oldRow = queenRowIndexByColumn[col];
  queensInRow[oldRow]--;
  queensInRow[newRow]++;
  queensInDiagonal1[N - 1 + col - oldRow]--;
  queensInDiagonal2[col + oldRow]--;
  queensInDiagonal1[N - 1 + col - newRow]++;
  queensInDiagonal2[col + newRow]++;
  queenRowIndexByColumn[col] = newRow;
}

function getRowWithLeastConflicts(col: number) {
  let potentialConflicts = new Array(N).fill(0);

  for (let i = 0; i < N; i++) {
    if (i === col) {
      continue;
    }

    const row = queenRowIndexByColumn[i];
    potentialConflicts[row]++;
    const diagonal1 = row + Math.abs(i - col);
    const diagonal2 = row - Math.abs(i - col);

    if (diagonal1 >= 0 && diagonal1 < N) {
      potentialConflicts[diagonal1]++;
    }

    if (diagonal2 >= 0 && diagonal2 < N) {
      potentialConflicts[diagonal2]++;
    }
  }

  let possibleRows: number[] = [];
  let minConflicts = N + 1;

  for (let i = 0; i < N; i++) {
    if (potentialConflicts[i] < minConflicts) {
      minConflicts = potentialConflicts[i];
      possibleRows = [i];
    } else if (potentialConflicts[i] === minConflicts) {
      possibleRows.push(i);
    }
  }

  if (possibleRows.length === 1) {
    return possibleRows[0];
  }

  return possibleRows[getRandomInteger(0, possibleRows.length - 1)];
}

function getColumnOfQueenWIthMostConflicts() {
  let possiblePositions: number[] = [];
  let maxConflicts = -1;
  for (let i = 0; i < N; i++) {
    if (conflictsPerQueen[i] > maxConflicts) {
      maxConflicts = conflictsPerQueen[i];
      possiblePositions = [i];
    } else if (conflictsPerQueen[i] === maxConflicts) {
      possiblePositions.push(i);
    }
  }

  if (possiblePositions.length === 1) {
    return possiblePositions[0];
  }

  return possiblePositions[getRandomInteger(0, possiblePositions.length - 1)];
}

function getConflictsForQueen(queenColIndex: number) {
  const row = queenRowIndexByColumn[queenColIndex];
  return (
    queensInRow[row] +
    queensInDiagonal1[N - 1 + queenColIndex - row] +
    queensInDiagonal2[queenColIndex + row] -
    3
  );
}

function generateStartingQueens() {
  // place the queens on rows that alternate (e.g. 1, 3, 5,...,0, 2, 4,...)
  let row = 1;

  for (let col = 0; col < N; col++) {
    queenRowIndexByColumn[col] = row;
    row += 2;

    if (row >= N) {
      row = 0;
    }
  }
}

function generateStartingConflicts() {
  conflictsPerQueen = new Array(N).fill(0);

  for (let col = 0; col < N; col++) {
    let row = queenRowIndexByColumn[col];
    queensInDiagonal1[N - 1 + col - row]++;
    queensInDiagonal2[col + row]++;
  }

  for (let col = 0; col < N; col++) {
    conflictsPerQueen[col] = getConflictsForQueen(col);
  }
}

function solveNQueens(): number[] | null {
  let performedIteration = 0;
  generateStartingQueens();
  generateStartingConflicts();

  let totalConflicts = conflictsPerQueen.reduce((sum, value) => sum + value, 0);

  while (performedIteration++ <= ITERATION_LIMIT) {
    if (totalConflicts === 0) {
      return queenRowIndexByColumn;
    }

    const col = getColumnOfQueenWIthMostConflicts();

    const newRow = getRowWithLeastConflicts(col);

    moveQueenToNewRow(col, newRow);
    totalConflicts = updateConflicts();
  }

  return null;
}

async function main(printBoard = false) {
  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
  });
  const ask = (question: string) =>
    new Promise((resolve) => rl.question(question, resolve));
  N = Number((await ask("Enter N: ")) as string);
  rl.close();

  queenRowIndexByColumn = new Array(N).fill(0);
  queensInRow = new Array(N).fill(1);
  queensInDiagonal1 = new Array(2 * N - 1).fill(0);
  queensInDiagonal2 = new Array(2 * N - 1).fill(0);

  const startTime = performance.now();
  const result = solveNQueens();
  const endTime = performance.now();
  const duration = (endTime - startTime) / 1000;

  if (N > 100) {
    console.log(`${duration.toFixed(2)}`);
    return;
  }

  if (result) {
    if (!printBoard) {
      console.log(result);
    } else {
      const transposedResult: number[] = new Array(N);
      for (let i = 0; i < N; i++) {
        transposedResult[result[i]] = i;
      }

      for (const colIndex of transposedResult) {
        let rowString = "_".repeat(N).split("");
        rowString[colIndex] = "*";
        const spacedRowString = rowString.join(" ");

        console.log(spacedRowString);
      }
    }
  } else {
    console.log(-1);
  }

  return;
}

main(true);
