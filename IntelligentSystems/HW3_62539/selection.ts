import { Population } from "./individual";
import { getPopulationLimit, REPRODUCTION_RATE } from "./limits";

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
export function elitistSelection(
  population: Population,
  objectLimit: number
): Population {
  const selection: Population = [];

  const selectionLimit = Math.min(
    population.length,
    Math.floor(getPopulationLimit(objectLimit) * REPRODUCTION_RATE)
  );

  for (let i = 0; i < selectionLimit; i++) {
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
export function rouletteWheelSelection(
  population: Population,
  objectLimit: number
): Population {
  const selection: Population = [];
  const totalFitness = population.reduce(
    (acc, individual) => acc + individual.fitness,
    0
  );

  const cumulativeProbabilities: number[] = [];
  let comulativeProbability = 0;
  for (const individual of population) {
    comulativeProbability += individual.fitness;
    cumulativeProbabilities.push(comulativeProbability);
  }

  const selectionLimit = Math.min(
    population.length,
    Math.floor(getPopulationLimit(objectLimit) * REPRODUCTION_RATE)
  );

  while (selection.length < selectionLimit) {
    const randomValue = Math.random() * totalFitness;

    for (let i = 0; i < population.length; i++) {
      if (randomValue <= cumulativeProbabilities[i]) {
        selection.push(population[i]);
        break;
      }
    }
  }

  return selection;
}
