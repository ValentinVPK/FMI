
#include <iostream>
using namespace std;

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void selectionSort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++)
	{
		int indexMin = i;

		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[indexMin]) 
			{
				indexMin = j;
			}
		}

		if (indexMin != i) 
		{
			swap(&arr[i], &arr[indexMin]);
		}
	}
}

int main()
{
	int arr[] = { 3,44,38,5,47,15,36,26,27,2,46,4,19,50,48 };
	selectionSort(arr, 15);
}

