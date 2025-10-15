import * as readline from "readline";
import * as fs from "fs";
import { CarryObject } from "./carryObject";
import {
  calculateIndividualFitness,
  Individual,
  isIndividualHealthy,
  Population,
} from "./individual";
import {
  getGenerationLimit,
  getMutationRate,
  getPopulationLimit,
  GREEDINES,
} from "./limits";
import { elitistSelection, rouletteWheelSelection } from "./selection";
import { discreteDistribution } from "./utils";
import {
  onePointCrossover,
  twoPointCrossover,
  uniformCrossover,
} from "./crossover";
import {
  createFromChildren,
  createFromElitism,
  createFromMixing,
} from "./generationCreation";

export let objectLimit: number = 0;
let weightLimit: number = 0;
const catalogue: CarryObject[] = [];

let onePointCrossoverOccurences = 0;
let twoPointCrossoverOccurences = 0;
let uniformCrossoverOccurences = 0;
let formGenerationFromChildrenOccurences = 0;
let formGenerationFromElitismOccurences = 0;
let formGenerationFromMixingOccurences = 0;
let elitistSelectionOccurences = 0;
let rouletteWheelSelectionOccurences = 0;

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
const ask = (question: string) =>
  new Promise((resolve) => rl.question(question, resolve));

async function initializeUserInputFromConsole() {
  const input = (await ask("Enter weight and object limit: ")) as string;

  const [inputWeightLimit, inputObjectLimit] = input
    .toString()
    .split(" ")
    .map(Number);

  weightLimit = inputWeightLimit;
  objectLimit = inputObjectLimit;

  for (let i = 0; i < objectLimit; i++) {
    const input = (await ask(`Object ${i + 1}: `)) as string;
    const [weight, value] = input.split(" ").map(Number);
    catalogue.push({ weight, value });
  }

  // Sort by value-to-weight ratio in descending order
  catalogue.sort((lhs, rhs) => rhs.value / rhs.weight - lhs.value / lhs.weight);
}

async function initializeUserInputFromFile(filePath: string) {
  try {
    const fileData = fs.readFileSync(filePath, "utf-8");
    const lines = fileData
      .split("\n")
      .map((line) => line.trim())
      .filter((line) => line.length > 0);

    if (lines.length < 2) {
      console.error(
        "Failed to read enough data from file. Initialize from console instead."
      );
      await initializeUserInputFromConsole();
      return;
    }

    const [inputWeightLimit, inputObjectLimit] = lines[0]
      .split(" ")
      .map(Number);
    weightLimit = inputWeightLimit;
    objectLimit = inputObjectLimit;

    for (let i = 1; i <= objectLimit; i++) {
      const [weight, value] = lines[i].split(" ").map(Number);
      catalogue.push({ weight, value });
    }

    // Sort by value-to-weight ratio in descending order
    catalogue.sort(
      (lhs, rhs) => rhs.value / rhs.weight - lhs.value / lhs.weight
    );
  } catch (error) {
    console.error(
      "Failed to input catalogue from file. Initialize from console instead.",
      error
    );
    await initializeUserInputFromConsole();
  }
}

/**
 * Generates a random individual (potential solution) for the knapsack problem.
 * The individual is represented by a boolean array (`genes`) indicating the selection of items.
 * The selection process is guided by a "greediness" factor, which decreases with each item
 * to prioritize earlier items in the sorted catalogue while maintaining randomness.
 * Ensures the total weight of selected items does not exceed the weight limit.
 *
 * @returns An individual object with:
 *          - `genes`: A boolean array representing selected items.
 *          - `fitness`: The total value of the selected items.
 */
function generateRandomIndividual(): Individual {
  const genes: boolean[] = new Array(objectLimit).fill(false);
  let tempGreedines = GREEDINES;
  let reduction = tempGreedines / objectLimit;
  let weight = 0;

  for (let i = 0; i < objectLimit; i++) {
    const isSelected = Math.random() < tempGreedines;
    genes[i] = isSelected;

    if (isSelected) {
      weight += catalogue[i].weight;
      if (weight > weightLimit) {
        genes[i] = false;
        break;
      }
    }

    tempGreedines -= reduction;
  }

  const individual: Individual = { genes, fitness: 0 };
  calculateIndividualFitness(individual, catalogue);
  return individual;
}

function generateInitialPopulation(): Population {
  const population: Population = [];

  while (population.length < getPopulationLimit(objectLimit)) {
    const tempIndividual = generateRandomIndividual();
    population.push(tempIndividual);
  }

  return population;
}

/**
 * Selects parents from the population for reproduction by randomly choosing
 * between two strategies: elitist selection or roulette wheel selection.
 * - Elitist selection prioritizes the most fit individuals, ensuring strong solutions are preserved.
 * - Roulette wheel selection probabilistically chooses individuals based on fitness, promoting diversity.
 *
 * The selection strategy is determined using weighted random selection with equal probabilities.
 * Tracks the number of times each strategy is used for analysis.
 *
 * @param population - The current population of individuals.
 * @returns A new population consisting of selected parents for reproduction.
 */
function selection(population: Population): Population {
  const selectedIndex = discreteDistribution([1, 1]);

  switch (selectedIndex) {
    case 0:
      elitistSelectionOccurences++;
      return elitistSelection(population, objectLimit);
    case 1:
      rouletteWheelSelectionOccurences++;
      return rouletteWheelSelection(population, objectLimit);
    default:
      elitistSelectionOccurences++;
      return elitistSelection(population, objectLimit);
  }
}

