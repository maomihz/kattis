#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <stack>
#include <climits>
#include <algorithm>

#include <stdio.h>
#include <stdlib.h>

using namespace std;

bool cmp(string a, string b) {
    string ra = a, rb = b;
    
    reverse(ra.begin(), ra.end());
    reverse(rb.begin(), rb.end());
    return ra < rb;
    if (a.at(a.length() - 1) < b.at(b.length() - 1)) {
        return true;
    }
    if (a.at(a.length() - 1) > b.at(b.length() - 1)) {
        return false;
    }
    
    if (a.length() >= 2 && b.length() >= 2) {
        if (a.at(a.length() - 2) < b.at(b.length() - 2)) {
            return true;
        }
        if (a.at(a.length() - 2) > b.at(b.length() - 2)) {
            return false;
        }
    }
    return a.length() < b.length();
}

int main() {
    string word;
    
    while (true) {
        vector<string> words;
        int len = 0;
        while (getline(cin, word)) {
            if (word == "") break;
            words.push_back(word);
            len = max((int)word.length(), len);
        }
        
        sort(words.begin(), words.end(), cmp);
        for (string w : words) {
            for (int i = 0; i < len - w.length(); i++) {
                cout << " ";
            }
            cout << w << endl;
        }
        if (cin) {
            cout << endl;
        } else {
            break;
        }
    }

    return 0;
}


