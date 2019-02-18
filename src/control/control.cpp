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

    int n;
    cin >> n;

    int count = 0;

    unordered_map<int, unordered_set<int>*> all;

    int c = 0;
    while (n--) {
        int m;
        cin >> m;

        unordered_map<int, bool> required;
        while (m--) {
            int i;
            cin >> i;
            required[i] = false;
        }

        bool ok = true;
        for (auto it = required.begin(); it != required.end(); it++) {
            if (it->second) continue;

            if (all.find(it->first) == all.end()) {
                all[it->first] = new unordered_set<int>({it->first});
                required[it->first] = true;
            } else {
                unordered_set<int>* items = all[it->first];
                
                for (auto item = items->begin(); item != items->end(); item++) {
                    if (required.find(*item) == required.end()) {
                        ok = false;
                        break;
                    } else {
                        required[*item] = true;
                    }
                }
            }
            if (!ok) break;
        }

        if (ok) {
            for (auto it = required.begin(); it != required.end(); it++) {
                if (!it->second) {
                    ok = false;
                    break;
                }
            }
        }

        // Merge
        unordered_set<int>* hello = new unordered_set<int>;
        if (ok) {
            for (auto it = required.begin(); it != required.end(); it++) {
                hello->insert(it->first);
                all[it->first] = hello;
            }
            c++;
        }
    }
    cout << c << endl;

    return 0;
}
