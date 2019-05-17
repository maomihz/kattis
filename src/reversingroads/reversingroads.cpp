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

int dfs(unordered_set<int>* g, int start, int& count, bool* seen) {
    if (seen[start]) return 0;
    seen[start] = true;
    
    for (int x : g[start]) {
        dfs(g, x, count, seen);
    }
    
    count++;
}

int connected(unordered_set<int>* g, unordered_set<int>* g_rev, int m) {
    bool seen[m * 2];
    for (int i = 0; i < m * 2; i++) seen[i] = false;
    
    // Do two dfs search
    int count = 0;
    dfs(g, 0, count, seen);
    if (count != m) return false;
    
    count = 0;
    dfs(g_rev, 0, count, seen + m);
    return count == m;
}


int main() {
    int m, n; // location, roads
    int a, b;
    
    int c = 1;
    
    while (cin >> m >> n) {
        cout << "Case " << c++ << ": ";
        unordered_set<int> g[m];
        unordered_set<int> g_rev[m];
        vector<pair<int, int>> edges;
        edges.reserve(m * (m - 1) / 2);
        
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            g[a].insert(b);
            g_rev[b].insert(a);
            edges.push_back(make_pair(a, b));
        }
        
        
        // Find strongly connected components
        // Build stack
        if (connected(g, g_rev, m)) {
            cout << "valid" << endl;
            continue;
        }
        
        // Do DFS
        bool done = false;
        for (pair<int, int> p : edges) {
            int a = p.first;
            int b = p.second;
            g[a].erase(b);
            g[b].insert(a);
            g_rev[b].erase(a);
            g_rev[a].insert(b);

            if (connected(g, g_rev, m)) {
                cout << a << " " << b << endl;
                done = true;
                break;
            }

            g[b].erase(a);
            g[a].insert(b);
            g_rev[a].erase(b);
            g_rev[b].insert(a);
            
        }
        
        if (!done) {
            cout << "invalid" << endl;
        }
    }

    

    return 0;
}
