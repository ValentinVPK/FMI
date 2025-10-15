import * as readline from "readline";
import * as fs from "fs";

import { FEATURE_COUNT } from "./constants";
import { FeatureValue, FeatureVector } from "./featureVector";
import {
  ClassificationLabel,
  classifyNaiveBayes,
  trainNaiveBayes,
} from "./naiveBayesClassifier";
import { createInterface } from "readline";

const featureVectorToLabelMap: Array<{
  featureVector: FeatureVector;
  label: ClassificationLabel;
}> = [];

/**
 * Reads the CSV file and handles "?" as an abstained value.
 */
export async function readCSVWithAbstained(pathToFile: string): Promise<void> {
  const fileStream = fs.createReadStream(pathToFile);
  const rl = createInterface({
    input: fileStream,
    crlfDelay: Infinity,
  });

  for await (const line of rl) {
    if (!line.trim()) continue;

    const segments = line.split(",").map((s) => s.trim());

    const features: FeatureValue[] = [];
    for (let i = 1; i < segments.length; i++) {
      const char = segments[i][0] as FeatureValue;
      features.push(char);
    }

    const featureVector: FeatureVector = { coordinates: features };
    const label = segments[0] as ClassificationLabel;

    featureVectorToLabelMap.push({ featureVector, label });
  }
}

// The "?" values are replaced probabilistically based on the observed frequency of "y" and "n" for each feature, using the probability of "y" to decide the replacement.
// This method preserves the natural distribution of values in the dataset, ensuring the model remains unbiased and generalizes well.

export async function readCSVWithReplacement(
  pathToFile: string
): Promise<void> {
  // Initialize counts to keep track of "y" and "n" occurrences for each feature
  const counts: Array<Record<"y" | "n", number>> = Array(FEATURE_COUNT)
    .fill(null)
    .map(() => ({ y: 0, n: 0 }));

  // Read the file line by line
  const fileStream = fs.createReadStream(pathToFile);
  const rl = createInterface({
    input: fileStream,
    crlfDelay: Infinity,
  });

  for await (const line of rl) {
    if (!line.trim()) continue;

    const segments = line.split(",").map((s) => s.trim());

    const features: FeatureValue[] = [];
    for (let i = 1; i < segments.length; i++) {
      const char = segments[i][0] as FeatureValue;
      features.push(char);

      if (char !== "?") {
        counts[i - 1][char as "y" | "n"]++;
      }
    }

    const featureVector: FeatureVector = { coordinates: features };
    const label = segments[0] as ClassificationLabel;

    featureVectorToLabelMap.push({ featureVector, label });
  }

  // Calculate probabilities for filling "?" values
  const probabilities = counts.map((count) => count.y / (count.y + count.n));

  // Fill "?" with "y" or "n" based on probabilities
  featureVectorToLabelMap.forEach(({ featureVector }) => {
    featureVector.coordinates = featureVector.coordinates.map(
      (value, index) => {
        if (value === "?") {
          const probability = probabilities[index];
          return Math.random() < probability ? "y" : "n";
        }
        return value;
      }
    );
  });
}

export async function crossValidation(): Promise<void> {
  featureVectorToLabelMap.forEach(({ featureVector }) => {
    console.log(featureVector.coordinates.join(", "));
  });
  // Shuffle the starting data
  const shuffledData = [...featureVectorToLabelMap];
  shuffledData.sort(() => Math.random() - 0.5);

  const partitionSize = Math.floor(shuffledData.length / 10);

  let validationDataStartingIndex = 0;
  let validationDataEndingIndex = partitionSize;

  let totalSuccesses = 0;
  let totalFails = 0;

  for (let i = 0; i < 10; i++) {
    let successes = 0;
    let fails = 0;

    // Split data into training and validation sets
    const trainData = [
      ...shuffledData.slice(0, validationDataStartingIndex),
      ...shuffledData.slice(validationDataEndingIndex),
    ];
    const validationData = shuffledData.slice(
      validationDataStartingIndex,
      validationDataEndingIndex
    );

    // Train the Naive Bayes classifier
    const classifierModel = trainNaiveBayes(trainData);

    // Validate the classifier on the validation set
    for (const { featureVector, label } of validationData) {
      const predictedLabel = classifyNaiveBayes(classifierModel, featureVector);
      if (predictedLabel === label) {
        successes++;
      } else {
        fails++;
      }
    }

    // Update total successes and failures
    totalSuccesses += successes;
    totalFails += fails;

    // Log results for the current fold
    console.log(
      `Accuracy Fold ${i + 1}: ${(
        (successes / (successes + fails)) *
        100
      ).toFixed(2)}% success, ${successes} : ${fails}`
    );

    // Update validation data indices
    validationDataStartingIndex = validationDataEndingIndex;
    validationDataEndingIndex += partitionSize;
  }

  // Log total results
  console.log(
    `Total: ${((totalSuccesses / (totalSuccesses + totalFails)) * 100).toFixed(
      2
    )}% success, ${totalSuccesses} : ${totalFails}`
  );
}

/**
 * Splits a labeled dataset into training and testing sets, ensuring that the class distributions
 * in the subsets are similar to the original dataset (stratified splitting).
 *
 * @param trainRatio - The proportion of the dataset allocated to the training set.
 *                     The remaining data is assigned to the test set.
 *                     Default is 0.8 (80% training, 20% testing).
 *
 * @returns An object containing:
 *          - `trainData`: The training set as an array of feature vectors and their corresponding labels.
 *          - `testData`: The testing set as an array of feature vectors and their corresponding labels.
 *
 * @example
 * const { trainData, testData } = stratifiedSplit(0.8);
 *
 * Input Assumptions:
 * - The data is globally stored in `featureVectorToLabelMap`.
 * - Each entry in `featureVectorToLabelMap` is an object of the form:
 *   { featureVector: FeatureVector, label: ClassificationLabel }.
 */
