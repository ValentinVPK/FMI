export type ClassificationLabel = "no-recurrence-events" | "recurrence-events";

export interface DataPoint {
  features: string[]; // All feature values (categorical strings)
  label: ClassificationLabel; // The class label
}

export interface ProcessedData {
  data: DataPoint[]; // Array of data points
  featureCounts: Record<number, Record<string, number>>; // Frequency counts for missing value handling
}

// Represents a node in the decision tree
export interface DecisionTreeNode {
  attributeIndex?: number; // Attribute index used for splitting
  label?: ClassificationLabel; // Leaf node label
  children?: Record<string, DecisionTreeNode>; // Subtrees based on attribute values
  isLeaf: boolean; // Indicates if the node is a leaf
}
