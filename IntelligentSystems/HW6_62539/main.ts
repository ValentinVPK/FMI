import * as readline from "readline";
import * as fs from "fs";

import { createInterface } from "readline";
import {
  ClassificationLabel,
  DataPoint,
  DecisionTreeNode,
  ProcessedData,
} from "./types";
import { buildDecisionTree, classify } from "./decisionTree";
import { shuffleData } from "./utils";
import {
  pruneTreeByChiSquare,
  pruneTreeByCostComplexity,
  pruneTreeByErrorEstimation,
} from "./postPruning";

const filePath = "./breast-cancer.data";

// Function to parse CSV data
export async function parseCSV(filePath: string): Promise<string[][]> {
  const data: string[][] = [];
  const fileStream = fs.createReadStream(filePath);
  const rl = readline.createInterface({
    input: fileStream,
    crlfDelay: Infinity,
  });

  for await (const line of rl) {
    if (line.trim()) {
      data.push(line.split(",").map((value) => value.trim())); // Trim whitespace
    }
  }

  return data;
}

// Replace missing values in data
export function preprocessData(rawData: string[][]): ProcessedData {
  const featureCounts: Record<number, Record<string, number>> = {}; // Track counts for each feature value
  const data: DataPoint[] = [];

  rawData.forEach((row) => {
    const label = row[0] as ClassificationLabel; // First column is the label
    const features = row.slice(1); // Remaining columns are features

    // Update feature frequency counts
    features.forEach((value, index) => {
      if (!featureCounts[index]) {
        featureCounts[index] = {};
      }
      if (value !== "?") {
        featureCounts[index][value] = (featureCounts[index][value] || 0) + 1;
      }
    });

    // Store data point
    data.push({ features, label });
  });

  // Replace missing values with the most frequent value in each column
  const processedData = data.map((point) => {
    const newFeatures = point.features.map((value, index) => {
      if (value === "?") {
        const mostFrequent = Object.entries(featureCounts[index]).reduce(
          (a, b) => (a[1] > b[1] ? a : b)
        )[0]; // Find most frequent value
        return mostFrequent;
      }
      return value; // Keep existing value
    });
    return { ...point, features: newFeatures };
  });

  return { data: processedData, featureCounts };
}

// Perform stratified split
export function stratifiedSplit(
  data: DataPoint[],
  trainRatio: number = 0.8
): { trainData: DataPoint[]; testData: DataPoint[] } {
  // Group data by label
  const groupedData: Record<ClassificationLabel, DataPoint[]> = {
    "no-recurrence-events": [],
    "recurrence-events": [],
  };

  data.forEach((point) => groupedData[point.label].push(point));

  const trainData: DataPoint[] = [];
  const testData: DataPoint[] = [];

  // Split each group maintaining proportions
  for (const label in groupedData) {
    const classData = groupedData[label as ClassificationLabel];
    const splitIndex = Math.floor(classData.length * trainRatio);

    // Shuffle data before splitting
    const shuffledData = [...classData].sort(() => Math.random() - 0.5);

    trainData.push(...shuffledData.slice(0, splitIndex));
    testData.push(...shuffledData.slice(splitIndex));
  }

  return { trainData, testData };
}

export function crossValidation(
  data: DataPoint[],
  attributes: number[],
  pruningMode: number,
  options?: {
    prePruningMethods?: string[];
    maxDepth?: number;
    minSamples?: number;
    minGain?: number;
    postPruningMethod?: string; // "E", "X", "C" (Post-pruning methods)
  }
): void {
  console.log("\n10-Fold Cross-Validation Results:");

  // Shuffle the data
  const shuffledData = [...data].sort(() => Math.random() - 0.5);
  const foldSize = Math.floor(data.length / 10);

  const foldAccuracies: number[] = [];

  // Perform 10-fold cross-validation
  for (let i = 0; i < 10; i++) {
    // Create training and validation sets for the fold
    const validationSet = shuffledData.slice(i * foldSize, (i + 1) * foldSize);
    const trainingSet = [
      ...shuffledData.slice(0, i * foldSize),
      ...shuffledData.slice((i + 1) * foldSize),
    ];

    let tree: DecisionTreeNode;

    // **Step 1: Handle Pre-Pruning Methods**
    if (pruningMode === 0 || pruningMode === 2) {
      // Pre-pruning enabled
      tree = buildDecisionTree(trainingSet, attributes, 0, options);
    } else {
      // No pre-pruning
      tree = buildDecisionTree(trainingSet, attributes);
    }

    // **Step 2: Apply Post-Pruning Methods (Dynamic Handling)**
    if (pruningMode === 1 || pruningMode === 2) {
      switch (options?.postPruningMethod) {
        case "E": // Error Estimation (Reduced Error Pruning)
          tree = pruneTreeByErrorEstimation(tree, validationSet); // Pass only required parameters
          break;

        case "X": // Chi-Square Test
          tree = pruneTreeByChiSquare(tree, trainingSet); // Correctly pass training set only
          break;

        case "C": // Minimal Cost-Complexity Pruning
          tree = pruneTreeByCostComplexity(tree, trainingSet, 0.01); // Pass alpha = 0.01 dynamically
          break;

        default:
          console.warn(
            "No valid post-pruning method specified. Skipping post-pruning."
          );
          break;
      }
    }

    // **Step 3: Evaluate Accuracy for the Fold**
    let correct = 0;
    validationSet.forEach((point) => {
      const prediction = classify(tree, point);
      if (prediction === point.label) correct++;
    });

    const foldAccuracy = (correct / validationSet.length) * 100;
    foldAccuracies.push(foldAccuracy);

    // Log accuracy for each fold
    console.log(
      `    Accuracy Fold ${i + 1}: ${foldAccuracy.toFixed(
        2
      )}% success, ${correct} / ${validationSet.length}`
    );
  }

  // **Step 4: Calculate Average Accuracy and Standard Deviation**
  const averageAccuracy =
    foldAccuracies.reduce((sum, acc) => sum + acc, 0) / foldAccuracies.length;
  const variance =
    foldAccuracies.reduce(
      (sum, acc) => sum + Math.pow(acc - averageAccuracy, 2),
      0
    ) / foldAccuracies.length;
  const stdDeviation = Math.sqrt(variance);

  console.log(`
    Average Accuracy: ${averageAccuracy.toFixed(2)}%
    Standard Deviation: ${stdDeviation.toFixed(2)}%
  `);
}

