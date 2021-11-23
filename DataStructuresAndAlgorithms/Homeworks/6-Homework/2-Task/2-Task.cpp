
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
using namespace std;

struct TreeNode {
    int index;
    int x;
    int y;
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int index, int x, int y)
    {
        this->index = index;
        this->x = x;
        this->y = y;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
    }
};

void findAndPrintTopView(TreeNode* root)
{
    queue<TreeNode*> queueOfNodes;
    map<int, int> resultMap;

    queueOfNodes.push(root);

    while (!queueOfNodes.empty())
    {
        root = queueOfNodes.front();
        queueOfNodes.pop();
        int currX = root->x;

        if (resultMap.count(currX) == 0)
        {
            resultMap[currX] = root->index;
        }

        if (root->left)
        {
            queueOfNodes.push(root->left);
        }
        if (root->right)
        {
            queueOfNodes.push(root->right);
        }
    }

    for (auto i = resultMap.begin(); i != resultMap.end(); i++) {
        cout << i->second << " ";
    }
}



int main()
{
    int N;
    cin >> N;

    TreeNode* root = new TreeNode(0, 0, 0);

    vector<TreeNode*> vec(N);
    vec[0] = root;
    for (int i = 0; i < N; i++)
    {
        int leftIndex, rightIndex;
        cin >> leftIndex >> rightIndex;

        if (leftIndex != -1)
        {
            TreeNode* newNode = new TreeNode(leftIndex, vec[i]->x - 1, vec[i]->y - 1);
            vec[i]->left = newNode;
            newNode->parent = vec[i];
            vec[leftIndex] = newNode;
        }
        else
        {
            vec[i]->left = nullptr;
        }

        if (rightIndex != -1)
        {
            TreeNode* newNode = new TreeNode(rightIndex, vec[i]->x + 1, vec[i]->y - 1);
            vec[i]->right = newNode;
            newNode->parent = vec[i];
            vec[rightIndex] = newNode;
        }
        else
        {
            vec[i]->right = nullptr;
        }
    }

    findAndPrintTopView(root);

    return 0;
}


