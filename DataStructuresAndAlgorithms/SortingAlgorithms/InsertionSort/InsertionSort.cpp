
#include <iostream>
using namespace std;

void insertionSort(int arr[], int size) {
	for (int i = 1; i < size; i++)
	{
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key) 
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}

		arr[j + 1] = key;
	}
}

int main()
{
	int arr[] = { 3,44,38,5,47,15,36,26,27,2,46,4,19,50,48 };
	insertionSort(arr, 15);
}

