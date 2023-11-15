#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> 
using namespace std;

void CountRecursive(char* s, const char* find, int* a, int i, int j) {
    if (i < strlen(find)) {
        if (j < strlen(s)) {
            if (s[j] == find[i]) {
                a[i]++;
            }
            CountRecursive(s, find, a, i, j + 1);
        }
        else {
            CountRecursive(s, find, a, i + 1, 0);
        }
    }
}

void Count(char* s, const char* find, int* a) {
    CountRecursive(s, find, a, 0, 0);
}

char* ChangeRecursive(char* str, char* tmp, char* t, size_t i) {
    size_t len = strlen(str);
    if (i < len && str[i + 2] != 0) {
        if (str[i] == 'B' && str[i + 1] == 'A' && str[i + 2] == 'S' && str[i + 3] == 'I' && str[i + 4] == 'C') {
            strcat(t, "Delphi");
            t += 6;
            return ChangeRecursive(str, tmp, t, i + 5);
        }
        else {
            *t++ = str[i++];
            *t = '\0';
            return ChangeRecursive(str, tmp, t, i);
        }
    }
    else {
        *t++ = str[i++];
        *t++ = str[i++];
        *t = '\0';
        strcpy(str, tmp);
        return tmp;
    }
}

char* Change(char* str) {
    size_t len = strlen(str);
    if (len < 6)
        return str;
    char* tmp = new char[len * 6 / 5 + 1];
    char* t = tmp;
    tmp[0] = '\0';
    return ChangeRecursive(str, tmp, t, 0);
}

int main() {
    char str[101];
    char find[] = "BASIC";
    int* a = new int[strlen(find)];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    Count(str, find, a);
    for (int i = 0; i < strlen(find); i++) {
        cout << "Символ " << find[i] << " зустрічається " << a[i] << " разів" << endl;
    }
    char* dest = new char[151];
    dest = Change(str);
    cout << dest;


    delete[] a;
    delete[] dest;

    return 0;
}
