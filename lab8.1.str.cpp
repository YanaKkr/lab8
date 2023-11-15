#include <iostream>
#include <string>

using namespace std;

void Count(const string& s, const string& find, int* a)
{
    for (size_t i = 0; i < find.length(); i++)
    {
        int c = 0;
        for (size_t j = 0; j < s.length(); j++)
        {
            if (s[j] == find[i])
            {
                c++;
            }
        }
        a[i] = c;
    }
}

string Change(string str)
{
    size_t len = str.length();
    if (len < 6)
        return str;

    size_t i = 0;
    while (i < len && str[i + 2] != 0)
    {
        if (str.substr(i, 5) == "BASIC")
        {
            str.replace(i, 5, "Delphi");
            i += 6; 
        }
        else
        {
            i++;
        }
    }

    return str;
}

int main()
{
    string str;
    string find = "BASIC";
    int* a = new int[find.length()];

    cout << "Enter string:" << endl;
    getline(cin, str);

    Count(str, find, a);
    for (size_t i = 0; i < find.length(); i++)
    {
        cout << "Символ " << find[i] << " зустрічається " << a[i] << " разів" << endl;
    }

    string dest = Change(str);
    cout << dest;

    delete[] a;

    return 0;
}
