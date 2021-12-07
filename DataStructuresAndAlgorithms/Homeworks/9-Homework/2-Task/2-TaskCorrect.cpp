
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
    //4 3
    // 1 3 3 9
    //(0, 1, 3), (0, 2, 3) - answer
    int N, K;
    cin >> N >> K;


    vector<size_t> animalWeights(N);

    int currWeight;
    for (size_t i = 0; i < N; i++)
    {
        cin >> currWeight;
        animalWeights[i] = currWeight;

    }

    long result = 0;


    //4 3
    // 1 3 3 9
    //(0, 1, 3), (0, 2, 3) - answer
    unordered_map<int, long> lefts;
    unordered_map<int, long> rights;
    for (size_t i = 0; i < N; i++) 
    {
        if (!rights.count(animalWeights[i])) 
        {
            rights[animalWeights[i]] = 1;
        }
        else 
        {
            rights[animalWeights[i]]++;
        }
    }

    for (size_t i = 0; i < N; i++) {
        rights[animalWeights[i]]--;

        if (animalWeights[i] % K == 0 && lefts.count(animalWeights[i] / K)
            && rights.count(animalWeights[i] * K))
        {
            result += lefts[animalWeights[i] / K] * rights[animalWeights[i] * K];
        }

        if (!lefts.count(animalWeights[i])) 
        {
            lefts[animalWeights[i]] = 1;    
        }
        else 
        {
            lefts[animalWeights[i]]++;
        }
    }

    cout << result;

    return 0;
}

