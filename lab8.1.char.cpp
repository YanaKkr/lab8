#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

void Count(char* s, const char* find, int* a)
{
    int c;
    char* t, * k;
    for (int i = 0; i < strlen(find); i++)
    {
        c = 0;
        t = s;
        k = strchr(t, find[i]);
        while (k != NULL)
        {
            c++;
            t = k + 1;
            k = strchr(t, find[i]);
        }
        a[i] = c;
    }
}

char* Change(char* s, const char* find, const char* change) {
    char* t = new char[100];
    char* p = strstr(s, find);
    if (p == nullptr) {
        strcpy(t, s);
        return t;
    }
    int f = strlen(find);
    int c = strlen(change);
    int Index = 0;
    while (p != nullptr) {
        strncpy(t + Index, s, p - s);
        Index += p - s;
        strcpy(t + Index, change);
        Index += c;
        s = p + f;
        p = strstr(s, find);
    }
    strcpy(t + Index, s);
    return t;
}
int main()
{
    char str[101];
    char find[] = "BASIC";
    char change[] = "Delphi";
    int* a = new int[strlen(find)];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    Count(str, find, a);
    for (int i = 0; i < strlen(find); i++)
    {
        cout << "Symbol " << find[i] << " occurs " << a[i] << " times" << endl;
    }
    char* dest = new char[151];
    dest = Change(str, find, change);
    cout << dest;
}
