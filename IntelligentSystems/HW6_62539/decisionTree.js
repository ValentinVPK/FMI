"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.calculateEntropy = calculateEntropy;
exports.calculateInformationGain = calculateInformationGain;
exports.buildDecisionTree = buildDecisionTree;
exports.classify = classify;
// Calculate entropy of a dataset
function calculateEntropy(data) {
    var labelCounts = {
        "no-recurrence-events": 0,
        "recurrence-events": 0,
    };
    // Count occurrences of each label
    data.forEach(function (point) { return labelCounts[point.label]++; });
    // Calculate entropy
    return Object.values(labelCounts).reduce(function (entropy, count) {
        if (count === 0)
            return entropy; // Skip 0 counts
        var probability = count / data.length;
        return entropy - probability * Math.log2(probability);
    }, 0);
}
// Calculate information gain for a specific attribute
function calculateInformationGain(data, attributeIndex) {
    // Calculate parent entropy
    var parentEntropy = calculateEntropy(data);
    // Group data by attribute value
    var subsets = {};
    data.forEach(function (point) {
        var value = point.features[attributeIndex];
        if (!subsets[value])
            subsets[value] = [];
        subsets[value].push(point);
    });
    // Calculate weighted entropy after split
    var weightedEntropy = Object.values(subsets).reduce(function (totalEntropy, subset) {
        var subsetProbability = subset.length / data.length;
        return totalEntropy + subsetProbability * calculateEntropy(subset);
    }, 0);
    // Information Gain = Parent Entropy - Weighted Entropy
    return parentEntropy - weightedEntropy;
}
// Build the decision tree
function buildDecisionTree(data, attributes, // Indices of available attributes
depth, // Current depth for pre-pruning
maxDepth, // Max depth for pre-pruning
minSamples, // Minimum samples for pre-pruning
minGain // Minimum gain for pre-pruning
) {
    if (depth === void 0) { depth = 0; }
    if (maxDepth === void 0) { maxDepth = 5; }
    if (minSamples === void 0) { minSamples = 3; }
    if (minGain === void 0) { minGain = 0.01; }
    // Base cases for stopping
    if (data.length === 0) {
        return { isLeaf: true, label: "no-recurrence-events" }; // Default label
    }
    var uniqueLabels = new Set(data.map(function (point) { return point.label; }));
    if (uniqueLabels.size === 1) {
        return { isLeaf: true, label: data[0].label }; // Pure node
    }
    if (attributes.length === 0 ||
        depth >= maxDepth ||
        data.length < minSamples) {
        var mostCommonLabel = getMostCommonLabel(data);
        return { isLeaf: true, label: mostCommonLabel };
    }
    // Select the best attribute to split
    var bestAttribute = -1;
    var bestGain = 0;
    attributes.forEach(function (attrIndex) {
        var gain = calculateInformationGain(data, attrIndex);
        if (gain > bestGain) {
            bestGain = gain;
            bestAttribute = attrIndex;
        }
    });
    // Stop if gain is below threshold
    if (bestGain < minGain) {
        var mostCommonLabel = getMostCommonLabel(data);
        return { isLeaf: true, label: mostCommonLabel };
    }
    // Partition data by the best attribute
    var subsets = {};
    data.forEach(function (point) {
        var value = point.features[bestAttribute];
        if (!subsets[value])
            subsets[value] = [];
        subsets[value].push(point);
    });
    // Build subtrees recursively
    var children = {};
    Object.entries(subsets).forEach(function (_a) {
        var value = _a[0], subset = _a[1];
        children[value] = buildDecisionTree(subset, attributes.filter(function (attr) { return attr !== bestAttribute; }), depth + 1, maxDepth, minSamples, minGain);
    });
    return {
        isLeaf: false,
        attributeIndex: bestAttribute,
        children: children,
    };
}
// Helper function to find the most common label
function getMostCommonLabel(data) {
    var labelCounts = {
        "no-recurrence-events": 0,
        "recurrence-events": 0,
    };
    data.forEach(function (point) { return labelCounts[point.label]++; });
    return labelCounts["no-recurrence-events"] >= labelCounts["recurrence-events"]
        ? "no-recurrence-events"
        : "recurrence-events";
}
// Classify a data point using the decision tree
function classify(tree, dataPoint) {
    var _a;
    if (tree.isLeaf) {
        return tree.label;
    }
    var value = dataPoint.features[tree.attributeIndex];
    var child = (_a = tree.children) === null || _a === void 0 ? void 0 : _a[value];
    if (!child) {
        // Default to most common label if path does not exist
        return "no-recurrence-events";
    }
    return classify(child, dataPoint);
}
