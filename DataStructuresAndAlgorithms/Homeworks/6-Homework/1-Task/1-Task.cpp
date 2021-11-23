
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1000002;
vector<vector<int>> bossesAndCount(N);

void workersCount(int boss)
{
    int currCount = 0;
    queue<int> tempQueue;

    tempQueue.push(boss);

    while (tempQueue.empty() == false)
    {
        int current = tempQueue.front();
        tempQueue.pop();

        currCount += bossesAndCount[current].size();

        for (auto worker : bossesAndCount[current])
        {
            tempQueue.push(worker);
        }
    }

   
    cout << currCount << " ";
}


int main()
{
    int numOfNodes;
    cin >> numOfNodes;

    for (int i = 1; i <= numOfNodes - 1; i++)
    {
        int boss, worker;
        cin >> boss >> worker;

        bossesAndCount[boss].push_back(worker);
    }
    

    for (size_t i = 0; i < numOfNodes; i++)
    {
        workersCount(i);
    }

    return 0;
}


