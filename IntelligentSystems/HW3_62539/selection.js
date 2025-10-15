"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.elitistSelection = elitistSelection;
exports.rouletteWheelSelection = rouletteWheelSelection;
var limits_1 = require("./limits");
/**
 * Selects the fittest individuals from the population for reproduction.
 * This elitist strategy ensures the strongest solutions (highest fitness) are preserved
 * by directly selecting the top-performing individuals based on their fitness.
 * The selection size is determined by the reproduction rate and population limits.
 *
 * @param population - The current population of individuals, sorted in descending order of fitness.
 * @param objectLimit - The number of objects in the knapsack problem, used to calculate population limits.
 * @returns A new population consisting of the fittest individuals for reproduction.
 */
function elitistSelection(population, objectLimit) {
    var selection = [];
    var selectionLimit = Math.min(population.length, Math.floor((0, limits_1.getPopulationLimit)(objectLimit) * limits_1.REPRODUCTION_RATE));
    for (var i = 0; i < selectionLimit; i++) {
        selection.push(population[i]);
    }
    return selection;
}
/**
 * Selects individuals from the population for reproduction using roulette wheel selection.
 * Each individual's likelihood of being selected is proportional to its fitness.
 * Higher fitness increases the probability of selection, but lower-fitness individuals
 * can still be chosen, promoting diversity in the population.
 *
 * This method computes cumulative probabilities based on fitness values and maps random
 * numbers to these probabilities to select individuals probabilistically.
 *
 * @param population - The current population of individuals.
 * @param objectLimit - The number of objects in the knapsack problem, used to calculate population limits.
 * @returns A new population of individuals selected for reproduction.
 */
function rouletteWheelSelection(population, objectLimit) {
    var selection = [];
    var totalFitness = population.reduce(function (acc, individual) { return acc + individual.fitness; }, 0);
    var cumulativeProbabilities = [];
    var comulativeProbability = 0;
    for (var _i = 0, population_1 = population; _i < population_1.length; _i++) {
        var individual = population_1[_i];
        comulativeProbability += individual.fitness;
        cumulativeProbabilities.push(comulativeProbability);
    }
    var selectionLimit = Math.min(population.length, Math.floor((0, limits_1.getPopulationLimit)(objectLimit) * limits_1.REPRODUCTION_RATE));
    while (selection.length < selectionLimit) {
        var randomValue = Math.random() * totalFitness;
        for (var i = 0; i < population.length; i++) {
            if (randomValue <= cumulativeProbabilities[i]) {
                selection.push(population[i]);
                break;
            }
        }
    }
    return selection;
}
