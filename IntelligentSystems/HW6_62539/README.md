# Building and Running the Puzzle Solver

To run the `main.ts` file, follow these steps:

1. **Build the TypeScript file** to generate a JavaScript file (You can skip this step as the JS files are already built)
   tsc main.ts
2. **Run the compiled JavaScript file**
   node main.js

You will need to install a node.js to run this project

# Naive Bayes Classifier for Congressional Voting Records

## Overview

This project implements a **Naive Bayes Classifier** to classify individuals as **Democrats** or **Republicans** based on their voting records. The dataset used is the **Congressional Voting Records Dataset** from the [UCI Machine Learning Repository](https://archive.ics.uci.edu/dataset/105/congressional+voting+records). The classifier handles missing data (`"?"`) and outputs accuracy metrics for its performance.

---

## Task Requirements

The task requires:

1. **Handling Missing Data (`"?"`)**:
   - First approach: Treat `"?"` as a third value ("abstained").
   - Second approach: Replace `"?"` with `"y"` or `"n"` using a probabilistic method based on observed distributions.
2. **Naive Bayes Classification**:
   - Prevent zero probabilities using **Laplace Smoothing**.
3. **Performance Metrics**:
   - Accuracy on the training dataset.
   - Average accuracy and standard deviation from **10-fold cross-validation**.
   - Accuracy on the test dataset.

---

## Dataset Description

- **Attributes**: 16 binary attributes (`"y"` for "yes", `"n"` for "no", `"?"` for missing).
- **Classes**:
  - Democrat
  - Republican
- **Class Distribution**:
  - 267 Democrats
  - 168 Republicans

---

## Approach to Missing Data (`"?"`)

### Method Used in This Solution

We replace `"?"` using **probabilistic sampling** based on observed data distributions:

1. **Frequency Calculation**:
   - Count occurrences of `"y"` and `"n"` for each attribute, ignoring `"?"`.
2. **Probability Estimation**:
   - Calculate \(P(y)\) as:
     \[
     P(y) = \frac{\text{count of "y"}}{\text{count of "y" + count of "n"}}
     \]
     - Similarly, \(P(n) = 1 - P(y)\).
3. **Random Replacement**:
   - Use a **Bernoulli Distribution** to replace `"?"`:
     - Replace `"?"` with `"y"` with probability \(P(y)\).
     - Replace `"?"` with `"n"` with probability \(P(n)\).

### Reason for This Approach

- **Consistency with Observed Data**: Replacements reflect the dataset's distribution of `"y"` and `"n"`.
- **Avoiding Bias**: Random replacements prevent over-representation of either `"y"` or `"n"`.
- **Simple and Effective**: This probabilistic method is computationally efficient and avoids overcomplicating the imputation process.

---

# Laplace Smoothing Observations

## Overview

Laplace smoothing was tested on the Naive Bayes Classifier to observe its effect on classification accuracy. The purpose of Laplace smoothing is to prevent zero probabilities for unseen feature-label combinations by introducing a smoothing parameter, `α` (alpha). The default value of `α` is 1, but we experimented with other values to analyze their impact on the model's performance.

## Values Tested

The following values of `α` were tested:

- **0.1**: A small smoothing factor to slightly reduce the effect of unseen combinations.
- **0.5**: A moderate smoothing factor to provide balanced smoothing without excessive distortion.
- **2**: A larger smoothing factor to amplify the smoothing effect and give more weight to unseen combinations.
- **5**: A high smoothing factor to exaggerate the smoothing, potentially diminishing the influence of actual probabilities.

## Results

For all tested values of `α`, the model consistently achieved around **90% accuracy**. This result indicates that the classifier's performance is robust to changes in the smoothing parameter within this range.

### Key Findings

1. **Minimal Impact on Accuracy**: The use of different `α` values did not significantly affect the model's overall accuracy. This robustness suggests that the dataset is well-suited for the Naive Bayes approach and that the smoothing parameter plays a relatively minor role in this specific case.
2. **Consistency Across Values**: Even with higher smoothing factors like `α = 5`, the accuracy remained stable, further reinforcing the notion that the dataset contains sufficient information to classify effectively without over-reliance on smoothing.

## Conclusion

The Naive Bayes Classifier's accuracy appears resilient to changes in the Laplace smoothing parameter. While testing alternative values of `α` is a good practice to ensure model robustness, the results suggest that the classifier performs reliably under varying smoothing conditions for the given dataset.

**Recommendation**: The default value of `α = 1` remains a suitable choice, as it balances simplicity and effectiveness without compromising accuracy.
