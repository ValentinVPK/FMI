

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

int getElementsCount(SinglyLinkedListNode* head)
{
    SinglyLinkedListNode* tempNode = head;
    int result = 0;

    while (true)
    {
        if (tempNode == nullptr)
        {
            break;
        }

        result++;
        tempNode = tempNode->next;
    }

    return result;
}

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

    SinglyLinkedListNode* tempNode1 = head1;
    SinglyLinkedListNode* tempNode2 = head2;

    int elementsCount1 = getElementsCount(head1);
    int elementsCount2 = getElementsCount(head2);

    if (elementsCount1 > elementsCount2)
    {
        int diff = elementsCount1 - elementsCount2;
        for (int i = 0; i < diff; i++)
        {
            if (tempNode1 == nullptr)
            {
                break;
            }

            tempNode1 = tempNode1->next;
        }
    }
    else
    {
        int diff = elementsCount2 - elementsCount1;
        for (int i = 0; i < diff; i++)
        {
            if (tempNode2 == nullptr)
            {
                break;
            }

            tempNode2 = tempNode2->next;
        }
    }

    while (true)
    {
        if (tempNode1 == tempNode2)
        {
            return tempNode1->data;
        }

        tempNode1 = tempNode1->next;
        tempNode2 = tempNode2->next;
    }

    return 0;
}


int main()
{
    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        int index;
        cin >> index;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        SinglyLinkedList* llist1 = new SinglyLinkedList();

        int llist1_count;
        cin >> llist1_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist1_count; i++) {
            int llist1_item;
            cin >> llist1_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist1->insert_node(llist1_item);
        }

        SinglyLinkedList* llist2 = new SinglyLinkedList();

        int llist2_count;
        cin >> llist2_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist2_count; i++) {
            int llist2_item;
            cin >> llist2_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist2->insert_node(llist2_item);
        }

        SinglyLinkedListNode* ptr1 = llist1->head;
        SinglyLinkedListNode* ptr2 = llist2->head;

        for (int i = 0; i < llist1_count; i++) {
            if (i < index) {
                ptr1 = ptr1->next;
            }
        }

        for (int i = 0; i < llist2_count; i++) {
            if (i != llist2_count - 1) {
                ptr2 = ptr2->next;
            }
        }

        ptr2->next = ptr1;

        int result = findMergeNode(llist1->head, llist2->head);

        cout << result << "\n";
    }


    return 0;
}

