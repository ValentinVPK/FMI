"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.trainNaiveBayes = trainNaiveBayes;
exports.classifyNaiveBayes = classifyNaiveBayes;
function trainNaiveBayes(data) {
    var labelCounts = {
        democrat: 0,
        republican: 0,
    }; // Tracks count of examples per label
    var attributeValueCounts = {
        democrat: {},
        republican: {},
    }; // Tracks counts of feature values per label and attribute
    var instanceCount = data.length; // Total number of examples
    var _loop_1 = function (featureVector, label) {
        // Update label counts
        if (!labelCounts[label]) {
            labelCounts[label] = 0;
        }
        labelCounts[label]++;
        // Update attribute value counts
        if (!attributeValueCounts[label]) {
            attributeValueCounts[label] = {};
        }
        featureVector.coordinates.forEach(function (value, index) {
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
    };
    // Process each training example
    for (var _i = 0, data_1 = data; _i < data_1.length; _i++) {
        var _a = data_1[_i], featureVector = _a.featureVector, label = _a.label;
        _loop_1(featureVector, label);
    }
    return { labelCounts: labelCounts, attributeValueCounts: attributeValueCounts, instanceCount: instanceCount };
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
function classifyNaiveBayes(model, query) {
    var labelCounts = model.labelCounts, attributeValueCounts = model.attributeValueCounts, instanceCount = model.instanceCount;
    // To store the calculated probabilities for each label
    var probabilities = [];
    var _loop_2 = function (label, labelCount) {
        // Start with the log-prior probability P(label)
        var probability = Math.log(labelCount / instanceCount);
        // Loop through each feature in the query vector
        query.coordinates.forEach(function (value, index) {
            var attributeCounts = attributeValueCounts[label][index] || {
                y: 0,
                n: 0,
                "?": 0,
            };
            // Count of the specific value of this feature for the label
            var sameValueAttributeCount = attributeCounts[value] || 0;
            // Apply Laplace smoothing (alpha = 1)
            var alpha = 1;
            var smoothedProbability = (sameValueAttributeCount + alpha) /
                (labelCount + alpha * Object.keys(attributeCounts).length);
            // Add the log of the smoothed probability
            probability += Math.log(smoothedProbability);
        });
        // Store the calculated probability for the label
        probabilities.push({ probability: probability, label: label });
    };
    // Loop through each label (Democrat, Republican)
    for (var _i = 0, _a = Object.entries(labelCounts); _i < _a.length; _i++) {
        var _b = _a[_i], label = _b[0], labelCount = _b[1];
        _loop_2(label, labelCount);
    }
    // Return the label with the highest probability
    return probabilities.reduce(function (max, current) {
        return current.probability > max.probability ? current : max;
    }).label;
}
