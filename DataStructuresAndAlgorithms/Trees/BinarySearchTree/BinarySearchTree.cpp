
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

TreeNode* search(TreeNode* root, int data)
{
    // Base Cases: root is null or key is present at root
    if (root == nullptr || root->data == data)
        return root;

    // Key is greater than root's key
    if (root->data > data)
    {
        return search(root->left, data);
    }
       
    

    // Key is smaller than root's key
    return search(root->right, data);
}

TreeNode* insertNewElement(TreeNode* root, int data)
{
    if (!root)
    {
        // Insert the first node, if root is NULL.
        return new TreeNode(data);
    }

    // Insert data.
    if (data > root->data)
    {
        // Insert right node data, if the 'value'
        // to be inserted is greater than 'root' node data.

        // Process right nodes.
        root->right = insertNewElement(root->right, data);
    }
    else
    {
        // Insert left node data, if the 'value'
        // to be inserted is greater than 'root' node data.

        // Process left nodes.
        root->left = insertNewElement(root->left, data);
    }

    // Return 'root' node, after insertion.
    return root;
}

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


// Traversals
void levelOrderTraversal(TreeNode* root)
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


void inorderTraversalAscending(TreeNode* root)
{
    if (root->left)
    {
        inorderTraversalAscending(root->left);
    }

    cout << root->data << " ";

    if (root->right)
    {
        inorderTraversalAscending(root->right);
    }
}

void inorderTraversalDescending(TreeNode* root)
{
    if (root->right)
    {
        inorderTraversalDescending(root->right);
    }

    cout << root->data << " ";

    if (root->left)
    {
        inorderTraversalDescending(root->left);
    }
}

void preorderTraversalFirst(TreeNode* root)
{
    cout << root->data << " ";

    if (root->left)
    {
        preorderTraversalFirst(root->left);
    }

    if (root->right)
    {
        preorderTraversalFirst(root->right);
    }
}

void preorderTraversalSecond(TreeNode* root)
{
    cout << root->data << " ";

    if (root->right)
    {
        preorderTraversalFirst(root->right);
    }

    if (root->left)
    {
        preorderTraversalFirst(root->left);
    }
}

void postOrderFirst(TreeNode* root)
{
    if (root->left)
    {
        preorderTraversalFirst(root->left);
    }

    if (root->right)
    {
        preorderTraversalFirst(root->right);
    }

    cout << root->data << " ";
}

void postOrderSecond(TreeNode* root)
{
    if (root->right)
    {
        preorderTraversalFirst(root->right);
    }

    if (root->left)
    {
        preorderTraversalFirst(root->left);
    }

    cout << root->data << " ";
}

int main()
{
    TreeNode* root = nullptr;
    root = insertNewElement(root, 50);
    insertNewElement(root, 30);
    insertNewElement(root, 20);
    insertNewElement(root, 40);
    insertNewElement(root, 70);
    insertNewElement(root, 60);
    insertNewElement(root, 80);

    //inorderTraversalDescending(root);
}
