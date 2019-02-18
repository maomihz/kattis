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

int main() {
    cerr << "hello, world" << endl;

    vector<string> v;
    while (cin) {
        string s;
        cin >> s;
        if (!cin) break;
        v.push_back(s);
    }

    unordered_set<string> words;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            if (i == j) continue;
            words.insert(v[i] + v[j]);
        }
    }

    vector<string> words_sorted(words.begin(), words.end());
    sort(words_sorted.begin(), words_sorted.end());
    for (string s : words_sorted) {
        cout << s << endl;
    }
    

    return 0;
}
