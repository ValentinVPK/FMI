import { ClassificationLabel, DataPoint } from "./types";

// Helper function to find the most common label
export function getMostCommonLabel(data: DataPoint[]): ClassificationLabel {
  const labelCounts: Record<ClassificationLabel, number> = {
    "no-recurrence-events": 0,
    "recurrence-events": 0,
  };
  data.forEach((point) => labelCounts[point.label]++);
  return labelCounts["no-recurrence-events"] >= labelCounts["recurrence-events"]
    ? "no-recurrence-events"
    : "recurrence-events";
}

// Helper function to shuffle data
export function shuffleData(data: DataPoint[]): DataPoint[] {
  return [...data].sort(() => Math.random() - 0.5);
}