export function stratifiedSplit(trainRatio: number = 0.8): {
  trainData: Array<{
    featureVector: FeatureVector;
    label: ClassificationLabel;
  }>;
  testData: Array<{ featureVector: FeatureVector; label: ClassificationLabel }>;
} {
  // Group data by label
  const groupedData: Record<
    ClassificationLabel,
    Array<{ featureVector: FeatureVector; label: ClassificationLabel }>
  > = {
    democrat: [],
    republican: [],
  };

  featureVectorToLabelMap.forEach((item) => groupedData[item.label].push(item));

  const trainData: Array<{
    featureVector: FeatureVector;
    label: ClassificationLabel;
  }> = [];
  const testData: Array<{
    featureVector: FeatureVector;
    label: ClassificationLabel;
  }> = [];

  // Perform stratified split for each class
  for (const label of Object.keys(groupedData) as ClassificationLabel[]) {
    const classData = groupedData[label];
    const splitIndex = Math.floor(classData.length * trainRatio);

    // Shuffle class data before splitting
    const shuffledClassData = [...classData].sort(() => Math.random() - 0.5);

    // Assign training and testing data
    trainData.push(...shuffledClassData.slice(0, splitIndex));
    testData.push(...shuffledClassData.slice(splitIndex));
  }

  return { trainData, testData };
}

/**
 * Orchestrates the training and evaluation of a Naive Bayes classifier.
 *
 * This function performs the following:
 * 1. **Stratified Train-Test Split**: Divides the dataset into training and testing subsets
 *    while maintaining the same proportion of classes in both subsets.
 * 2. **Train the Model**: Trains a Naive Bayes classifier using the training subset.
 * 3. **Train Set Evaluation**: Evaluates the trained model on the training subset to ensure it has learned effectively.
 * 4. **10-Fold Cross-Validation**: Conducts cross-validation on the training subset to estimate the generalization performance.
 *    - Logs the accuracy for each fold.
 *    - Computes and logs the average accuracy and standard deviation across all folds.
 * 5. **Test Set Evaluation**: Validates the model on the unseen test subset to assess its final real-world performance.
 *
 * @returns {Promise<void>} Outputs evaluation metrics to the console.
 */
export async function trainAndTest(): Promise<void> {
  // Perform stratified split
  const { trainData, testData } = stratifiedSplit();

  // Train the Naive Bayes model on the training data
  const model = trainNaiveBayes(trainData);

  // Evaluate the model on the training data
  let trainSuccesses = 0;
  let trainFails = 0;
  for (const { featureVector, label } of trainData) {
    const predictedLabel = classifyNaiveBayes(model, featureVector);
    if (predictedLabel === label) {
      trainSuccesses++;
    } else {
      trainFails++;
    }
  }

  // Log Train Set Accuracy
  console.log(
    `1. Train Set Accuracy:\n    Accuracy: ${(
      (trainSuccesses / (trainSuccesses + trainFails)) *
      100
    ).toFixed(2)}%`
  );

  console.log("10-Fold Cross-Validation Results: ");

  // Perform 10-fold cross-validation
  const shuffledData = [...trainData];
  shuffledData.sort(() => Math.random() - 0.5);
  const partitionSize = Math.floor(shuffledData.length / 10);

  const foldAccuracies: number[] = [];
  for (let i = 0; i < 10; i++) {
    const validationData = shuffledData.slice(
      i * partitionSize,
      (i + 1) * partitionSize
    );
    const trainingData = [
      ...shuffledData.slice(0, i * partitionSize),
      ...shuffledData.slice((i + 1) * partitionSize),
    ];

    const foldModel = trainNaiveBayes(trainingData);

    let foldSuccesses = 0;
    let foldFails = 0;
    for (const { featureVector, label } of validationData) {
      const predictedLabel = classifyNaiveBayes(foldModel, featureVector);
      if (predictedLabel === label) {
        foldSuccesses++;
      } else {
        foldFails++;
      }
    }

    const foldAccuracy = (foldSuccesses / (foldSuccesses + foldFails)) * 100;
    foldAccuracies.push(foldAccuracy);

    console.log(
      `    Accuracy Fold ${i + 1}: ${foldAccuracy.toFixed(
        2
      )}% success, ${foldSuccesses} : ${foldFails}`
    );
  }

  // Calculate average accuracy and standard deviation
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

  // Evaluate the model on the test data
  let testSuccesses = 0;
  let testFails = 0;
  for (const { featureVector, label } of testData) {
    const predictedLabel = classifyNaiveBayes(model, featureVector);
    if (predictedLabel === label) {
      testSuccesses++;
    } else {
      testFails++;
    }
  }

  // Log Test Set Accuracy
  console.log(
    `2. Test Set Accuracy:\n    Accuracy: ${(
      (testSuccesses / (testSuccesses + testFails)) *
      100
    ).toFixed(2)}%`
  );
}

async function main(filePath: string) {
  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
  });

  const handleAbstained = await new Promise<boolean>((resolve) => {
    rl.question(
      "Enter 0 to handle '?' as abstained or 1 to replace it with 'y'/'n': ",
      (answer) => {
        rl.close();
        resolve(answer.trim() === "0");
      }
    );
  });

  if (handleAbstained) {
    await readCSVWithAbstained(filePath);
  } else {
    await readCSVWithReplacement(filePath);
  }

  await trainAndTest();
}

main("./house-votes-84.data");
