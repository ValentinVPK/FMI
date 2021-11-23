#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* leftNode;
    Node* rightNode;
    Node(int d) {
        data = d;
        leftNode = NULL;
        rightNode = NULL;
    }
};

class Solution {
public:
    Node* insert(Node* root, int data) {
        if (root == NULL) {
            return new Node(data);
        }
        else {
            Node* cur;
            if (data <= root->data) {
                cur = insert(root->leftNode, data);
                root->leftNode = cur;
            }
            else {
                cur = insert(root->rightNode, data);
                root->rightNode = cur;
            }

            return root;
        }
    }


    void leaves(Node* root) {
        cout << sumOfLeaves(root);
    }

    int sumOfLeaves(Node* root)
    {
        int sum = 0;
        if (root->leftNode == nullptr && root->rightNode == nullptr && root->data % 2 == 1)
        {
            sum += root->data;
        }

        if (root->leftNode)
        {
            sum += sumOfLeaves(root->leftNode);
        }

        if (root->rightNode)
        {
            sum += sumOfLeaves(root->rightNode);
        }

        return sum;
    }

}; //End of Solution

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.leaves(root);
    return 0;
}