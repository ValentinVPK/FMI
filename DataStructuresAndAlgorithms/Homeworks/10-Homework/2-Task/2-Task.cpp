

#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    int rows, cols;
    cin >> rows >> cols;

    int minutes, infected;
    cin >> minutes >> infected;

    vector<vector<int>> cinema(rows, vector<int>(cols, 0));
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    
    int row, col;
    queue<pair<pair<int,int>, int>> infectedPlaces;
    for (size_t i = 0; i < infected; i++)
    {
        cin >> row >> col;
        cinema[row - 1][col - 1] = 1;
        infectedPlaces.push({ { row - 1, col - 1 }, minutes });
        visited[row - 1][col - 1] = true;
    }


    while (!infectedPlaces.empty()) 
    {
        pair<pair<int, int>, int> currInfected = infectedPlaces.front();
        infectedPlaces.pop();

        int currRow = currInfected.first.first;
        int currCol = currInfected.first.second;
        int currTime = currInfected.second;

        if (currRow - 1 >= 0 && currTime > 0 && !visited[currRow - 1][currCol]) 
        {
            cinema[currRow - 1][currCol] = 1;
            infectedPlaces.push({ { currRow - 1, currCol }, currTime - 1 });
        }

        if (currRow + 1 < rows && currTime > 0 && !visited[currRow + 1][currCol])
        {
            cinema[currRow + 1][currCol] = 1;
            infectedPlaces.push({ { currRow + 1, currCol }, currTime - 1 });
        }

        if (currCol - 1 >= 0 && currTime > 0 && !visited[currRow][currCol - 1])
        {
            cinema[currRow][currCol - 1] = 1;
            infectedPlaces.push({ { currRow, currCol - 1 }, currTime - 1 });
        }

        if (currCol + 1 < cols && currTime > 0 && !visited[currRow][currCol + 1])
        {
            cinema[currRow][currCol + 1] = 1;
            infectedPlaces.push({ { currRow, currCol + 1 }, currTime - 1});
        }
    }

    int count = 0;

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            if (cinema[i][j] == 0)
            {
                count++;
            }
        }
    }

    cout << count;


    return 0;
}


