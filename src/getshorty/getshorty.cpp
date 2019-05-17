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
#include <cfloat>

#include <stdio.h>
#include <stdlib.h>

using namespace std;

class cmp {
    bool operator()(pair<int, double> a, pair<int, double> b) {
        return a.second < b.second;
    }
};

int main() {
    int n, m, a, b;
    double w;
    while (cin >> n >> m, n != 0 && m != 0) {
        unordered_map<int, double> g[n];
        
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> w;
            g[a][b] = w;
            g[b][a] = w;
        }
        
        
        // Run shortest path algorithm
        double dist[n];
        dist[0] = 1;
        for (int i = 1; i < n; i++) {
            dist[i] = 0;
        }
        priority_queue<pair<double, int>, vector<pair<double, int>>, less<pair<double, int>>> q;
        q.push(make_pair(1, 0));
        
        while (!q.empty()) {
            pair<double, int> p = q.top(); q.pop();
            
            double d = p.first;
            int n = p.second;
            
            
            for (auto it = g[n].begin(); it != g[n].end(); it++) {
                int n2 = it->first;
                double d2 = g[n][n2] * d;
                if (dist[n2] < d2) {
                    dist[n2] = d2;
                    q.push(make_pair(d2, n2));
                }
            }
        }
        
        printf("%.4f\n", dist[n-1]);
        
        
    }

    return 0;
}