export function reproduction(parents: Population): Population {
  const children: Population = [];
  for (let i = 0; i < parents.length - 1; i += 2) {
    for (const child of crossover(parents[i], parents[i + 1])) {
      children.push(child);
    }
  }

  return children;
}

/**
 * Combines the genes of two parents to produce offspring using a randomly chosen crossover strategy.
 * The function selects one of three strategies—one-point, two-point, or uniform crossover—
 * based on weighted probabilities:
 * - **One-point crossover (lower chance)**: Preserves larger segments of parent genes, focusing on exploitation.
 * - **Two-point crossover (higher chance)**: Introduces moderate variability, balancing exploration and exploitation.
 * - **Uniform crossover (higher chance)**: Promotes maximum diversity by mixing genes at the individual level, enhancing exploration.
 *
 * This balanced approach ensures the algorithm can explore the solution space effectively while refining high-quality solutions.
 *
 * @param firstParent - The first parent individual.
 * @param secondParent - The second parent individual.
 * @returns An array of two offspring individuals.
 */
function crossover(firstParent: Individual, secondParent: Individual) {
  const selectedIndex = discreteDistribution([2, 5, 5]);

  switch (selectedIndex) {
    case 0:
      onePointCrossoverOccurences++;
      return onePointCrossover(firstParent, secondParent);
    case 1:
      twoPointCrossoverOccurences++;
      return twoPointCrossover(firstParent, secondParent);
    case 2:
      uniformCrossoverOccurences++;
      return uniformCrossover(firstParent, secondParent);
    default:
      return onePointCrossover(firstParent, secondParent);
  }
}

/**
 * Applies mutation to the population of children by flipping genes with a probability
 * determined by the mutation rate. Ensures all individuals remain valid solutions
 * by removing those that exceed the weight limit.
 *
 * **Key Steps**:
 * 1. Randomly decides whether to mutate each gene based on the mutation rate.
 * 2. Flips the gene (true → false, false → true) if mutation occurs.
 * 3. Removes unhealthy individuals whose total weight exceeds the allowed weight limit.
 *
 * This function introduces genetic diversity while maintaining a feasible population.
 *
 * @param children - The population of offspring to be mutated and validated.
 */
function mutatePopulation(children: Population) {
  const mutationIsNeeded = (): boolean =>
    Math.random() < getMutationRate(objectLimit);

  children.forEach((individual) => {
    individual.genes = individual.genes.map((gene) =>
      mutationIsNeeded() ? !gene : gene
    );
  });

  let i = 0;
  while (i < children.length) {
    if (!isIndividualHealthy(children[i], weightLimit, catalogue)) {
      children.splice(i, 1);
    } else {
      i++;
    }
  }
}

/**
 * Creates the next generation by selecting one of three strategies based on weighted probabilities:
 * - **`createFromChildren` (Probability: 1.0)**: Focuses solely on the new children, maximizing diversity.
 * - **`createFromMixing` (Probability: 3.0)**: Combines children with the existing population, balancing exploration and exploitation.
 * - **`createFromElitism` (Probability: 2.5)**: Prioritizes the best individuals from the current population, refining strong solutions.
 *
 * **Why These Probabilities?**
 * - **1.0 (Children)**: Ensures diversity but minimizes disruption to elite traits by using this strategy sparingly.
 * - **3.0 (Mixing)**: A balanced approach, emphasizing both preservation of strong traits and introduction of variability.
 * - **2.5 (Elitism)**: Focuses on refining strong solutions but avoids over-reliance to prevent premature convergence.
 *
 * The chosen weights reflect the algorithm’s need for diversity early on and refinement as it progresses.
 *
 * @param population - The current population of individuals.
 * @param parents - The parent individuals selected for reproduction.
 * @param children - The offspring generated through crossover and mutation.
 */
function createNewGeneration(
  population: Population,
  parents: Population,
  children: Population
) {
  const probabilities = [1.0, 3.0, 2.5];
  const selectedIndex = discreteDistribution(probabilities);

  switch (selectedIndex) {
    case 0:
      formGenerationFromChildrenOccurences++;
      createFromChildren(population, parents, children);
      break;

    case 1:
      createFromMixing(population, children);
      formGenerationFromMixingOccurences++;
      break;

    case 2:
      formGenerationFromElitismOccurences++;
      createFromElitism(population, children);
      break;

    default:
      throw new Error("Invalid index from discrete distribution");
  }
}

async function main(fromConsole = false, filePath = "") {
  if (fromConsole) {
    await initializeUserInputFromConsole();
  } else {
    await initializeUserInputFromFile(filePath);
  }

  let currentGeneration = 0;
  const generatedPopulation = generateInitialPopulation();
  generatedPopulation.sort((a, b) => b.fitness - a.fitness);

  while (currentGeneration < getGenerationLimit(objectLimit)) {
    const parents: Population = selection(generatedPopulation);
    const children: Population = reproduction(parents);
    mutatePopulation(children);
    createNewGeneration(generatedPopulation, parents, children);
    currentGeneration++;
    console.log(generatedPopulation[0].fitness);
  }

  rl.close();
  return 0;
}

main(false, "KP short test data.txt");
