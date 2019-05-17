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

struct Country {
    int total = 0;
    int left = 0;
    
    bool leave() {
        return left * 2 >= total;
    }
};

int main() {
    int a,b,c,p,x,l;
    while (cin >> c >> p >> x >> l) {
        unordered_map<int, unordered_set<int>> g;
        Country countries[c];
        bool left[c];
        
        for (int i = 0; i < c; i++) {
            left[i] = false;
        }
        
        for (int i = 0; i < p; i++) {
            cin >> a >> b;
            if (g.find(--a) == g.end()) {
                g[a] = unordered_set<int>();
            }
            if (g.find(--b) == g.end()) {
                g[b] = unordered_set<int>();
            }
            
            g[a].insert(b);
            g[b].insert(a);
            countries[a].total++;
            countries[b].total++;
        }
        
        queue<int> q;
        q.push(--l);
        left[l] = true;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            
            for (int c : g[x]) {
                if (left[c]) continue;
                countries[c].left++;
                if (countries[c].leave()) {
                    left[c] = true;
                    q.push(c);
                }
            }
        }
        left[l] = true;
        
        
        cout << (left[--x] ? "leave" : "stay") << endl;
        
    }

    return 0;
}
