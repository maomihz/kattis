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
    int h, w;
    pair<int, int> target;
    char ch;
    
    while (cin >> h >> w, h != 0 && w != 0) {
        int map[h][w];               // Track numbers
        pair<int, int> parent[h][w]; // Track the parents
        bool visited[h][w];          // Track visited
        
        // Fill map with data
        for (int r = 0; r < h; r++) {
            for (int c = 0; c < w; c++) {
                cin >> ch;
                map[r][c] = ch - '0';
                visited[r][c] = false;
            }
        }
        
        
        
        // <Distance, Coordinate>
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > q;
        
        
        // Push the first row
        for (int i = 0; i < w; i++) {
            q.push(make_pair(map[0][i], make_pair(0, i)));
            visited[0][i] = true;
        }
        
        
        
        while (!q.empty()) {
            pair<int, pair<int, int>> t = q.top();
            q.pop();
            
            
            int dist = t.first;
            pair<int, int> coord = t.second;
            int r = coord.first;
            int c = coord.second;
            cerr << "Dist=" << dist << ", Coord=(" << r << "," << c << ")\n";
            
            
            // If we reach the last line
            if (r == h - 1) {
                target = coord;
                cerr << "target=(" << target.first << "," << target.second << ")" << endl;
                break;
            }
            
            // Go to next coordinates
            vector<pair<int, int>> next_coords;
            
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int nr = r + i;
                    int nc = c + j;
                    
                    if (nr <= 0) continue;
                    if (nr >= h) continue;
                    if (nc < 0) continue;
                    if (nc >= w) continue;
                    if (visited[nr][nc]) continue;
                    visited[nr][nc] = true;
                    
                    // Calculate distance
                    int ndist = dist + map[nr][nc];
                    parent[nr][nc] = coord;
                    q.push(make_pair(ndist, make_pair(nr, nc)));
                }
            }
        }
        
        
        
        while (target.first != 0) {
            map[target.first][target.second] = 0;
            target = parent[target.first][target.second];
        }
        map[target.first][target.second] = 0;
        
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                int v = map[i][j];
                if (v == 0) {
                    cout << " ";
                } else {
                   cout << v;
                }
            }
            cout << endl;
        }
        cout << endl;
        
        
        
    }

    return 0;
}
