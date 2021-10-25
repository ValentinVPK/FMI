
#include <iostream>
#include <vector>
using namespace std;


void merge(vector<int>& vec, int left, int mid, int right) {
    vector<int> leftVec;
    vector<int> rightVec;

    for (int i = left; i <= mid; i++) {
        leftVec.push_back(vec[i]);
    }

    for (int i = mid + 1; i <= right; i++) {
        rightVec.push_back(vec[i]);
    }

    int i = 0;
    int j = 0;

    int index = left;
    while (i < leftVec.size() && j < rightVec.size()) {
        if (leftVec[i] < rightVec[j]) {
            vec[index++] = leftVec[i++];
        }
        else {
            vec[index++] = rightVec[j++];
        }
    }

    while (i < leftVec.size()) {
        vec[index++] = leftVec[i++];
    }

    while (j < rightVec.size()) {
        vec[index++] = rightVec[j++];
    }
}

void mergeSort(vector<int>& vec, int left, int right) {
    if (right - left <= 0) {
        return;
    }

    int mid = (left + right) / 2;

    mergeSort(vec, left, mid);
    mergeSort(vec, mid + 1, right);

    merge(vec, left, mid, right);
}

int main()
{
    int arrSize;
    cin >> arrSize;

    vector<int> vec;

    for (int i = 0; i < arrSize; i++)
    {
        int currNum;
        cin >> currNum;

        vec.push_back(currNum);
    }

    mergeSort(vec, 0, vec.size() - 1);

    vector<int> resultVector;
    int currNumber = -1;
    for (int i = 0; i < arrSize; i++)
    {
        if (currNumber != vec[i]) {
            cout << vec[i] << " ";
            currNumber = vec[i];
        }
    }

    return 0;
}

