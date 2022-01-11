#include <vector>
#include <iostream>
using namespace std;

const int N = 10000;
int degree[N];
int numberOfEdges = 0, numberOfVertices = 0;
vector<string> ans;

int main() {

    int from = 0, to = 0;
    int q = 0;
    cin >> q;

    while (q--) {

        int numberOfOddDegree = 0;
        cin >> numberOfVertices >> numberOfEdges;

        for (int i = 0; i < N; i++)
        {
            degree[i] = 0;
        }

        while (numberOfEdges)
        {
            cin >> from >> to;
            degree[to]++;
            degree[from]++;
            numberOfEdges--;
        }

        for (int i = 0; i < N; i++)
        {

            if (degree[i] % 2 != 0)  numberOfOddDegree++;

        }

        if (numberOfOddDegree == 0) ans.push_back("ecycle\n");
        else if (numberOfOddDegree == 0 || numberOfOddDegree == 2) ans.push_back("epath\n");
        else ans.push_back("none\n");
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
    }

    return 0;
}
