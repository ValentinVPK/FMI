
#include <iostream>
using namespace std;

class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedList {
public:
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;

    SinglyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int node_data) {
        SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

        if (!this->head) {
            this->head = node;
        }
        else {
            this->tail->next = node;
        }

        this->tail = node;
    }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep) {
    while (node) {
        cout << node->data;

        node = node->next;

        if (node) {
            cout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

SinglyLinkedListNode* pushInFront(SinglyLinkedListNode* llist, int data)
{
    SinglyLinkedListNode* newNodeHead = new SinglyLinkedListNode(data);
    newNodeHead->next = llist;
    llist = newNodeHead;

    return llist;
}

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    //if position is wrong this func returns the head node llist
    if (position == 0)
    {
        return pushInFront(llist, data);
    }

    if (llist == nullptr)
    {
        return llist;
    }

    SinglyLinkedListNode* currNode = llist;
    SinglyLinkedListNode* prevNode = nullptr;
    
    for (int i = 0; i < position; i++)
    {
        if (currNode == nullptr)
        {
            return llist;
        }

        prevNode = currNode;
        currNode = currNode->next;
    }

    SinglyLinkedListNode* nodeToBeInserted = new SinglyLinkedListNode(data);
    nodeToBeInserted->next = currNode;

    prevNode->next = nodeToBeInserted;

    return llist;

}
int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();

    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        llist->insert_node(llist_item);
    }

    int data;
    cin >> data;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int position;
    cin >> position;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    SinglyLinkedListNode* llist_head = insertNodeAtPosition(llist->head, data, position);

    print_singly_linked_list(llist_head, " ");
    cout << "\n";

    free_singly_linked_list(llist_head);

    return 0;
}

