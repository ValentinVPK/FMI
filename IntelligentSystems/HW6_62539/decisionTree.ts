import { ClassificationLabel, DataPoint, DecisionTreeNode } from "./types";
import { getMostCommonLabel } from "./utils";

// Calculate entropy of a dataset
export function calculateEntropy(data: DataPoint[]): number {
  const labelCounts: Record<ClassificationLabel, number> = {
    "no-recurrence-events": 0,
    "recurrence-events": 0,
  };

  // Count occurrences of each label
  data.forEach((point) => labelCounts[point.label]++);

  // Calculate entropy
  return Object.values(labelCounts).reduce((entropy, count) => {
    if (count === 0) return entropy; // Skip 0 counts
    const probability = count / data.length;
    return entropy - probability * Math.log2(probability);
  }, 0);
}

// Calculate information gain for a specific attribute
export function calculateInformationGain(
  data: DataPoint[],
  attributeIndex: number
): number {
  // Calculate parent entropy
  const parentEntropy = calculateEntropy(data);

  // Group data by attribute value
  const subsets: Record<string, DataPoint[]> = {};
  data.forEach((point) => {
    const value = point.features[attributeIndex];
    if (!subsets[value]) subsets[value] = [];
    subsets[value].push(point);
  });

  // Calculate weighted entropy after split
  const weightedEntropy = Object.values(subsets).reduce(
    (totalEntropy, subset) => {
      const subsetProbability = subset.length / data.length;
      return totalEntropy + subsetProbability * calculateEntropy(subset);
    },
    0
  );

  // Information Gain = Parent Entropy - Weighted Entropy
  return parentEntropy - weightedEntropy;
}

// Classify a data point using the decision tree
export function classify(
  tree: DecisionTreeNode,
  dataPoint: DataPoint
): ClassificationLabel {
  if (tree.isLeaf) {
    return tree.label!;
  }

  const value = dataPoint.features[tree.attributeIndex!];
  const child = tree.children?.[value];

  if (!child) {
    // Default to most common label if path does not exist
    return "no-recurrence-events";
  }
  return classify(child, dataPoint);
}

export function buildDecisionTree(
  data: DataPoint[],
  attributes: number[],
  depth: number = 0,
  options?: {
    prePruningMethods?: string[]; // Array of active pre-pruning methods (e.g., ["N", "K"])
    maxDepth?: number; // Max depth (N)
    minSamples?: number; // Min samples (K)
    minGain?: number; // Min gain (G)
  }
): DecisionTreeNode {
  const {
    prePruningMethods = [], // Default: No pre-pruning
    maxDepth = 5,
    minSamples = 3,
    minGain = 0.01,
  } = options || {};

  // **Base cases for stopping**

  // 1. Empty dataset
  if (data.length === 0) {
    return { isLeaf: true, label: "no-recurrence-events" };
  }

  // 2. Pure node - all examples have the same label
  const uniqueLabels = new Set(data.map((point) => point.label));
  if (uniqueLabels.size === 1) {
    return { isLeaf: true, label: data[0].label };
  }

  // **Pre-Pruning Methods (Check Individually)**

  // Max Depth (N)
  if (prePruningMethods.includes("N") && depth >= maxDepth) {
    return { isLeaf: true, label: getMostCommonLabel(data) };
  }

  // Min Samples (K)
  if (prePruningMethods.includes("K") && data.length < minSamples) {
    return { isLeaf: true, label: getMostCommonLabel(data) };
  }

  // Min Gain (G)
  let bestAttribute = -1;
  let bestGain = 0;
  attributes.forEach((attrIndex) => {
    const gain = calculateInformationGain(data, attrIndex);
    if (gain > bestGain) {
      bestGain = gain;
      bestAttribute = attrIndex;
    }
  });
  if (prePruningMethods.includes("G") && bestGain < minGain) {
    return { isLeaf: true, label: getMostCommonLabel(data) };
  }

  // **Partition Data by Best Attribute**
  const subsets: Record<string, DataPoint[]> = {};
  data.forEach((point) => {
    const value = point.features[bestAttribute];
    if (!subsets[value]) subsets[value] = [];
    subsets[value].push(point);
  });

  // **Build Child Nodes Recursively**
  const children: Record<string, DecisionTreeNode> = {};
  Object.entries(subsets).forEach(([value, subset]) => {
    children[value] = buildDecisionTree(
      subset,
      attributes.filter((attr) => attr !== bestAttribute),
      depth + 1,
      options // Pass options
    );
  });

  // **Return Node with Split Information**
  return {
    isLeaf: false,
    attributeIndex: bestAttribute,
    children,
  };
}
