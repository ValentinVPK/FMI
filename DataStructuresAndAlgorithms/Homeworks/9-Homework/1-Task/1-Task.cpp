
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> keysInput(N);
    //vector<int> doorsInput(N);

    int currKey;
    for (size_t i = 0; i < N; i++)
    {
        cin >> currKey;
        keysInput[i] = currKey;
    }

    int brokenDoors = 0;
    unordered_map<int, size_t> keysAvailable;
    int currDoor;
    for (size_t i = 0; i < N; i++)
    {
        if (keysAvailable.count(keysInput[i])) 
        {
            keysAvailable[keysInput[i]]++;
        }
        else
        {
            keysAvailable.insert({ keysInput[i] , 1 });
        }

        cin >> currDoor;

        if (keysAvailable.count(currDoor) && keysAvailable[currDoor] > 0)
        {
            keysAvailable[currDoor]--;
        }
        else
        {
            brokenDoors++;
        }
    }

    cout << brokenDoors;

    return 0;
}

