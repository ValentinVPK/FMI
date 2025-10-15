"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.createFromChildren = createFromChildren;
exports.createFromMixing = createFromMixing;
exports.createFromElitism = createFromElitism;
var limits_1 = require("./limits");
var main_1 = require("./main");
/**
 * Generates the next generation by prioritizing the newly created children and supplementing
 * them with parent individuals if space allows. The population is then sorted by fitness
 * to ensure the fittest individuals are prioritized for the next generation.
 *
 * **Key Steps**:
 * 1. Replaces the population with the children, emphasizing exploration and introducing diversity.
 * 2. Adds parent individuals if the population limit has not been reached, preserving strong traits.
 * 3. Sorts the population by fitness in descending order to maintain solution quality.
 *
 * This strategy is designed to encourage diversity while retaining some elite individuals,
 * ensuring a balance between exploration and exploitation.
 *
 * @param population - The current population of individuals to be updated.
 * @param parents - The parent individuals from the previous generation.
 * @param children - The offspring generated from crossover and mutation.
 */
function createFromChildren(population, parents, children) {
    population.length = 0;
    population.push.apply(population, children);
    var i = 0;
    while (i < parents.length &&
        population.length < (0, limits_1.getPopulationLimit)(main_1.objectLimit)) {
        population.push(parents[i]);
        i++;
    }
    population.sort(function (a, b) { return b.fitness - a.fitness; });
}
/**
 * Generates the next generation by combining the current population with the newly generated children.
 * Prioritizes the fittest individuals while introducing diversity by shuffling and mixing weaker solutions.
 * Ensures the population size adheres to the defined limit.
 *
 * **Key Steps**:
 * 1. Adds children to the current population, encouraging exploration and introducing new genetic material.
 * 2. Sorts the population by fitness to retain strong solutions.
 * 3. Splits the population into two halves:
 *    - The top half (fittest individuals) is directly preserved.
 *    - The remaining half is shuffled to maintain diversity and avoid stagnation.
 * 4. Ensures the population size respects the defined limit by trimming or filling as needed.
 *
 * This strategy balances exploration and exploitation, promoting steady improvement
 * while maintaining variability to escape local optima.
 *
 * @param population - The current population of individuals to be updated.
 * @param children - The offspring generated through crossover and mutation.
 */
function createFromMixing(population, children) {
    var _a;
    population.push.apply(population, children);
    population.sort(function (a, b) { return b.fitness - a.fitness; });
    var populationLimit = (0, limits_1.getPopulationLimit)(main_1.objectLimit);
    var halfSize = Math.floor(populationLimit / 2);
    var remaining = population.slice(halfSize);
    for (var i = remaining.length - 1; i > 0; i--) {
        var j = Math.floor(Math.random() * (i + 1));
        _a = [remaining[j], remaining[i]], remaining[i] = _a[0], remaining[j] = _a[1];
    }
    population.length = populationLimit;
    var remainingSize = populationLimit - halfSize;
    var remainingToAdd = remaining.slice(0, remainingSize);
    remainingToAdd.sort(function (a, b) { return b.fitness - a.fitness; });
    for (var i = 0; i < remainingToAdd.length; i++) {
        population[halfSize + i] = remainingToAdd[i];
    }
}
/**
 * Creates the next generation by prioritizing the fittest individuals from the current population
 * and the newly generated children. Combines both groups, sorts them by fitness, and trims the
 * population to the predefined size limit, ensuring that only the strongest individuals are retained.
 *
 * **Key Steps**:
 * 1. Combines the current population with the newly generated children to form a candidate pool.
 * 2. Sorts the combined population in descending order of fitness to prioritize strong solutions.
 * 3. Trims the population to the size limit, discarding weaker individuals and maintaining stability.
 *
 * **Why Use Elitism?**
 * - Focuses on refining strong solutions, rapidly converging toward optimal or near-optimal results.
 * - Preserves the best genetic material, emphasizing exploitation over exploration.
 *
 * **Potential Trade-offs**:
 * - May sacrifice diversity by removing weaker individuals, increasing the risk of premature convergence.
 *
 * @param population - The current population of individuals to be updated.
 * @param children - The offspring generated through crossover and mutation.
 */
function createFromElitism(population, children) {
    var populationLimit = (0, limits_1.getPopulationLimit)(main_1.objectLimit);
    population.push.apply(population, children);
    population.sort(function (a, b) { return b.fitness - a.fitness; });
    if (population.length > populationLimit) {
        population.length = populationLimit;
    }
}
