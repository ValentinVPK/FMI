
#include <iostream>
using namespace std;

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubbleSort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1]) 
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

int main()
{
	int arr[] = { 3,44,38,5,47,15,36,26,27,2,46,4,19,50,48 };
	bubbleSort(arr, 15);
}

