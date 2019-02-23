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

    int x;
    int count = 1;
    while (cin >> x, x != 0) {
        vector<string> a,b;
        for (int i = 0; i < x; i++) {
            string s;
            cin >> s;
            if (i % 2 == 0) {
                a.push_back(s);
            } else {
                b.push_back(s);
            }
        }
        
        cout << "SET " << count << endl;
        for (size_t i = 0; i < a.size(); i++) {
            cout << a.at(i) << endl;
        }
        for (size_t i = 0; i < b.size(); i++) {
            cout << b.at(b.size() - i - 1) << endl;
        }
        count++;
    }

    return 0;
}
