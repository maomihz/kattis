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
    int c, r;
    cin >> c >> r;
    
    char t;
    char map[r][c];
    bool seen[r][c];
    
    
    pair<int, int> player;
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> t;
            if (t == 'P') {
                player = make_pair(i, j);
                t = '.';
            }
            map[i][j] = t;
            seen[i][j] = false;
        }
    }
    
    
    queue<pair<int, int>> q;
    q.push(player);
    
    int gold = 0;
    
    while (!q.empty()) {
        pair<int, int> t = q.front();
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if (seen[r][c]) {
            continue;
        }
        seen[r][c] = true;
        
//         cerr << "(" << r << ","<< c << ")="<<map[r][c]<<endl;
        
        char V = map[r][c];
        
        if (V == 'G') {
            gold++;
        }
        if (V == '#') {
            continue;
        }
        
        char L = map[r][c-1],
             R = map[r][c+1],
             U = map[r-1][c],
             D = map[r+1][c];
        
        if (V=='T' || L=='T' || R=='T' || U=='T' || D=='T') {
            continue;
        }
        
//         fprintf(stderr, "V=%c,L=%c,R=%c,U=%c,D=%c\n", V,L,R,U,D);
        
        q.push(make_pair(r, c+1));
        q.push(make_pair(r, c-1));
        q.push(make_pair(r+1, c));
        q.push(make_pair(r-1, c));
    }
    cout << gold << endl;
    
    return 0;
}
