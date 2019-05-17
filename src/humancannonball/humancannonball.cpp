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
#include <iomanip>

#include <stdio.h>
#include <stdlib.h>

using namespace std;

double dist(pair<double, double>& a, pair<double, double>& b) {
    return sqrt(
        abs(a.first - b.first) *
        abs(a.first - b.first) +
        abs(a.second - b.second) *
        abs(a.second - b.second)
    );
}

int main() {
    double srcx, srcy, dstx, dsty;
    double x, y;
    int n;
    
    while (cin >> srcx >> srcy >> dstx >> dsty >> n) {
        // Construct src & dst points
        pair<double, double> src, dst;
        src = make_pair(srcx, srcy);
        dst = make_pair(dstx, dsty);
        
        // Read cannons data
        pair<double, double> cannons[n+1];
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            cannons[i] = make_pair(x, y);
        }
        cannons[n] = dst;
        
        // Construct graph, not including the starting point
        double g[n+1][n+1];
        bool visited[n+1];
        for (int i = 0; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                double d = dist(cannons[i], cannons[j]);
                // Walking time
                double a = d / 5;
                // Launching time, 2 sec + walking distance
                double b = 2 + abs(d - 50) / 5;
                g[i][j] = g[j][i] = min(a, b);
            }
            // Populate walking time to the destination
            // n = last element
//             cerr << "S" << " -> " << i << ": " << dist(cannons[i], src) / 5 << " | " << dist(cannons[i], src) << endl;
            visited[i] = false;
        }
        
//         for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)if(i!=j)cerr<<i<<" -> "<<j<<": "<<g[i][j]<<" | "<<dist(cannons[i],cannons[j])<<endl;
        
        
        // <time, index#cannon>
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
    
        
        // Populate walking time from source
        for (int i = 0; i <= n; i++) {
            q.push(make_pair(dist(cannons[i], src) / 5, i));
        }
        
        double target;
        while (!q.empty()) {
            pair<double, int> p = q.top();
            q.pop();
            double d = p.first;
            int i = p.second;
            if (i == n) {
                // We found the final target
                target = d;
                break;
            }
            if (visited[i]) continue;
            visited[i] = true;
            
            // Iterate through its childs, including the end point
            for (int k = 0; k <= n; k++) {
                if (i != k && !visited[k]) {
                    q.push(make_pair(d + g[i][k], k));
                }
            }
            
        }
        
        cout << setprecision(40) << target << endl;
    }

    return 0;
}
