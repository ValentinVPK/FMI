export type FeatureValue = "y" | "n" | "?";

export interface FeatureVector {
  coordinates: FeatureValue[]; // Array of "y", "n", or "?"
}
