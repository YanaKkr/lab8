#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

void Count(char* s, const char* find, int* a)
{
    for (int i = 0; i < strlen(find); i++)
    {
        int c = 0;
        for (int j = 0; j < strlen(s); j++)
        {
            if (s[j] == find[i])
            {
                c++;
            }
        }
        a[i] = c;
    }
}

char* Change(char* str)
{
    size_t len = strlen(str);
    if (len < 6)
        return str;
    char* tmp = new char[len * 6 / 5 + 1];
    char* t = tmp;
    tmp[0] = '\0';
    size_t i = 0;
    while (i < len && str[i + 2] != 0)
    {
        if (str[i] == 'B' && str[i + 1] == 'A' && str[i + 2] == 'S' && str[i + 3] == 'I' && str[i + 4] == 'C')
        {
            strcat(t, "Delphi");
            t += 6;
            i += 5;
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
        }
    }
    *t++ = str[i++];
    *t++ = str[i++];
    *t = '\0';
    strcpy(str, tmp);
    return tmp;
}

int main()
{
    char str[101];
    char find[] = "BASIC";
    int* a = new int[strlen(find)];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    Count(str, find, a);
    for (int i = 0; i < strlen(find); i++)
    {
        cout << "Symbol " << find[i] << " occurs " << a[i] << " times" << endl;
    }
    char* dest = new char[151];
    dest = Change(str);
    cout << dest;
}
