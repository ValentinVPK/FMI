"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.discreteDistribution = discreteDistribution;
/**
 * Simulates a weighted random selection based on a given array of probabilities.
 * Each index in the array has a likelihood of being selected proportional to its value.
 * Commonly used in scenarios like roulette wheel selection or stochastic decision-making.
 *
 * @param probabilities - An array of numbers representing the probabilities or weights for each index.
 * @returns The index of the selected item, based on the probabilities.
 */
function discreteDistribution(probabilities) {
    var totalProbability = probabilities.reduce(function (sum, probability) { return sum + probability; }, 0);
    var randomValue = Math.random() * totalProbability;
    var cumulativeProbability = 0;
    for (var i = 0; i < probabilities.length; i++) {
        cumulativeProbability += probabilities[i];
        if (randomValue < cumulativeProbability) {
            return i;
        }
    }
    return probabilities.length - 1;
}
