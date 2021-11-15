
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

SinglyLinkedListNode* deleteFirstElement(SinglyLinkedListNode* llist)
{
    SinglyLinkedListNode* tempNode = llist;

    if (llist != nullptr)
    {
        llist = llist->next;
        delete tempNode;
    }

    return llist;
}

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
    if (llist->next == nullptr)
    {
        return nullptr;
    }

    if (position == 0)
    {
        return deleteFirstElement(llist);
    }

    if (llist == nullptr)
    {
        return nullptr;
    }

    SinglyLinkedListNode* currNode = llist;
    SinglyLinkedListNode* prevNode = nullptr;

    for (int i = 0; i < position; i++)
    {
        if (currNode->next != nullptr)
        {
            prevNode = currNode;
            currNode = currNode->next;
        }
        else
        {
            return nullptr;
        }
    }

    prevNode->next = currNode->next;

    delete currNode;

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

    int position;
    cin >> position;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    SinglyLinkedListNode* llist1 = deleteNode(llist->head, position);

    print_singly_linked_list(llist1, " ");
    cout << "\n";

    free_singly_linked_list(llist1);


    return 0;
}

