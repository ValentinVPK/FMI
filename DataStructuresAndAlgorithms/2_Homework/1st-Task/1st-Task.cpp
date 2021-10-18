
#include <iostream>
#include <vector>
using namespace std;


void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int arr[], int left, int right) {
    int storedIndex = left + 1;
    int pivot = arr[left];
    for (int j = left + 1; j <= right; j++)
    {
        if (arr[j] < pivot)
        {
            swap(arr[storedIndex], arr[j]);
            storedIndex += 1;
        }
    }
    swap(&arr[left], &arr[storedIndex - 1]);
    return storedIndex - 1;
}

void quickSort(int arr[], int left, int right) {
    if (left < right)
    {
        int pivotPosition = partition(arr, left, right);
        quickSort(arr, left, pivotPosition);
        quickSort(arr, pivotPosition + 1, right);
    }
}
int main()
{
    int presentsCount;
    cin >> presentsCount;

    int* presents = new int[presentsCount];

    for (int i = 0; i < presentsCount; i++)
    {
        cin >> presents[i];
    }

    quickSort(presents, 0, presentsCount - 1);

    int employeesCount;
    cin >> employeesCount;
    long int totalCost = 0;

    for (int i = 0; i < employeesCount; i++)
    {
        totalCost += presents[i];
    }

    cout << totalCost;

    return 0;
}

