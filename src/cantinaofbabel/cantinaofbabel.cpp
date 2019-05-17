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


int dfs(unordered_set<int>* g, int start, stack<int>& s, bool* seen) {
    if (seen[start]) return 0;
    seen[start] = true;
    
    for (int x : g[start]) {
        dfs(g, x, s, seen);
    }
    
    s.push(start);
}

int main() {
    int n;
    string name, s, line, speak;
    
    while (getline(cin, line)) {
        istringstream ss_n(line);
        ss_n >> n;
        
        // Language -> Person who understand that language
        unordered_map<string, unordered_set<int>> understands;
        
        // Person -> Languages the person speak
        string speaks[n];
        
        // Index -> name
        string names[n];
        
        
        // Read data
        for (int i = 0; i < n; i++) {
            getline(cin, line);
            istringstream ss_line(line);
            ss_line >> names[i];
            
            int c = 0;
            while (ss_line >> s) {
                if (c++ == 0) { speaks[i] = s; }
                if (understands.find(s) == understands.end()) {
                    understands[s] = unordered_set<int>();
                }
                understands[s].insert(i);
            }
        }
        
        
        // Build the graph
        unordered_set<int> g[n];
        unordered_set<int> g_reverse[n];
        
        bool seen[n];
        for (int i = 0; i < n; i++) {
            seen[i] = false;
            for (int x : understands[speaks[i]]) {
                if (x != i) {
                    g[i].insert(x);
                    g_reverse[x].insert(i);
                }
            }
        }
        
        
        // Find largest strongly connected components
        // Build stack
        stack<int> st;
        for (int i = 0; i < n; i++) {
            dfs(g, i, st, seen);
        }
        
        int max_count = 0;
        for (int i = 0; i < n; i++) {
            seen[i] = false;
        }
        while (!st.empty()) {
            int x = st.top();
            st.pop();
            if (seen[x]) continue;
            
            stack<int> component;
            dfs(g_reverse, x, component, seen);
            max_count = max(max_count, (int)component.size());
        }
        cout << n - max_count << endl;
        
        
        // Debug
//         for (int i = 0; i < n; i++) {
//             cerr << i << ": ";
//             for (int x : g[i]) {
//                 cerr << x << ", ";
//             }
//             cerr << endl;
//         }
//         cerr << "* Graph" << endl;
//         for (int i = 0; i < n; i++) {
//             cerr << names[i] << ": ";
//             for (int x : g[i]) {
//                 cerr << names[x] << ", ";
//             }
//             cerr << endl;
//         }
//         cerr << "* Reverse Graph" << endl;
//         for (int i = 0; i < n; i++) {
//             cerr << names[i] << ": ";
//             for (int x : g_reverse[i]) {
//                 cerr << names[x] << ", ";
//             }
//             cerr << endl;
//         }
        
    }

    

    return 0;
}
