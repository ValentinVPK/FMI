
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void findKLargest(TreeNode* root, int K, int& counter, int& result)
{
    if (root == nullptr || counter >= K)
    {
        return;
    }

    findKLargest(root->right, K, counter, result);

    if (++counter == K)
    {
        result = root->data;
        return;
    }


    findKLargest(root->left, K, counter, result);
}

TreeNode* minValueNode(TreeNode* node)
{
    TreeNode* current = node;

    while (current != nullptr && current->left != nullptr)
    {
        current = current->left;
    }

    return current;
}


TreeNode* deleteNode(TreeNode* root, int data)
{
    if (root == nullptr)
    {
        return root;
    }


    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else 
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            return nullptr;
        }
        else if (root->left == nullptr) 
        {
            TreeNode* tempNode = root->right;
            return tempNode;
        }
        else if (root->right == nullptr) 
        {
            TreeNode* tempNode = root->left;
            return tempNode;
        }


        TreeNode* tempNode = minValueNode(root->right);

        root->data = tempNode->data;

        root->right = deleteNode(root->right, tempNode->data);
    }

    return root;
}

void printAllLevels(TreeNode* root)
{
    if (root == nullptr)
    {
        return;
    }

    queue<TreeNode*> queueOfNodes;

    queueOfNodes.push(root);

    while (!queueOfNodes.empty())
    {
        TreeNode* curr = queueOfNodes.front();
        cout << curr->data << " ";
        queueOfNodes.pop();

        if (curr->left)
        {
            queueOfNodes.push(curr->left);
        }

        if (curr->right)
        {
            queueOfNodes.push(curr->right);
        }
    }
}

int main()
{
    int N, K;
    cin >> N >> K;

    vector<TreeNode*> nodes;
	for (size_t i = 0; i < N; i++)
	{
		int num;
		cin >> num;

        TreeNode* currNode = new TreeNode(num);

        if (i == 0)
        {
            nodes.push_back(currNode);
            continue;
        }

        if (!nodes[(i - 1) / 2]->left)
        {
            nodes[(i - 1) / 2]->left = currNode;
            nodes.push_back(currNode);
            continue;
        }

        if (!nodes[(i - 1) / 2]->right)
        {
            nodes[(i - 1) / 2]->right = currNode;
            nodes.push_back(currNode);
        }
	}

    int counter = 0;
    int result = 0;
    findKLargest(nodes[0], K, counter, result);

    deleteNode(nodes[0], result);

    printAllLevels(nodes[0]);
    return 0;
}


