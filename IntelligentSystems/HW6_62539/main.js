"use strict";
var __assign = (this && this.__assign) || function () {
    __assign = Object.assign || function(t) {
        for (var s, i = 1, n = arguments.length; i < n; i++) {
            s = arguments[i];
            for (var p in s) if (Object.prototype.hasOwnProperty.call(s, p))
                t[p] = s[p];
        }
        return t;
    };
    return __assign.apply(this, arguments);
};
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
exports.parseCSV = parseCSV;
exports.preprocessData = preprocessData;
exports.stratifiedSplit = stratifiedSplit;
var readline = require("readline");
var fs = require("fs");
var decisionTree_1 = require("./decisionTree");
var filePath = "./breast-cancer.data";
// Function to parse CSV data
function parseCSV(filePath) {
    return __awaiter(this, void 0, void 0, function () {
        var data, fileStream, rl, _a, rl_1, rl_1_1, line, e_1_1;
        var _b, e_1, _c, _d;
        return __generator(this, function (_e) {
            switch (_e.label) {
                case 0:
                    data = [];
                    fileStream = fs.createReadStream(filePath);
                    rl = readline.createInterface({
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
                    if (line.trim()) {
                        data.push(line.split(",").map(function (value) { return value.trim(); })); // Trim whitespace
                    }
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
                case 12: return [2 /*return*/, data];
            }
        });
    });
}
// Replace missing values in data
function preprocessData(rawData) {
    var featureCounts = {}; // Track counts for each feature value
    var data = [];
    rawData.forEach(function (row) {
        var label = row[0]; // First column is the label
        var features = row.slice(1); // Remaining columns are features
        // Update feature frequency counts
        features.forEach(function (value, index) {
            if (!featureCounts[index]) {
                featureCounts[index] = {};
            }
            if (value !== "?") {
                featureCounts[index][value] = (featureCounts[index][value] || 0) + 1;
            }
        });
        // Store data point
        data.push({ features: features, label: label });
    });
    // Replace missing values with the most frequent value in each column
    var processedData = data.map(function (point) {
        var newFeatures = point.features.map(function (value, index) {
            if (value === "?") {
                var mostFrequent = Object.entries(featureCounts[index]).reduce(function (a, b) { return (a[1] > b[1] ? a : b); })[0]; // Find most frequent value
                return mostFrequent;
            }
            return value; // Keep existing value
        });
        return __assign(__assign({}, point), { features: newFeatures });
    });
    return { data: processedData, featureCounts: featureCounts };
}
// Perform stratified split
function stratifiedSplit(data, trainRatio) {
    if (trainRatio === void 0) { trainRatio = 0.8; }
    // Group data by label
    var groupedData = {
        "no-recurrence-events": [],
        "recurrence-events": [],
    };
    data.forEach(function (point) { return groupedData[point.label].push(point); });
    var trainData = [];
    var testData = [];
    // Split each group maintaining proportions
    for (var label in groupedData) {
        var classData = groupedData[label];
        var splitIndex = Math.floor(classData.length * trainRatio);
        // Shuffle data before splitting
        var shuffledData = __spreadArray([], classData, true).sort(function () { return Math.random() - 0.5; });
        trainData.push.apply(trainData, shuffledData.slice(0, splitIndex));
        testData.push.apply(testData, shuffledData.slice(splitIndex));
    }
    return { trainData: trainData, testData: testData };
}
function main() {
    return __awaiter(this, void 0, void 0, function () {
        var rawData, data, _a, trainData, testData, attributes, tree, correct;
        return __generator(this, function (_b) {
            switch (_b.label) {
                case 0: return [4 /*yield*/, parseCSV(filePath)];
                case 1:
                    rawData = _b.sent();
                    data = preprocessData(rawData).data;
                    _a = stratifiedSplit(data), trainData = _a.trainData, testData = _a.testData;
                    attributes = Array.from(Array(trainData[0].features.length).keys());
                    tree = (0, decisionTree_1.buildDecisionTree)(trainData, attributes);
                    correct = 0;
                    testData.forEach(function (point) {
                        var prediction = (0, decisionTree_1.classify)(tree, point);
                        if (prediction === point.label)
                            correct++;
                    });
                    console.log("Test Set Accuracy: ".concat((correct / testData.length) * 100, "%"));
                    return [2 /*return*/];
            }
        });
    });
}
main();
