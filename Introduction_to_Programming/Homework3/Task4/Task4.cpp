
#include <iostream>
using namespace std;

int charArrayLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    return length;
}
int repetaingChars(char str[], int length) {
    int count = 0;
    for (size_t i = 0; i < length; i++) {
        for (size_t j = i + 1; j < length; j++) {
            if (str[i] == str[j]) {
                count++;
                break;
            }
        }
    }

    return count;
}
bool onlyLetters(char str[], int length) {
    for (size_t i = 0; i < length; i++) {
        if (str[i] < 'a' || str[i] > 'z') {
            return false;
        }
    }

    return true;
}
int countStrings(char str[], int length, int exclusion){

    if (exclusion == 0) return 1;

    int count = 0;
    int currentSubstringLength = length - exclusion;
    for (size_t i = 0;i < length; i++) {
        while (currentSubstringLength > 0) {
            for (size_t j = 0; j < length; j++) {
                count++;
                if (j == i) continue;
                if (currentSubstringLength < 1) break;
                currentSubstringLength--;
            }
        }
    }

    exclusion--;
    return count + countStrings(str, length, exclusion);
}

int main()
{
    char str[99];
    cin >> str;
    int length = charArrayLength(str);

    if (!onlyLetters(str, length)) {
        cout << "-1" << endl;
        return 0;
    }

    cout << countStrings(str, length, length - 1) - repetaingChars(str, length) << endl;

    return 0;
}