// **MAIN FUNCTION**
async function main() {
  // --- 1. Read and Parse Command-Line Arguments ---
  const args = process.argv.slice(2);

  // Validate input arguments
  if (args.length < 1 || args.length > 3) {
    console.error(
      "Usage: node main.js <pruningMode> [prePruningMethod] [postPruningMethod]"
    );
    console.error("Pruning Mode: 0 (Pre-pruning), 1 (Post-pruning), 2 (Both)");
    process.exit(1);
  }

  // Extract user input
  const pruningMode = parseInt(args[0]); // 0, 1, or 2
  const prePruningMethod = args[1]; // Optional for pre-pruning
  const postPruningMethod = args[2]; // Optional for post-pruning

  // Validate pruning mode
  if (![0, 1, 2].includes(pruningMode)) {
    console.error("Invalid pruning mode. Allowed values: 0, 1, or 2.");
    process.exit(1);
  }

  // --- 2. Load and Preprocess Data ---
  console.log("Loading and preprocessing data...");
  const rawData = await parseCSV(filePath);
  const { data } = preprocessData(rawData);

  // --- 3. Stratified Train-Test Split ---
  const { trainData, testData } = stratifiedSplit(data);
  console.log(`Training examples: ${trainData.length}`);
  console.log(`Testing examples: ${testData.length}`);

  // --- 4. Evaluate Model on Train Set (WITHOUT PRUNING) ---
  console.log("Building Decision Tree (Without Pruning)...");

  const attributes = Array.from(Array(trainData[0].features.length).keys());

  // **Pass pruning options dynamically** based on user input
  const options = {
    prePruningMethods:
      pruningMode === 0 || pruningMode === 2
        ? prePruningMethod
          ? [prePruningMethod] // Single pre-pruning method
          : ["N", "K", "G"] // Apply all by default
        : [],
    postPruningMethod:
      pruningMode === 1 || pruningMode === 2 ? postPruningMethod : undefined, // Apply specific post-pruning method
  };

  const tree: DecisionTreeNode = buildDecisionTree(trainData, attributes, 0, {
    prePruningMethods: options.prePruningMethods,
  });

  // --- 5. Evaluate Model on Train Set ---
  let correct = 0;
  trainData.forEach((point) => {
    const prediction = classify(tree, point);
    if (prediction === point.label) correct++;
  });

  const trainAccuracy = (correct / trainData.length) * 100;
  console.log(
    `\n1. Train Set Accuracy:\n    Accuracy: ${trainAccuracy.toFixed(2)}%`
  );

  // --- 6. Cross-Validation with Dynamic Pruning ---
  console.log("\n10-Fold Cross-Validation Results:");
  const { averageAccuracy, stdDeviation } = crossValidation(
    trainData,
    attributes,
    options // Pass user-defined pruning options dynamically
  );

  console.log(`
    Average Accuracy: ${averageAccuracy.toFixed(2)}%
    Standard Deviation: ${stdDeviation.toFixed(2)}%
  `);

  // --- 7. Evaluate Model on Test Set ---
  correct = 0;
  testData.forEach((point) => {
    const prediction = classify(tree, point);
    if (prediction === point.label) correct++;
  });

  const testAccuracy = (correct / testData.length) * 100;
  console.log(
    `\n2. Test Set Accuracy:\n    Accuracy: ${testAccuracy.toFixed(2)}%`
  );
}

main();
