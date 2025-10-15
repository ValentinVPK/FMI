import { DecisionTreeNode, DataPoint, ClassificationLabel } from "./types";
import { classify } from "./decisionTree";
import { getMostCommonLabel } from "./utils";

// Count occurrences of labels
function countLabels(data: DataPoint[]): Record<ClassificationLabel, number> {
  const counts: Record<ClassificationLabel, number> = {
    "no-recurrence-events": 0,
    "recurrence-events": 0,
  };
  data.forEach((point) => counts[point.label]++);
  return counts;
}

// Calculate classification accuracy
function calculateAccuracy(tree: DecisionTreeNode, data: DataPoint[]): number {
  let correct = 0;
  data.forEach((point) => {
    if (classify(tree, point) === point.label) correct++;
  });
  return correct / data.length;
}

// **Reduced Error Pruning**
export function pruneTreeByErrorEstimation(
  tree: DecisionTreeNode,
  validationData: DataPoint[]
): DecisionTreeNode {
  if (tree.isLeaf) return tree; // Leaf nodes cannot be pruned

  // Calculate initial accuracy before pruning
  const initialAccuracy = calculateAccuracy(tree, validationData);

  // Attempt to prune each child
  if (tree.children) {
    for (const [key, child] of Object.entries(tree.children)) {
      tree.children[key] = pruneTreeByErrorEstimation(child, validationData); // Recursive pruning
    }
  }

  // Evaluate accuracy if current node is replaced with a leaf
  const labelCounts = countLabels(validationData);
  const majorityLabel =
    labelCounts["no-recurrence-events"] >= labelCounts["recurrence-events"]
      ? "no-recurrence-events"
      : "recurrence-events";

  const prunedTree: DecisionTreeNode = { isLeaf: true, label: majorityLabel };
  const prunedAccuracy = calculateAccuracy(prunedTree, validationData);

  // Replace the current node with a leaf if pruning improves accuracy
  return prunedAccuracy >= initialAccuracy ? prunedTree : tree;
}

// Calculate Chi-Square statistic
function chiSquareTest(observed: number[], expected: number[]): number {
  return observed.reduce((sum, obs, i) => {
    const exp = expected[i];
    return sum + (obs - exp) ** 2 / exp;
  }, 0);
}

// Critical value lookup for Chi-Square test (95% confidence level)
const CHI_SQUARE_CRITICAL_VALUE = 3.84;

// **Chi-Square Pruning**
export function pruneTreeByChiSquare(
  tree: DecisionTreeNode,
  data: DataPoint[]
): DecisionTreeNode {
  if (tree.isLeaf) return tree; // Leaf nodes cannot be pruned

  // Count labels at the current node
  const labelCounts = countLabels(data);
  const total = data.length;

  // Evaluate statistical significance
  const expected: number[] = Object.values(labelCounts).map(
    (count) => (count / total) * total
  );
  const observed = Object.values(labelCounts);

  const chiSquare = chiSquareTest(observed, expected);

  // Prune if the split is not statistically significant
  if (chiSquare < CHI_SQUARE_CRITICAL_VALUE) {
    const majorityLabel =
      labelCounts["no-recurrence-events"] >= labelCounts["recurrence-events"]
        ? "no-recurrence-events"
        : "recurrence-events";

    return { isLeaf: true, label: majorityLabel };
  }

  // Otherwise, recursively prune children
  if (tree.children) {
    for (const [key, child] of Object.entries(tree.children)) {
      const subset = data.filter(
        (point) => point.features[tree.attributeIndex!] === key
      );
      tree.children[key] = pruneTreeByChiSquare(child, subset);
    }
  }

  return tree;
}

// Calculate error rate
function calculateErrorRate(tree: DecisionTreeNode, data: DataPoint[]): number {
  let errors = 0;
  data.forEach((point) => {
    if (classify(tree, point) !== point.label) errors++;
  });
  return errors / data.length;
}

// **Minimal Cost-Complexity Pruning**
export function pruneTreeByCostComplexity(
  tree: DecisionTreeNode,
  data: DataPoint[],
  alpha: number = 0.01 // Regularization parameter for pruning
): DecisionTreeNode {
  if (tree.isLeaf) return tree; // Leaf nodes cannot be pruned

  // Calculate errors before pruning
  const initialError = calculateErrorRate(tree, data);

  // Evaluate cost-complexity tradeoff for subtree
  let subtreeError = 0;
  let leafCount = 0;

  if (tree.children) {
    for (const child of Object.values(tree.children)) {
      subtreeError += calculateErrorRate(child, data);
      if (child.isLeaf) leafCount++;
    }
  }

  const complexityPenalty = alpha * leafCount;
  const totalCost = subtreeError + complexityPenalty;

  // Prune if the cost of keeping the subtree is higher
  if (totalCost >= initialError) {
    const majorityLabel = getMostCommonLabel(data);
    return { isLeaf: true, label: majorityLabel };
  }

  // Otherwise, recursively prune children
  if (tree.children) {
    for (const [key, child] of Object.entries(tree.children)) {
      const subset = data.filter(
        (point) => point.features[tree.attributeIndex!] === key
      );
      tree.children[key] = pruneTreeByCostComplexity(child, subset, alpha);
    }
  }

  return tree;
}
