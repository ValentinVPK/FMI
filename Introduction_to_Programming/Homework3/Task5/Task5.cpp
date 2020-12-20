
#include <iostream>
#include <fstream>
using namespace std;

int charArrayLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    return length;
}
char minChar(char str[], int length) {
    char min = 'z';

    for (int i = 0; i < length; i++) {
        if (str[i] < min) {
            min = str[i];
        }
    }
    return min;
}
char secretChar(char str[], int length, char min) {

    for (int i = min + 1; i <= 'z'; i++) {
        if (i > 90 && i < 97) continue;
        bool isEqual = false;
        for (size_t j = 0; j < length; j++) {
            if (str[j] == i) {
                isEqual = true;
                break;
            }
        }
        if (!isEqual) return i;
    }

    return '.';
}

void printSecretMessage(char filename[])
{
    ifstream myFile(filename);
    if (!myFile.is_open()) {
        cout << "-2";
        return;
    }
    char str[151];
    while (!myFile.eof())
    {
        myFile.getline(str, 151);
        int length = charArrayLength(str);
        for (size_t i = 0; i < length; i++) {
            if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))) {
                cout << "-1";
                return;
            }
        }

        char min = minChar(str, length);
        cout << secretChar(str, length, min);
    }
}
int main()
{
    char fileName[] = "message.txt";

    printSecretMessage(fileName);

    return 0;
}

