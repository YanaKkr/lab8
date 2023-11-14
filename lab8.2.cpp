#include <iostream>

using namespace std;

void checkLastWord(const string words[], int size) {
    bool found = false;
    for (int i = size - 1; i >= 0; --i) {
        if (words[i][0] == 'a' || words[i][0] == 'A') {
            cout << "Last word which starts with a letter 'a': " << words[i] << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "There isn't a word which starts with a letter 'a'" << endl;
    }
}

void splitString(const string& str, string words[], int& size) {
    string word = "";
    size = 0;
    for (char ch : str) {
        if (isspace(ch)) {
            if (!word.empty()) {
                words[size++] = word;
                word = "";
            }
        } else {
            word += ch;
        }
    }
    if (!word.empty()) {
        words[size++] = word;
    }
}

int main() {
    cout << "Enter sentence: ";
    string str;
    getline(cin, str);

    const int maxSize = 100; 
    string words[maxSize];
    int size;
    splitString(str, words, size);

    checkLastWord(words, size);

    return 0;
}
