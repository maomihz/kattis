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
#include <cmath>

#include <stdio.h>
#include <stdlib.h>

using namespace std;

double dist(double a1, double a2, double b1, double b2) {
    return sqrt(abs(b1 - a1) * abs(b1 - a1) + abs(b2 - a2) * abs(b2 - a2));
}


int main() {
    int n, m, s, v;
    double a, b;
    
    while (cin >> n >> m >> s >> v) {
        pair<double, double> gophers[n];
        int size = n + m + 2;
        int start = size - 2;
        int end = size - 1;
        
        int speed = s * v;
        
        int g[size][size];
        for (int i = 0; i < size * size; i++) {
            g[i / size][i % size] = 0;
        }
        
        // Read gophers data
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            gophers[i] = make_pair(a, b);
            
            // Starting -> gophers
            g[start][i] = 1;
        }
        
        // Read holes data
        // Always gopher -> hole
        for (int i = n; i < m + n; i++) {
            cin >> a >> b;
            for (int j = 0; j < m; j++) {
                double d = dist(gophers[j].first, gophers[j].second, a, b);
                if (d <= speed) {
                    g[j][i] = 1;
                }
            }
            
            // Holes -> ending
            g[i][end] = 1;
        }
        
        
        
        

        // Start BFS
        int max_flow = 0;
        int parents[size];
        while (true) {
            // Clear parents array
            for (int i = 0; i < size; i++) {
                parents[i] = -1;
            }


            queue<int> q;
            q.push(start);
            parents[start] = start;

            bool done = false;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                
                for (int i = 0; i < size; i++) {
                    if (g[v][i] > 0 && parents[i] < 0) {
//                     cerr << "n=" << i << endl;
                        parents[i] = v;
                        q.push(i);

                        if (i == end) {
                            done = true;
                            break;
                        }
                    }
                }

                if (done) break;
            }

            // We cannot find more paths
            if (!done) break;

            int current = end;
            int p;
            
            while ((p = parents[current]) != current) {
                g[p][current]--;
                g[current][p]++;
                current = p;
            }

            max_flow++;
        }
        cout << n - max_flow << endl;
    }


    return 0;
}
