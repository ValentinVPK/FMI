import { FeatureValue, FeatureVector } from "./featureVector";

// Classification labels (specific to the dataset)
export type ClassificationLabel = "democrat" | "republican";

// Tracks label counts for the dataset
export type LabelCounts = Record<ClassificationLabel, number>;

// Tracks feature counts for each label and attribute
export type AttributeValueCounts = Record<
  ClassificationLabel,
  Record<number, Record<FeatureValue, number>>
>;

// Naive Bayes model structure
export interface NaiveBayesModel {
  labelCounts: LabelCounts; // Counts of each label
  attributeValueCounts: AttributeValueCounts; // Counts of feature values grouped by label and attribute
  instanceCount: number; // Total number of examples
}

export function trainNaiveBayes(
  data: Array<{ featureVector: FeatureVector; label: ClassificationLabel }>
): NaiveBayesModel {
  const labelCounts: LabelCounts = {
    democrat: 0,
    republican: 0,
  }; // Tracks count of examples per label
  const attributeValueCounts: AttributeValueCounts = {
    democrat: {},
    republican: {},
  }; // Tracks counts of feature values per label and attribute
  const instanceCount = data.length; // Total number of examples

  // Process each training example
  for (const { featureVector, label } of data) {
    // Update label counts
    if (!labelCounts[label]) {
      labelCounts[label] = 0;
    }
    labelCounts[label]++;

    // Update attribute value counts
    if (!attributeValueCounts[label]) {
      attributeValueCounts[label] = {};
    }

    featureVector.coordinates.forEach((value, index) => {
      // Initialize counts for this attribute index if not already present
      if (!attributeValueCounts[label][index]) {
        attributeValueCounts[label][index] = {
          y: 0,
          n: 0,
          "?": 0,
        };
      }
      // Initialize counts for this specific feature value if not already present
      if (!attributeValueCounts[label][index][value]) {
        attributeValueCounts[label][index][value] = 0;
      }
      // Increment count for this feature value
      attributeValueCounts[label][index][value]++;
    });
  }

  return { labelCounts, attributeValueCounts, instanceCount };

  // Example return data:

  // labelCounts = { democrat: 5, republican: 3 };

  // attributeValueCounts = {
  //   democrat: {
  //     0: { y: 10, n: 5, "?": 2 }, // Feature 0 for democrats
  //     1: { y: 7, n: 8, "?": 3 },  // Feature 1 for democrats
  //   },
  //   republican: {
  //     0: { y: 3, n: 7, "?": 5 },  // Feature 0 for republicans
  //   },
  // };
}

export function classifyNaiveBayes(
  model: NaiveBayesModel,
  query: FeatureVector
): ClassificationLabel {
  const { labelCounts, attributeValueCounts, instanceCount } = model;

  // To store the calculated probabilities for each label
  const probabilities: Array<{
    probability: number;
    label: ClassificationLabel;
  }> = [];

  // Loop through each label (Democrat, Republican)
  for (const [label, labelCount] of Object.entries(labelCounts) as [
    ClassificationLabel,
    number
  ][]) {
    // Start with the log-prior probability P(label)
    // Use log to prevent underflow
    let probability = Math.log(labelCount / instanceCount);

    // Loop through each feature in the query vector
    query.coordinates.forEach((value, index) => {
      const attributeCounts = attributeValueCounts[label][index] || {
        y: 0,
        n: 0,
        "?": 0,
      };

      // Count of the specific value of this feature for the label
      const sameValueAttributeCount = attributeCounts[value] || 0;

      // Apply Laplace smoothing (alpha = 1)
      const alpha = 1;
      const smoothedProbability =
        (sameValueAttributeCount + alpha) /
        (labelCount + alpha * Object.keys(attributeCounts).length);

      // Add the log of the smoothed probability
      probability += Math.log(smoothedProbability);
    });

    // Store the calculated probability for the label
    probabilities.push({ probability, label });
  }

  // Return the label with the highest probability
  return probabilities.reduce((max, current) =>
    current.probability > max.probability ? current : max
  ).label;
}
