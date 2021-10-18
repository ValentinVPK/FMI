
#include <iostream>
using namespace std;

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int arr[], int left, int mid, int right)
{
    int leftArrLength = mid - left + 1;
    int rightArrLength = right - mid;

    // Create temp arrays
    int* leftArr = new int[leftArrLength],
        * rightArr = new int[rightArrLength];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < leftArrLength; i++)
        leftArr[i] = arr[left + i];
    for (auto j = 0; j < rightArrLength; j++)
        rightArr[j] = arr[mid + 1 + j];

    int leftArrIndex = 0, // Initial index of first sub-array
        rightArrIndex = 0; // Initial index of second sub-array
    int mergedArrIndex = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (leftArrIndex < leftArrLength && rightArrIndex < rightArrLength) {
        if (leftArr[leftArrIndex] <= rightArr[rightArrIndex]) {
            arr[mergedArrIndex] = leftArr[leftArrIndex];
            leftArrIndex++;
        }
        else {
            arr[mergedArrIndex] = rightArr[rightArrIndex];
            rightArrIndex++;
        }
        mergedArrIndex++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (leftArrIndex < leftArrLength) {
        arr[mergedArrIndex] = leftArr[leftArrIndex];
        leftArrIndex++;
        mergedArrIndex++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (rightArrIndex < rightArrLength) {
        arr[mergedArrIndex] = rightArr[rightArrIndex];
        rightArrIndex++;
        mergedArrIndex++;
    }
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int array[], int left, int right)
{
    if (left >= right)
        return; // Returns recursively

    int mid = left + (right - left) / 2;
    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);
    merge(array, left, mid, right);
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int arr[], int size)
{
    for (auto i = 0; i < size; i++)
        cout << arr[i] << " ";
}

// Driver code
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    auto arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}


