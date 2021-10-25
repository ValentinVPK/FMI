
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long allPoints;
    cin >> allPoints;

    long presentsCount = 0;
    while (allPoints > 0) 
    {
        long currNumber = 1;
        while (true) 
        {
            long currCube = currNumber * currNumber * currNumber;
            if (currCube > allPoints)
            {
                currNumber--;
                break;
            }

            currNumber++;
        }

        presentsCount++;
        allPoints -= currNumber * currNumber * currNumber;
    }

    cout << presentsCount;

    return 0;
}


