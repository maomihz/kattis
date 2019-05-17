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

class UnionFind {
private:
    vector<int> p, rank;

public:
    UnionFind(int N) {
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++) {
            // Point to itself
            p[i] = i;
        }
    }

    int findSet(int i) {
        if (p[i] == i) {
            return i;
        } else {
            return p[i] = findSet(p[i]);
        }
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    } 

    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            int x = findSet(i);
            int y = findSet(j);
            if (rank[x] > rank[y]) {
                p[y] = x;
            } else {
                p[x] = y;
            }
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    }
};


struct Edge {
    int a;
    int b;
    int w;
};

bool cmp(Edge& a, Edge& b) {
    return a.w < b.w;
}

int main() {
    int c, m, c1, c2, d, t;
    
    
    while (cin >> c >> m) {
        UnionFind cities(c);
        vector<Edge> edges;
        
        for (int i = 0; i < m; i++) {
            cin >> c1 >> c2 >> d;
            edges.push_back(Edge{c1, c2, d});
        }
        
        sort(edges.begin(), edges.end(), cmp);
        
        int ans = 0;
        int count = 0;
        
        for (Edge& e : edges) {
            if (count >= c - 1) break;
            
            if (cities.isSameSet(e.a, e.b)) {
                continue;
            }
            
            cities.unionSet(e.a, e.b);
            ans = e.w;
            count++;
        }
        
        
        if (count >= c - 1) {
            cout << ans << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
        
        
    }


}

int main2() {
    int c, m, c1, c2, d, t;
    
    
    while (cin >> c >> m) {
        unordered_map<int, int> dist[c];
        
        UnionFind cities(c);
        
        for (int i = 0; i < m; i++) {
            cin >> c1 >> c2 >> d;
            if (c1 > c2) {
                t = c1; c1 = c2; c2 = t;
            }
            
            if (dist[c1].find(c2) == dist[c1].end()) {
                dist[c1][c2] = INT_MAX;
            }
            
            dist[c1][c2] = min(dist[c1][c2], d);
            cities.unionSet(c1, c2);
        }
        
        
        bool br = false;
        for (int i = 1; (i < c) && !br; i++) {
            if (cities.findSet(i) != cities.findSet(0)) {
                cout << "IMPOSSIBLE" << endl;
                br = true;
            }
        }
        if (br) continue;
        
        int ans = 0;
        
        for (int j = 0; j < c; j++) {
            for (int i = 0; i < j; i++) {
                if (dist[i].find(j) != dist[i].end()) {
                    ans = max(dist[i][j], ans);
                }
            }
        }
        
        
        cout << ans << endl;
    }

    return 0;
}
