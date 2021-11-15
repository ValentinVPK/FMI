
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;


struct Node {
    int data;
    Node* prev;
    Node* next;

    Node() 
    {
        data = 0;
        prev = nullptr;
        next = nullptr;
    }

    Node(int valueData) 
    {
        data = valueData;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* first;
    Node* last;
    Node* mid;
    bool isMidCorrect;
public:
    DoublyLinkedList()
    {
        first = nullptr;
        last = nullptr;
        mid = nullptr;
        isMidCorrect = false;
    }

    void insertEnd(int dataValue) {

        Node* newElement = new Node(dataValue);
        if (first == nullptr)
        {
            first = newElement;
            last = newElement;
            mid = newElement;
            return;
        }

        last->next = newElement;
        newElement->prev = last;
        last = newElement;

        if (isMidCorrect == false)
        {
            isMidCorrect = true;
        }
        else
        {
            isMidCorrect = false;
        }

        if (isMidCorrect == false)
        {
            mid = mid->next;
        }
    }

    void deleteEnd() 
    {
        if (first->next == nullptr)
        {

            first = nullptr;
            last = nullptr;
            mid = nullptr;
            return;
        }

        last = last->prev;
        last->next = nullptr;

        if (isMidCorrect == false)
        {
            mid = mid->prev;
        }

        if (isMidCorrect == false)
        {
            isMidCorrect = true;
        }
        else
        {
            isMidCorrect = false;
        }
    }

    void milenFunc()
    {
      

        if (first->next == nullptr)
        {
            return;
        }

        if (first->next->next == nullptr)
        {
            first->prev = last;
            last->next = first;
            first = last;
            last = mid;
            mid = first;
            first->prev = nullptr;
            last->next = nullptr;
            return;
        }

        if (isMidCorrect == false)
        {
            first->prev = last;
            last->next = first;
            first = mid;
            mid = last;
            last = first->prev;
            first->prev = nullptr;
            last->next = nullptr;
            
        }
        else
        {
            first->prev = last;
            last->next = first;
            first = mid->next;
            mid = last;
            last = first->prev;
            first->prev = nullptr;
            last->next = nullptr;        
        }
    }

    void print(string sep) {
        while (first) {
            cout << first->data;

            first = first->next;

            if (first) {
                cout << sep;
            }
        }
    }
};



int main()
{
    DoublyLinkedList* gunsList = new DoublyLinkedList();
    int size = 0;
    int querries;
    cin >> querries;

    for (int i = 0; i < querries; i++)
    {
        string command;
        int number;

        cin >> command;

        if (command == "add")
        {
            cin >> number;
            gunsList->insertEnd(number);
            size++;
        }
        else if (command == "gun")
        {
            gunsList->deleteEnd();
            size--;
        }
        else if (command == "milen")
        {
            gunsList->milenFunc();
        }
    }

    cout << size << endl;

    gunsList->print(" ");

    return 0;
}

