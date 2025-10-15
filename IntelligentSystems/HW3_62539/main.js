"use strict";
var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
var __generator = (this && this.__generator) || function (thisArg, body) {
    var _ = { label: 0, sent: function() { if (t[0] & 1) throw t[1]; return t[1]; }, trys: [], ops: [] }, f, y, t, g = Object.create((typeof Iterator === "function" ? Iterator : Object).prototype);
    return g.next = verb(0), g["throw"] = verb(1), g["return"] = verb(2), typeof Symbol === "function" && (g[Symbol.iterator] = function() { return this; }), g;
    function verb(n) { return function (v) { return step([n, v]); }; }
    function step(op) {
        if (f) throw new TypeError("Generator is already executing.");
        while (g && (g = 0, op[0] && (_ = 0)), _) try {
            if (f = 1, y && (t = op[0] & 2 ? y["return"] : op[0] ? y["throw"] || ((t = y["return"]) && t.call(y), 0) : y.next) && !(t = t.call(y, op[1])).done) return t;
            if (y = 0, t) op = [op[0] & 2, t.value];
            switch (op[0]) {
                case 0: case 1: t = op; break;
                case 4: _.label++; return { value: op[1], done: false };
                case 5: _.label++; y = op[1]; op = [0]; continue;
                case 7: op = _.ops.pop(); _.trys.pop(); continue;
                default:
                    if (!(t = _.trys, t = t.length > 0 && t[t.length - 1]) && (op[0] === 6 || op[0] === 2)) { _ = 0; continue; }
                    if (op[0] === 3 && (!t || (op[1] > t[0] && op[1] < t[3]))) { _.label = op[1]; break; }
                    if (op[0] === 6 && _.label < t[1]) { _.label = t[1]; t = op; break; }
                    if (t && _.label < t[2]) { _.label = t[2]; _.ops.push(op); break; }
                    if (t[2]) _.ops.pop();
                    _.trys.pop(); continue;
            }
            op = body.call(thisArg, _);
        } catch (e) { op = [6, e]; y = 0; } finally { f = t = 0; }
        if (op[0] & 5) throw op[1]; return { value: op[0] ? op[1] : void 0, done: true };
    }
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.objectLimit = void 0;
exports.reproduction = reproduction;
var readline = require("readline");
var fs = require("fs");
var individual_1 = require("./individual");
var limits_1 = require("./limits");
var selection_1 = require("./selection");
var utils_1 = require("./utils");
var crossover_1 = require("./crossover");
var generationCreation_1 = require("./generationCreation");
exports.objectLimit = 0;
var weightLimit = 0;
var catalogue = [];
var onePointCrossoverOccurences = 0;
var twoPointCrossoverOccurences = 0;
var uniformCrossoverOccurences = 0;
var formGenerationFromChildrenOccurences = 0;
var formGenerationFromElitismOccurences = 0;
var formGenerationFromMixingOccurences = 0;
var elitistSelectionOccurences = 0;
var rouletteWheelSelectionOccurences = 0;
var rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});
var ask = function (question) {
    return new Promise(function (resolve) { return rl.question(question, resolve); });
};
function initializeUserInputFromConsole() {
    return __awaiter(this, void 0, void 0, function () {
        var input, _a, inputWeightLimit, inputObjectLimit, i, input_1, _b, weight, value;
        return __generator(this, function (_c) {
            switch (_c.label) {
                case 0: return [4 /*yield*/, ask("Enter weight and object limit: ")];
                case 1:
                    input = (_c.sent());
                    _a = input
                        .toString()
                        .split(" ")
                        .map(Number), inputWeightLimit = _a[0], inputObjectLimit = _a[1];
                    weightLimit = inputWeightLimit;
                    exports.objectLimit = inputObjectLimit;
                    i = 0;
                    _c.label = 2;
                case 2:
                    if (!(i < exports.objectLimit)) return [3 /*break*/, 5];
                    return [4 /*yield*/, ask("Object ".concat(i + 1, ": "))];
                case 3:
                    input_1 = (_c.sent());
                    _b = input_1.split(" ").map(Number), weight = _b[0], value = _b[1];
                    catalogue.push({ weight: weight, value: value });
                    _c.label = 4;
                case 4:
                    i++;
                    return [3 /*break*/, 2];
                case 5:
                    // Sort by value-to-weight ratio in descending order
                    catalogue.sort(function (lhs, rhs) { return rhs.value / rhs.weight - lhs.value / lhs.weight; });
                    return [2 /*return*/];
            }
        });
    });
}
function initializeUserInputFromFile(filePath) {
    return __awaiter(this, void 0, void 0, function () {
        var fileData, lines, _a, inputWeightLimit, inputObjectLimit, i, _b, weight, value, error_1;
        return __generator(this, function (_c) {
            switch (_c.label) {
                case 0:
                    _c.trys.push([0, 3, , 5]);
                    fileData = fs.readFileSync(filePath, "utf-8");
                    lines = fileData
                        .split("\n")
                        .map(function (line) { return line.trim(); })
                        .filter(function (line) { return line.length > 0; });
                    if (!(lines.length < 2)) return [3 /*break*/, 2];
                    console.error("Failed to read enough data from file. Initialize from console instead.");
                    return [4 /*yield*/, initializeUserInputFromConsole()];
                case 1:
                    _c.sent();
                    return [2 /*return*/];
                case 2:
                    _a = lines[0]
                        .split(" ")
                        .map(Number), inputWeightLimit = _a[0], inputObjectLimit = _a[1];
                    weightLimit = inputWeightLimit;
                    exports.objectLimit = inputObjectLimit;
                    for (i = 1; i <= exports.objectLimit; i++) {
                        _b = lines[i].split(" ").map(Number), weight = _b[0], value = _b[1];
                        catalogue.push({ weight: weight, value: value });
                    }
                    // Sort by value-to-weight ratio in descending order
                    catalogue.sort(function (lhs, rhs) { return rhs.value / rhs.weight - lhs.value / lhs.weight; });
                    return [3 /*break*/, 5];
                case 3:
                    error_1 = _c.sent();
                    console.error("Failed to input catalogue from file. Initialize from console instead.", error_1);
                    return [4 /*yield*/, initializeUserInputFromConsole()];
                case 4:
                    _c.sent();
                    return [3 /*break*/, 5];
                case 5: return [2 /*return*/];
            }
        });
    });
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
function generateRandomIndividual() {
    var genes = new Array(exports.objectLimit).fill(false);
    var tempGreedines = limits_1.GREEDINES;
    var reduction = tempGreedines / exports.objectLimit;
    var weight = 0;
    for (var i = 0; i < exports.objectLimit; i++) {
        var isSelected = Math.random() < tempGreedines;
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
    var individual = { genes: genes, fitness: 0 };
    (0, individual_1.calculateIndividualFitness)(individual, catalogue);
    return individual;
}
function generateInitialPopulation() {
    var population = [];
    while (population.length < (0, limits_1.getPopulationLimit)(exports.objectLimit)) {
        var tempIndividual = generateRandomIndividual();
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
function selection(population) {
    var selectedIndex = (0, utils_1.discreteDistribution)([1, 1]);
    switch (selectedIndex) {
        case 0:
            elitistSelectionOccurences++;
            return (0, selection_1.elitistSelection)(population, exports.objectLimit);
        case 1:
            rouletteWheelSelectionOccurences++;
            return (0, selection_1.rouletteWheelSelection)(population, exports.objectLimit);
        default:
            elitistSelectionOccurences++;
            return (0, selection_1.elitistSelection)(population, exports.objectLimit);
    }
}
function reproduction(parents) {
    var children = [];
    for (var i = 0; i < parents.length - 1; i += 2) {
        for (var _i = 0, _a = crossover(parents[i], parents[i + 1]); _i < _a.length; _i++) {
            var child = _a[_i];
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
function crossover(firstParent, secondParent) {
    var selectedIndex = (0, utils_1.discreteDistribution)([2, 5, 5]);
    switch (selectedIndex) {
        case 0:
            onePointCrossoverOccurences++;
            return (0, crossover_1.onePointCrossover)(firstParent, secondParent);
        case 1:
            twoPointCrossoverOccurences++;
            return (0, crossover_1.twoPointCrossover)(firstParent, secondParent);
        case 2:
            uniformCrossoverOccurences++;
            return (0, crossover_1.uniformCrossover)(firstParent, secondParent);
        default:
            return (0, crossover_1.onePointCrossover)(firstParent, secondParent);
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
function mutatePopulation(children) {
    var mutationIsNeeded = function () {
        return Math.random() < (0, limits_1.getMutationRate)(exports.objectLimit);
    };
    children.forEach(function (individual) {
        individual.genes = individual.genes.map(function (gene) {
            return mutationIsNeeded() ? !gene : gene;
        });
    });
    var i = 0;
    while (i < children.length) {
        if (!(0, individual_1.isIndividualHealthy)(children[i], weightLimit, catalogue)) {
            children.splice(i, 1);
        }
        else {
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
function createNewGeneration(population, parents, children) {
    var probabilities = [1.0, 3.0, 2.5];
    var selectedIndex = (0, utils_1.discreteDistribution)(probabilities);
    switch (selectedIndex) {
        case 0:
            formGenerationFromChildrenOccurences++;
            (0, generationCreation_1.createFromChildren)(population, parents, children);
            break;
        case 1:
            (0, generationCreation_1.createFromMixing)(population, children);
            formGenerationFromMixingOccurences++;
            break;
        case 2:
            formGenerationFromElitismOccurences++;
            (0, generationCreation_1.createFromElitism)(population, children);
            break;
        default:
            throw new Error("Invalid index from discrete distribution");
    }
}
function main() {
    return __awaiter(this, arguments, void 0, function (fromConsole, filePath) {
        var currentGeneration, generatedPopulation, parents, children;
        if (fromConsole === void 0) { fromConsole = false; }
        if (filePath === void 0) { filePath = ""; }
        return __generator(this, function (_a) {
            switch (_a.label) {
                case 0:
                    if (!fromConsole) return [3 /*break*/, 2];
                    return [4 /*yield*/, initializeUserInputFromConsole()];
                case 1:
                    _a.sent();
                    return [3 /*break*/, 4];
                case 2: return [4 /*yield*/, initializeUserInputFromFile(filePath)];
                case 3:
                    _a.sent();
                    _a.label = 4;
                case 4:
                    currentGeneration = 0;
                    generatedPopulation = generateInitialPopulation();
                    generatedPopulation.sort(function (a, b) { return b.fitness - a.fitness; });
                    while (currentGeneration < (0, limits_1.getGenerationLimit)(exports.objectLimit)) {
                        parents = selection(generatedPopulation);
                        children = reproduction(parents);
                        mutatePopulation(children);
                        createNewGeneration(generatedPopulation, parents, children);
                        currentGeneration++;
                        console.log(generatedPopulation[0].fitness);
                    }
                    rl.close();
                    return [2 /*return*/, 0];
            }
        });
    });
}
main(false, "KP short test data.txt");
