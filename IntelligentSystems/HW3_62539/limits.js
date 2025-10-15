"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.REPRODUCTION_RATE = exports.GREEDINES = void 0;
exports.getGenerationLimit = getGenerationLimit;
exports.getMutationRate = getMutationRate;
exports.getPopulationLimit = getPopulationLimit;
exports.GREEDINES = 0.5;
exports.REPRODUCTION_RATE = 0.75;
/**
 * Calculates the maximum number of generations for the genetic algorithm.
 * The limit is scaled based on the problem size (`objectLimit / 2`), capped at 400 for efficiency,
 * and floored at 20 to ensure sufficient iterations for small problems.
 *
 * @param objectLimit - The number of objects in the knapsack problem.
 * @returns The maximum number of generations.
 */
function getGenerationLimit(objectLimit) {
    return Math.max(20, Math.min(400, objectLimit / 2));
}
/**
 * Calculates the mutation rate for the genetic algorithm based on the size of the catalogue.
 * The mutation rate is inversely proportional to the catalogue size, ensuring that:
 * - Smaller catalogues have a higher mutation rate to promote diversity and exploration.
 * - Larger catalogues have a lower mutation rate to prevent excessive disruption while maintaining stability.
 *
 * This dynamic scaling balances the introduction of randomness with the refinement of solutions,
 * adapting the mutation process to different problem sizes.
 *
 * @param catalogueSize - The number of items in the catalogue (total number of genes).
 * @returns The mutation rate as a decimal value, representing the probability of mutation for each gene.
 */
function getMutationRate(catalogueSize) {
    return 1.0 / catalogueSize;
}
/**
 * Calculates the maximum population size for the genetic algorithm.
 * The size is limited to the smaller of `objectLimit * 10` (to ensure scalability and diversity)
 * and `1000` (to maintain efficiency for large problems).
 *
 * @param objectLimit - The number of objects in the knapsack problem.
 * @returns The maximum population size.
 */
function getPopulationLimit(objectLimit) {
    return Math.min(1000, objectLimit * 10);
}
