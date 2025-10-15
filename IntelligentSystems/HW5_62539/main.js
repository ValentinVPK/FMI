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
var __asyncValues = (this && this.__asyncValues) || function (o) {
    if (!Symbol.asyncIterator) throw new TypeError("Symbol.asyncIterator is not defined.");
    var m = o[Symbol.asyncIterator], i;
    return m ? m.call(o) : (o = typeof __values === "function" ? __values(o) : o[Symbol.iterator](), i = {}, verb("next"), verb("throw"), verb("return"), i[Symbol.asyncIterator] = function () { return this; }, i);
    function verb(n) { i[n] = o[n] && function (v) { return new Promise(function (resolve, reject) { v = o[n](v), settle(resolve, reject, v.done, v.value); }); }; }
    function settle(resolve, reject, d, v) { Promise.resolve(v).then(function(v) { resolve({ value: v, done: d }); }, reject); }
};
var __spreadArray = (this && this.__spreadArray) || function (to, from, pack) {
    if (pack || arguments.length === 2) for (var i = 0, l = from.length, ar; i < l; i++) {
        if (ar || !(i in from)) {
            if (!ar) ar = Array.prototype.slice.call(from, 0, i);
            ar[i] = from[i];
        }
    }
    return to.concat(ar || Array.prototype.slice.call(from));
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.readCSVWithAbstained = readCSVWithAbstained;
exports.readCSVWithReplacement = readCSVWithReplacement;
exports.crossValidation = crossValidation;
exports.stratifiedSplit = stratifiedSplit;
exports.trainAndTest = trainAndTest;
var readline = require("readline");
var fs = require("fs");
var constants_1 = require("./constants");
var naiveBayesClassifier_1 = require("./naiveBayesClassifier");
var readline_1 = require("readline");
var featureVectorToLabelMap = [];
/**
 * Reads the CSV file and handles "?" as an abstained value.
 */
function readCSVWithAbstained(pathToFile) {
    return __awaiter(this, void 0, void 0, function () {
        var fileStream, rl, _a, rl_1, rl_1_1, line, segments, features, i, char, featureVector, label, e_1_1;
        var _b, e_1, _c, _d;
        return __generator(this, function (_e) {
            switch (_e.label) {
                case 0:
                    fileStream = fs.createReadStream(pathToFile);
                    rl = (0, readline_1.createInterface)({
                        input: fileStream,
                        crlfDelay: Infinity,
                    });
                    _e.label = 1;
                case 1:
                    _e.trys.push([1, 6, 7, 12]);
                    _a = true, rl_1 = __asyncValues(rl);
                    _e.label = 2;
                case 2: return [4 /*yield*/, rl_1.next()];
                case 3:
                    if (!(rl_1_1 = _e.sent(), _b = rl_1_1.done, !_b)) return [3 /*break*/, 5];
                    _d = rl_1_1.value;
                    _a = false;
                    line = _d;
                    if (!line.trim())
                        return [3 /*break*/, 4];
                    segments = line.split(",").map(function (s) { return s.trim(); });
                    features = [];
                    for (i = 1; i < segments.length; i++) {
                        char = segments[i][0];
                        features.push(char);
                    }
                    featureVector = { coordinates: features };
                    label = segments[0];
                    featureVectorToLabelMap.push({ featureVector: featureVector, label: label });
                    _e.label = 4;
                case 4:
                    _a = true;
                    return [3 /*break*/, 2];
                case 5: return [3 /*break*/, 12];
                case 6:
                    e_1_1 = _e.sent();
                    e_1 = { error: e_1_1 };
                    return [3 /*break*/, 12];
                case 7:
                    _e.trys.push([7, , 10, 11]);
                    if (!(!_a && !_b && (_c = rl_1.return))) return [3 /*break*/, 9];
                    return [4 /*yield*/, _c.call(rl_1)];
                case 8:
                    _e.sent();
                    _e.label = 9;
                case 9: return [3 /*break*/, 11];
                case 10:
                    if (e_1) throw e_1.error;
                    return [7 /*endfinally*/];
                case 11: return [7 /*endfinally*/];
                case 12: return [2 /*return*/];
            }
        });
    });
}
// The "?" values are replaced probabilistically based on the observed frequency of "y" and "n" for each feature, using the probability of "y" to decide the replacement.
// This method preserves the natural distribution of values in the dataset, ensuring the model remains unbiased and generalizes well.
function readCSVWithReplacement(pathToFile) {
    return __awaiter(this, void 0, void 0, function () {
        var counts, fileStream, rl, _a, rl_2, rl_2_1, line, segments, features, i, char, featureVector, label, e_2_1, probabilities;
        var _b, e_2, _c, _d;
        return __generator(this, function (_e) {
            switch (_e.label) {
                case 0:
                    counts = Array(constants_1.FEATURE_COUNT)
                        .fill(null)
                        .map(function () { return ({ y: 0, n: 0 }); });
                    fileStream = fs.createReadStream(pathToFile);
                    rl = (0, readline_1.createInterface)({
                        input: fileStream,
                        crlfDelay: Infinity,
                    });
                    _e.label = 1;
                case 1:
                    _e.trys.push([1, 6, 7, 12]);
                    _a = true, rl_2 = __asyncValues(rl);
                    _e.label = 2;
                case 2: return [4 /*yield*/, rl_2.next()];
                case 3:
                    if (!(rl_2_1 = _e.sent(), _b = rl_2_1.done, !_b)) return [3 /*break*/, 5];
                    _d = rl_2_1.value;
                    _a = false;
                    line = _d;
                    if (!line.trim())
                        return [3 /*break*/, 4];
                    segments = line.split(",").map(function (s) { return s.trim(); });
                    features = [];
                    for (i = 1; i < segments.length; i++) {
                        char = segments[i][0];
                        features.push(char);
                        if (char !== "?") {
                            counts[i - 1][char]++;
                        }
                    }
                    featureVector = { coordinates: features };
                    label = segments[0];
                    featureVectorToLabelMap.push({ featureVector: featureVector, label: label });
                    _e.label = 4;
                case 4:
                    _a = true;
                    return [3 /*break*/, 2];
                case 5: return [3 /*break*/, 12];
                case 6:
                    e_2_1 = _e.sent();
                    e_2 = { error: e_2_1 };
                    return [3 /*break*/, 12];
                case 7:
                    _e.trys.push([7, , 10, 11]);
                    if (!(!_a && !_b && (_c = rl_2.return))) return [3 /*break*/, 9];
                    return [4 /*yield*/, _c.call(rl_2)];
                case 8:
                    _e.sent();
                    _e.label = 9;
                case 9: return [3 /*break*/, 11];
                case 10:
                    if (e_2) throw e_2.error;
                    return [7 /*endfinally*/];
                case 11: return [7 /*endfinally*/];
                case 12:
                    probabilities = counts.map(function (count) { return count.y / (count.y + count.n); });
                    // Fill "?" with "y" or "n" based on probabilities
                    featureVectorToLabelMap.forEach(function (_a) {
                        var featureVector = _a.featureVector;
                        featureVector.coordinates = featureVector.coordinates.map(function (value, index) {
                            if (value === "?") {
                                var probability = probabilities[index];
                                return Math.random() < probability ? "y" : "n";
                            }
                            return value;
                        });
                    });
                    return [2 /*return*/];
            }
        });
    });
}
function crossValidation() {
    return __awaiter(this, void 0, void 0, function () {
        var shuffledData, partitionSize, validationDataStartingIndex, validationDataEndingIndex, totalSuccesses, totalFails, i, successes, fails, trainData, validationData, classifierModel, _i, validationData_1, _a, featureVector, label, predictedLabel;
        return __generator(this, function (_b) {
            featureVectorToLabelMap.forEach(function (_a) {
                var featureVector = _a.featureVector;
                console.log(featureVector.coordinates.join(", "));
            });
            shuffledData = __spreadArray([], featureVectorToLabelMap, true);
            shuffledData.sort(function () { return Math.random() - 0.5; });
            partitionSize = Math.floor(shuffledData.length / 10);
            validationDataStartingIndex = 0;
            validationDataEndingIndex = partitionSize;
            totalSuccesses = 0;
            totalFails = 0;
            for (i = 0; i < 10; i++) {
                successes = 0;
                fails = 0;
                trainData = __spreadArray(__spreadArray([], shuffledData.slice(0, validationDataStartingIndex), true), shuffledData.slice(validationDataEndingIndex), true);
                validationData = shuffledData.slice(validationDataStartingIndex, validationDataEndingIndex);
                classifierModel = (0, naiveBayesClassifier_1.trainNaiveBayes)(trainData);
                // Validate the classifier on the validation set
                for (_i = 0, validationData_1 = validationData; _i < validationData_1.length; _i++) {
                    _a = validationData_1[_i], featureVector = _a.featureVector, label = _a.label;
                    predictedLabel = (0, naiveBayesClassifier_1.classifyNaiveBayes)(classifierModel, featureVector);
                    if (predictedLabel === label) {
                        successes++;
                    }
                    else {
                        fails++;
                    }
                }
                // Update total successes and failures
                totalSuccesses += successes;
                totalFails += fails;
                // Log results for the current fold
                console.log("Accuracy Fold ".concat(i + 1, ": ").concat(((successes / (successes + fails)) *
                    100).toFixed(2), "% success, ").concat(successes, " : ").concat(fails));
                // Update validation data indices
                validationDataStartingIndex = validationDataEndingIndex;
                validationDataEndingIndex += partitionSize;
            }
            // Log total results
            console.log("Total: ".concat(((totalSuccesses / (totalSuccesses + totalFails)) * 100).toFixed(2), "% success, ").concat(totalSuccesses, " : ").concat(totalFails));
            return [2 /*return*/];
        });
    });
}
function stratifiedSplit(trainRatio) {
    if (trainRatio === void 0) { trainRatio = 0.8; }
    // Group data by label
    var groupedData = {
        democrat: [],
        republican: [],
    };
    featureVectorToLabelMap.forEach(function (item) { return groupedData[item.label].push(item); });
    var trainData = [];
    var testData = [];
    // Perform stratified split for each class
    for (var _i = 0, _a = Object.keys(groupedData); _i < _a.length; _i++) {
        var label = _a[_i];
        var classData = groupedData[label];
        var splitIndex = Math.floor(classData.length * trainRatio);
        // Shuffle class data before splitting
        var shuffledClassData = __spreadArray([], classData, true).sort(function () { return Math.random() - 0.5; });
        // Assign training and testing data
        trainData.push.apply(trainData, shuffledClassData.slice(0, splitIndex));
        testData.push.apply(testData, shuffledClassData.slice(splitIndex));
    }
    return { trainData: trainData, testData: testData };
}
function trainAndTest() {
    return __awaiter(this, void 0, void 0, function () {
        var _a, trainData, testData, model, trainSuccesses, trainFails, _i, trainData_1, _b, featureVector, label, predictedLabel, shuffledData, partitionSize, foldAccuracies, i, validationData, trainingData, foldModel, foldSuccesses, foldFails, _c, validationData_2, _d, featureVector, label, predictedLabel, foldAccuracy, averageAccuracy, variance, stdDeviation, testSuccesses, testFails, _e, testData_1, _f, featureVector, label, predictedLabel;
        return __generator(this, function (_g) {
            _a = stratifiedSplit(), trainData = _a.trainData, testData = _a.testData;
            model = (0, naiveBayesClassifier_1.trainNaiveBayes)(trainData);
            trainSuccesses = 0;
            trainFails = 0;
            for (_i = 0, trainData_1 = trainData; _i < trainData_1.length; _i++) {
                _b = trainData_1[_i], featureVector = _b.featureVector, label = _b.label;
                predictedLabel = (0, naiveBayesClassifier_1.classifyNaiveBayes)(model, featureVector);
                if (predictedLabel === label) {
                    trainSuccesses++;
                }
                else {
                    trainFails++;
                }
            }
            // Log Train Set Accuracy
            console.log("1. Train Set Accuracy:\n    Accuracy: ".concat(((trainSuccesses / (trainSuccesses + trainFails)) *
                100).toFixed(2), "%"));
            console.log("10-Fold Cross-Validation Results: ");
            shuffledData = __spreadArray([], trainData, true);
            shuffledData.sort(function () { return Math.random() - 0.5; });
            partitionSize = Math.floor(shuffledData.length / 10);
            foldAccuracies = [];
            for (i = 0; i < 10; i++) {
                validationData = shuffledData.slice(i * partitionSize, (i + 1) * partitionSize);
                trainingData = __spreadArray(__spreadArray([], shuffledData.slice(0, i * partitionSize), true), shuffledData.slice((i + 1) * partitionSize), true);
                foldModel = (0, naiveBayesClassifier_1.trainNaiveBayes)(trainingData);
                foldSuccesses = 0;
                foldFails = 0;
                for (_c = 0, validationData_2 = validationData; _c < validationData_2.length; _c++) {
                    _d = validationData_2[_c], featureVector = _d.featureVector, label = _d.label;
                    predictedLabel = (0, naiveBayesClassifier_1.classifyNaiveBayes)(foldModel, featureVector);
                    if (predictedLabel === label) {
                        foldSuccesses++;
                    }
                    else {
                        foldFails++;
                    }
                }
                foldAccuracy = (foldSuccesses / (foldSuccesses + foldFails)) * 100;
                foldAccuracies.push(foldAccuracy);
                console.log("    Accuracy Fold ".concat(i + 1, ": ").concat(foldAccuracy.toFixed(2), "% success, ").concat(foldSuccesses, " : ").concat(foldFails));
            }
            averageAccuracy = foldAccuracies.reduce(function (sum, acc) { return sum + acc; }, 0) / foldAccuracies.length;
            variance = foldAccuracies.reduce(function (sum, acc) { return sum + Math.pow(acc - averageAccuracy, 2); }, 0) / foldAccuracies.length;
            stdDeviation = Math.sqrt(variance);
            console.log("\n    Average Accuracy: ".concat(averageAccuracy.toFixed(2), "%\n    Standard Deviation: ").concat(stdDeviation.toFixed(2), "%\n  "));
            testSuccesses = 0;
            testFails = 0;
            for (_e = 0, testData_1 = testData; _e < testData_1.length; _e++) {
                _f = testData_1[_e], featureVector = _f.featureVector, label = _f.label;
                predictedLabel = (0, naiveBayesClassifier_1.classifyNaiveBayes)(model, featureVector);
                if (predictedLabel === label) {
                    testSuccesses++;
                }
                else {
                    testFails++;
                }
            }
            // Log Test Set Accuracy
            console.log("2. Test Set Accuracy:\n    Accuracy: ".concat(((testSuccesses / (testSuccesses + testFails)) *
                100).toFixed(2), "%"));
            return [2 /*return*/];
        });
    });
}
function main(filePath) {
    return __awaiter(this, void 0, void 0, function () {
        var rl, handleAbstained;
        return __generator(this, function (_a) {
            switch (_a.label) {
                case 0:
                    rl = readline.createInterface({
                        input: process.stdin,
                        output: process.stdout,
                    });
                    return [4 /*yield*/, new Promise(function (resolve) {
                            rl.question("Enter 0 to handle '?' as abstained or 1 to replace it with 'y'/'n': ", function (answer) {
                                rl.close();
                                resolve(answer.trim() === "0");
                            });
                        })];
                case 1:
                    handleAbstained = _a.sent();
                    if (!handleAbstained) return [3 /*break*/, 3];
                    return [4 /*yield*/, readCSVWithAbstained(filePath)];
                case 2:
                    _a.sent();
                    return [3 /*break*/, 5];
                case 3: return [4 /*yield*/, readCSVWithReplacement(filePath)];
                case 4:
                    _a.sent();
                    _a.label = 5;
                case 5: return [4 /*yield*/, trainAndTest()];
                case 6:
                    _a.sent();
                    return [2 /*return*/];
            }
        });
    });
}
main("./house-votes-84.data");
