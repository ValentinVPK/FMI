
#include <iostream>
using namespace std;

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int arr[], int left, int right) {
    int storedIndex = left + 1;
    int piv = arr[left];            //make the first element as pivot element.
    for (int j = left + 1; j <= right; j++) {
        /*rearrange the array by putting elements which are less than pivot
           on one side and which are greater that on other. */

        if (arr[j] < piv) {
            swap(arr[storedIndex], arr[j]);
            storedIndex += 1;
        }
    }
    swap(&arr[left], &arr[storedIndex - 1]);  //put the pivot element in its proper place.
    return storedIndex - 1;                      //return the position of the pivot
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
    int arr[] = { 3,44,38,5,47,15,36,26,27,2,46,4,19,50,48 };
    auto arrSize = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, arrSize - 1);
}
