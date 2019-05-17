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
    int r, c;
    
    while (cin >> r >> c) {
        pair<int, int> map[r][c];
        bool seen[r][c];
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                seen[i][j] = false;
                char d;
                cin >> d;
                
                if (d == 'N') {
                    map[i][j] = make_pair(-1, 0);
                } else if (d == 'S') {
                    map[i][j] = make_pair(1, 0);
                } else if (d == 'W') {
                    map[i][j] = make_pair(0, -1);
                } else if (d == 'E') {
                    map[i][j] = make_pair(0, 1);
                } else if (d == 'T') {
                    map[i][j] = make_pair(0, 0);
                }
            }
        }
        
        
        
        pair<int, int> player = make_pair(0, 0);
        int moves = 0;
        
        
        while (true) {
            pair<int, int> dir = map[player.first][player.second];
            if (dir == make_pair(0, 0)) {// Treasure
                cout << moves << endl;
                break;
            }
            
            if (seen[player.first][player.second]) {
                cout << "Lost" << endl;
                break;
            }
            
            seen[player.first][player.second] = true;
            
            player.first += dir.first;
            player.second += dir.second;
            moves++;
            
            if (player.first < 0 || player.first >= r || player.second < 0 || player.second >= c) {
                cout << "Out" << endl;
                break;
            }
        }
        
    }

    return 0;
}
