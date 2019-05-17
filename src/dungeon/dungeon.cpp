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

typedef tuple<int, int, int> coord;

int main() {
    int z, h, w;
    char ch;
    while (cin >> z >> h >> w, z != 0 && h != 0 && w != 0) {
        char map[z][h][w];
        bool seen[z][h][w];
        coord start;
        
        for (int i = 0; i < z; i++) {
            for (int j = 0; j < h; j++) {
                for (int k = 0; k < w; k++) {
                    cin >> ch;
                    map[i][j][k] = ch;
                    seen[i][j][k] = false;
                    
                    if (ch == 'S') {
                        start = make_tuple(i,j,k);
                        seen[i][j][k] = true;
                    }
                }
            }
        }
        
        queue<pair<coord, int>> q;
        q.push(make_pair(start, 0));
        
        bool done = false;
        while (!q.empty()) {
            pair<coord, int> cpair = q.front();
            coord co = cpair.first;
            int depth = cpair.second;
            q.pop();
            
            int a = get<0>(co);
            int b = get<1>(co);
            int c = get<2>(co);
            
//             cerr << a << "," << b << "," << c << endl;
            
            vector<coord> next = {
                make_tuple(a+1,b,c),
                make_tuple(a-1,b,c),
                make_tuple(a,b+1,c),
                make_tuple(a,b-1,c),
                make_tuple(a,b,c+1),
                make_tuple(a,b,c-1)
            };
            
            for (coord& n : next) {
                int na = get<0>(n);
                int nb = get<1>(n);
                int nc = get<2>(n);
            
                // Boundary
                if (na < 0 || na >= z) continue;
                if (nb < 0 || nb >= h) continue;
                if (nc < 0 || nc >= w) continue;
                
                // Check for walls
                if (map[na][nb][nc] == '#') continue;
                
                // Check visited
                if (seen[na][nb][nc]) continue;
                seen[na][nb][nc] = true;
                
                // Check destination
                if (map[na][nb][nc] == 'E') {
                    done = true;
                    cout << "Escaped in " << depth+1 << " minute(s)." << endl;
                    break;
                }
                
                q.push(make_pair(n, depth+1));
            }
            
            if (done) break;
        }
        
        if (!done) {
            cout << "Trapped!" << endl;
        }
        
    }

    return 0;
}
