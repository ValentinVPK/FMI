
#include <iostream>
using namespace std;

int charArrayLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    return length;
}

bool invalidInput(char str1[], char str2[], char str3[], int str1Length, int str2Length, int str3Length) {
    
    for (size_t i = 0; i < str1Length; i++) {
        if (str1[i] < 'a' || str1[i] > 'z'){
            return true;
        }
    }

    for (size_t i = 0; i < str2Length; i++) {
        if (str2[i] < 'a' || str2[i] > 'z') {
            return true;
        }
    }

    for (size_t i = 0; i < str3Length; i++) {
        if (str3[i] < 'a' || str3[i] > 'z') {
            return true;
        }
    }

    return false;
}

int str3LetterCount(char str3[], char letter, int str3Length) {
    int count = 0;
    for (size_t i = 0; i < str3Length; i++) {
        if (str3[i] == letter) count++;
    }

    return count;
}

int str1AndStr2LetterCount(char str1[], char str2[], char letter, int str1Length, int str2Length) {
    int count = 0;
    for (size_t i = 0; i < str1Length; i++) {
        if (str1[i] == letter) count++;
    }

    for (size_t i = 0; i < str2Length; i++) {
        if (str2[i] == letter) count++;
    }

    return count;
}

bool isString3Combined(char str1[], char str2[], char str3[], int str1Length, int str2Length, int str3Length) {
    if (str3Length != str1Length + str2Length) return false;

    for (size_t i = 0; i < str3Length; i++) {
        char currLetterStr3 = str3[i];

        int currLetterStr3Count = str3LetterCount(str3, currLetterStr3, str3Length);
        int currLetterStr1AndStr2Count = str1AndStr2LetterCount(str1, str2, currLetterStr3, str1Length, str2Length);

        if (currLetterStr3Count != currLetterStr1AndStr2Count) {
            return false;
        }
    }

    return true;
}


int main()
{
    char str1[150], str2[150], str3[150], combinedStr[300];
    cin >> str1 >> str2 >> str3;

    int str1Length = charArrayLength(str1);
    int str2Length = charArrayLength(str2);
    int str3Length = charArrayLength(str3);

    if (invalidInput(str1, str2, str3, str1Length, str2Length, str3Length)) {
        cout << "-1";
        return 0;
    }

    cout << isString3Combined(str1, str2, str3, str1Length, str2Length, str3Length) << endl;

    return 0;
}

