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

int dfs(unordered_set<int>* g, int start, int& count, bool* seen, int* dfs_num, int* dfs_low, int* dfs_parent) {
    dfs_num[start] = dfs_low[start] = count++;
    
    for (int x : g[start]) {
        if (seen[x]) {
            if (x != dfs_parent[start]) {
                dfs_low[start] = min(dfs_low[start], dfs_low[x]);
            }
        } else {
            dfs_parent[x] = start;
            seen[x] = true;
            
            if (dfs(g, x, count, seen, dfs_num, dfs_low, dfs_parent) == -1) return -1;
            if (dfs_low[x] > dfs_num[start]) return -1;
                
            dfs_low[start] = min(dfs_low[start], dfs_low[x]);
        }
    }
    return 0;
}

int main() {
    int p, c;
    int a, b;
    
    while (cin >> p >> c, p != 0 && c != 0) {
        unordered_set<int> g[p];
        
        // Build graph
        for (int i = 0; i < c; i++) {
            cin >> a >> b;
            g[a].insert(b);
            g[b].insert(a);
        }
        
        int dfs_num[p];
        int dfs_low[p];
        int dfs_parent[p];
        bool seen[p];
        int count = 0;
        
        for (int i = 0; i < p; i++) {
            seen[i] = false;
        }
        
        bool fail = (dfs(g, 0, count, seen, dfs_num, dfs_low, dfs_parent) == -1);
        
        
        if (!fail)
        for (int i = 0; i < p; i++) {
            if (!seen[i]) {
                fail = true;
                break;
            }
        }
        
        
        cout << (fail ? "Yes" : "No") << endl;
        
        
    }
    
    return 0;
}
