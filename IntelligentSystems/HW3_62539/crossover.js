"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.onePointCrossover = onePointCrossover;
exports.twoPointCrossover = twoPointCrossover;
exports.uniformCrossover = uniformCrossover;
/**
 * Performs a one-point crossover on two parent individuals to produce two offspring.
 * A random crossover point is selected, and genes are swapped between the parents
 * at that point to create new children. This method preserves large contiguous segments
 * of parent genes while introducing moderate diversity in the offspring.
 *
 * @param firstParent - The first parent individual, containing genes and fitness.
 * @param secondParent - The second parent individual, containing genes and fitness.
 * @returns An array containing two offspring individuals with combined genes.
 *
 * @throws An error if the parents have different numbers of genes.
 */
function onePointCrossover(firstParent, secondParent) {
    if (firstParent.genes.length !== secondParent.genes.length) {
        throw new Error("Parents must have the same number of genes for crossover.");
    }
    var crossoverPoint = Math.floor(Math.random() * (firstParent.genes.length - 1)) + 1;
    var firstChildGenes = [];
    var secondChildGenes = [];
    for (var i = 0; i < firstParent.genes.length; i++) {
        if (i < crossoverPoint) {
            firstChildGenes[i] = firstParent.genes[i];
            secondChildGenes[i] = secondParent.genes[i];
        }
        else {
            firstChildGenes[i] = secondParent.genes[i];
            secondChildGenes[i] = firstParent.genes[i];
        }
    }
    var firstChild = { genes: firstChildGenes, fitness: 0 };
    var secondChild = { genes: secondChildGenes, fitness: 0 };
    return [firstChild, secondChild];
}
/**
 * Performs a two-point crossover on two parent individuals to produce two offspring.
 * Two random crossover points are selected, and the genes between these points are swapped
 * between the parents. This method introduces greater diversity than one-point crossover
 * by allowing multiple segments of genes to be exchanged.
 *
 * @param firstParent - The first parent individual, containing genes and fitness.
 * @param secondParent - The second parent individual, containing genes and fitness.
 * @returns An array containing two offspring individuals with combined genes.
 *
 * @throws An error if the parents have different numbers of genes.
 */
function twoPointCrossover(firstParent, secondParent) {
    var _a;
    if (firstParent.genes.length !== secondParent.genes.length) {
        throw new Error("Parents must have the same number of genes for crossover.");
    }
    var geneLength = firstParent.genes.length;
    var getRandomPoint = function () {
        return Math.floor(Math.random() * (geneLength - 1)) + 1;
    };
    var point1 = getRandomPoint();
    var point2 = getRandomPoint();
    while (point1 === point2) {
        point2 = getRandomPoint();
    }
    if (point1 > point2) {
        _a = [point2, point1], point1 = _a[0], point2 = _a[1];
    }
    var firstChildGenes = [];
    var secondChildGenes = [];
    for (var i = 0; i < geneLength; i++) {
        if (i < point1) {
            firstChildGenes[i] = firstParent.genes[i];
            secondChildGenes[i] = secondParent.genes[i];
        }
        else if (i < point2) {
            firstChildGenes[i] = secondParent.genes[i];
            secondChildGenes[i] = firstParent.genes[i];
        }
        else {
            firstChildGenes[i] = firstParent.genes[i];
            secondChildGenes[i] = secondParent.genes[i];
        }
    }
    var firstChild = { genes: firstChildGenes, fitness: 0 };
    var secondChild = { genes: secondChildGenes, fitness: 0 };
    return [firstChild, secondChild];
}
/**
 * Performs a uniform crossover on two parent individuals to produce two offspring.
 * Each gene in the offspring is independently inherited from one of the parents,
 * with a 50% probability for each parent. This method maximizes genetic diversity
 * by creating fine-grained mixing of parent traits.
 *
 * @param firstParent - The first parent individual, containing genes and fitness.
 * @param secondParent - The second parent individual, containing genes and fitness.
 * @returns An array containing two offspring individuals with combined genes.
 *
 * @throws An error if the parents have different numbers of genes.
 */
function uniformCrossover(firstParent, secondParent) {
    if (firstParent.genes.length !== secondParent.genes.length) {
        throw new Error("Parents must have the same number of genes for crossover.");
    }
    var geneLength = firstParent.genes.length;
    var firstChildGenes = [];
    var secondChildGenes = [];
    for (var i = 0; i < geneLength; i++) {
        if (Math.random() < 0.5) {
            firstChildGenes[i] = firstParent.genes[i];
            secondChildGenes[i] = secondParent.genes[i];
        }
        else {
            firstChildGenes[i] = secondParent.genes[i];
            secondChildGenes[i] = firstParent.genes[i];
        }
    }
    var firstChild = { genes: firstChildGenes, fitness: 0 };
    var secondChild = { genes: secondChildGenes, fitness: 0 };
    return [firstChild, secondChild];
}
