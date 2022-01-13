
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <list>
using namespace std;

class Graph
{
public:
    int N;
    list<int>* adjList;
    vector<int> degreeVec;

    Graph(int N)
    {
        this->N = N;
        adjList = new list<int>[N];
        for (size_t i = 0; i < N; i++)
        {
            degreeVec.push_back(0);
        }   
    }
    void addEdge(int fromNode, int toNode)
    {
        degreeVec[fromNode]++;
        degreeVec[toNode]++;
        adjList[fromNode].push_back(toNode);
        adjList[toNode].push_back(fromNode);
    }

    vector<int> rootForMinimumHeight()
    {
        queue<int> myQueue;

        for (size_t i = 0; i < N; i++)
        {
            if (degreeVec[i] == 1)
            {
                myQueue.push(i);
            }
        }
            
        while (N > 2)
        {
            int leavingElementCount = myQueue.size();
            N -= leavingElementCount;      

            for (size_t i = 0; i < leavingElementCount; i++)
            {
                int currNode = myQueue.front();
                myQueue.pop();

                for (auto j = adjList[currNode].begin(); j != adjList[currNode].end(); j++)
                {
                    degreeVec[*j]--;
                    if (degreeVec[*j] == 1)
                    {
                        myQueue.push(*j);
                    }              
                }
            }
        }

        vector<int> resultVec;
        while (!myQueue.empty())
        {
            resultVec.push_back(myQueue.front());
            myQueue.pop();
        }
        return resultVec;
    }
};




int main()
{
    int numberOfNodes;
    cin >> numberOfNodes;
    Graph myGraph(numberOfNodes);

    int fromNode, toNode;
    for (size_t i = 0; i < numberOfNodes - 1; i++)
    {
        cin >> fromNode >> toNode;

        myGraph.addEdge(fromNode, toNode);
    }

    vector<int> resultVec = myGraph.rootForMinimumHeight();

    for (size_t i = 0; i < resultVec.size(); i++)
    {
        cout << resultVec[i] << " ";
    }
    
    return 0;
}


