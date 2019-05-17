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
    int m, n;
    while (cin >> m) {
        
        string x, y;
        unordered_set<string> u, a, b;
        
        while (m--) {
            cin >> x;
            u.insert(x);
        }
        
        unordered_map<string, unordered_set<string>> m;
        
        cin >> n;
        // Build the graph
        while (n--) {
            cin >> x >> y;
            if (m.find(x) == m.end()) {
                m[x] = unordered_set<string>();
            }
            if (m.find(y) == m.end()) {
                m[y] = unordered_set<string>();
            }
            m[x].insert(y);
            m[y].insert(x);
        }
        
        bool over = false;
        // Iterate through words
        for (string s : u) {
            // If we have already seen the word, then continue
            if (a.find(s) != a.end() || b.find(s) != b.end()) {
                continue;
            }
            
            
            vector<string> layer1;
            layer1.push_back(s);
            a.insert(s);
            
            
            while (!layer1.empty()) {
                vector<string> layer2;
                bool s1ina, s1inb, s2ina, s2inb;
                for (string s1 : layer1) {
                    s1ina = a.find(s1) != a.end();
                    s1inb = b.find(s1) != b.end();
                    // Find all of its conflict
                    for (string s2 : m[s1]) {
                        s2ina = a.find(s2) != a.end();
                        s2inb = b.find(s2) != b.end();
                        
                        if ((s1ina || s1inb) && (s2ina || s2inb)) {
                            // If the sorting is in conflict
                            if (s1ina == s2ina) {
                                over = true;
                                break;
                            }
                            // If both are sorted, then skip
                            continue;
                        }
                        
                        (s1ina ? b : a).insert(s2);
                        layer2.push_back(s2);
                    }
                    if (over) break;
                }
                if (over) break;
                layer1 = layer2;
            }
            if (over) break;
        }
        
        if (over) {
            cout << "impossible" << endl;
        } else {
            for (string x : a) {
                cout << x << " ";
            }
            cout << endl;
            for (string x : b) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}
