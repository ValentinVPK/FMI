"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.isIndividualHealthy = isIndividualHealthy;
exports.calculateIndividualFitness = calculateIndividualFitness;
function isIndividualHealthy(individual, weightLimit, catalogue) {
    var totalWeight = 0;
    var totalValue = 0;
    for (var i = 0; i < individual.genes.length; i++) {
        if (individual.genes[i]) {
            totalWeight += catalogue[i].weight;
            totalValue += catalogue[i].value;
        }
    }
    individual.fitness = totalValue;
    return totalWeight < weightLimit;
}
/**
 * Calculates the fitness score of an individual based on the total value of selected items.
 * The fitness is determined by summing the values of the items in the catalogue that are "selected"
 * according to the individual's genes. A higher fitness score indicates a better solution.
 *
 * @param individual - The individual whose fitness is to be calculated. It has:
 *                     - `genes`: An array of booleans indicating item selection.
 *                     - `fitness`: A property where the calculated fitness score will be stored.
 * @param catalogue - The array of items (with `value` and `weight` properties) available for selection.
 */
function calculateIndividualFitness(individual, catalogue) {
    var totalValue = 0;
    for (var i = 0; i < individual.genes.length; i++) {
        if (individual.genes[i]) {
            totalValue += catalogue[i].value;
        }
    }
    individual.fitness = totalValue;
}
