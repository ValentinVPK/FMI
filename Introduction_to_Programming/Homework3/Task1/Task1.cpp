
#include <iostream>
using namespace std;

int charArrayLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    return length;
}

int charCount(char str[], size_t i, int length) {
    int count = 1;
    for (size_t j = i + 1; j < length; j++) {
        if (str[j] == str[i]) count++;
    }

    return count;
}

bool areAmountOfSymbolsEqual(char str[]) {
    int length = charArrayLength(str);
    int count;
    bool oneExclusion = false;
    bool areEqual = true;

    for (size_t i = 0; i < length; i++) {
        if (i == 0) {
            count = charCount(str, i, length);
            continue;
        }
        bool isAlreadyCounted = false;
        for (size_t j = 0; j < i; j++) {
            if (str[j] == str[i]) isAlreadyCounted = true;
        }
        if (isAlreadyCounted) continue;
        
        int currentCharCount = charCount(str, i, length);

        if (currentCharCount == count + 1 && !oneExclusion) {
            currentCharCount--;
            oneExclusion = true;
        }
        if (currentCharCount == 1 && count > 1 && !oneExclusion) {
            oneExclusion = true;
            continue;
        }
        if (count == currentCharCount + 1 && !oneExclusion) {
            count--;
            oneExclusion = true;
        }
        if (currentCharCount != count) {
            areEqual = false;
            break;
        }
    }

    return areEqual;
}

int main()
{
    char str[150];
    cin.getline(str,150);
    
    cout << areAmountOfSymbolsEqual(str);
}

