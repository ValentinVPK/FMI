/**
 * Simulates a weighted random selection based on a given array of probabilities.
 * Each index in the array has a likelihood of being selected proportional to its value.
 * Commonly used in scenarios like roulette wheel selection or stochastic decision-making.
 *
 * @param probabilities - An array of numbers representing the probabilities or weights for each index.
 * @returns The index of the selected item, based on the probabilities.
 */
export function discreteDistribution(probabilities: number[]): number {
  const totalProbability = probabilities.reduce(
    (sum, probability) => sum + probability,
    0
  );
  const randomValue = Math.random() * totalProbability;

  let cumulativeProbability = 0;
  for (let i = 0; i < probabilities.length; i++) {
    cumulativeProbability += probabilities[i];
    if (randomValue < cumulativeProbability) {
      return i;
    }
  }

  return probabilities.length - 1;
}
