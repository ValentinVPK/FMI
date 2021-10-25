
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;


int binaryFindIndex(vector<int>& vec, int number)
{
    int l = 0;
    int r = vec.size() - 1;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (vec[mid] == number)
        {
            for (int i = mid + 1; i < (int)vec.size(); i++)
            {
                if (vec[i] == number)
                {
                    mid = i;
                }
                else 
                {
                    break;
                }
            }
            return mid;
        }
        else if (vec[mid] < number)
            l = mid + 1;

        else
            r = mid - 1;
    }

    return r;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;

    cin >> N >> Q;

    vector<int> numbers;

    for (int i = 0; i < N; i++)
    {
        int currNumber;
        cin >> currNumber;

        numbers.push_back(currNumber);
    }

    sort(numbers.begin(), numbers.end());

    vector<int> results;
    for (int i = 0; i < Q; i++)
    {
        int S, P;
        cin >> S >> P;

        int indexOfP = binaryFindIndex(numbers, P);

        long currCount = 0;
        long currSum = 0;
        
        
        for (int j = indexOfP; j >= 0 ; j-= 10)
        {
            if (j - 10 < 0)
            {
                for (int h = j; h >= 0; h--)
                {
                    currSum += numbers[h];
                    if (currSum > S)
                    {
                        break;
                    }

                    currCount++;
                }
                break;
            }

            currSum += numbers[j];
            currSum += numbers[j - 1];
            currSum += numbers[j - 2];
            currSum += numbers[j - 3];
            currSum += numbers[j - 4];
            currSum += numbers[j - 5];
            currSum += numbers[j - 6];
            currSum += numbers[j - 7];
            currSum += numbers[j - 8];
            currSum += numbers[j - 9];
            currCount += 10;

            if (currSum > S)
            {
                for (int h = j - 10 + 1; h <= j; h++)
                {
                    currSum -= numbers[h];
                    if (currSum <= S)
                    {
                        currCount--;
                        break;
                    }
                    currCount--;
                }

                break;
            }
        }

        printf("%d\n", currCount);
    }

    return 0;
}
