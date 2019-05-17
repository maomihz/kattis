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

struct Solution {
    int r;
    int c;
    bool **map;
    bool **map2;
    
    Solution(int r, int c) : r(r),c(c) {
        char ch;
        map = new bool*[r];
        map2 = new bool*[r];
        bool seen[r][c];
            
        for (int i = 0; i < r; i++) {
            map[i] = new bool[c];
            map2[i] = new bool[c];
            
            for (int j = 0; j < c; j++) {
                cin >> ch;
                map[i][j] = (ch == '1');
                map2[i][j] = true;
                seen[i][j] = false;
            }
        }
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (i == 0 || i == r - 1 || j == 0 || j == c - 1) {
                    queue<pair<int, int>> q;
                    q.push(make_pair(i, j));
                    
                    while (!q.empty()) {
                        pair<int, int> p = q.front();
                        q.pop();
                        
                        
                        int rr = p.first;
                        int cc = p.second;
                        if (seen[rr][cc]) {
                            continue;
                        }
                        seen[rr][cc] = true;
                        
                        if (!map[rr][cc]) {
                            map2[rr][cc] = false;
                            if (rr > 0) {
                                q.push(make_pair(rr-1, cc));
                            }
                            if (rr < r - 1) {
                                q.push(make_pair(rr+1, cc));
                            }
                            if (cc > 0) {
                                q.push(make_pair(rr, cc-1));
                            }
                            if (cc < c - 1) {
                                q.push(make_pair(rr, cc+1));
                            }
                        }
                    }
                }
            }
        }
        
        
        
        
        for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) {
            seen[i][j] = false;
        }
        int count = 0;
        int edges = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (!seen[i][j] && map2[i][j]) {
                    queue<pair<int, int>> q;
                    q.push(make_pair(i, j));
                    
                    while (!q.empty()) {
                        pair<int, int> p = q.front();
                        q.pop();
                        
                        int rr = p.first;
                        int cc = p.second;
                        
                        if (seen[rr][cc]) {
                            continue;
                        }
                        seen[rr][cc] = true;
                        
                        count++;
                        
                        if (map2[rr][cc]) {
                            if (rr > 0) {
                                if (map2[rr-1][cc]) {
                                    edges++;
                                    q.push(make_pair(rr-1, cc));
                                }
                            }
                            if (rr < r - 1) {
                                if (map2[rr+1][cc]) {
                                    edges++;
                                    q.push(make_pair(rr+1, cc));
                                }
                            }
                            if (cc > 0) {
                                if (map2[rr][cc-1]) {
                                    edges++;
                                    q.push(make_pair(rr, cc-1));
                                }
                            }
                            if (cc < c - 1) {
                                if (map2[rr][cc+1]) {
                                    edges++;
                                    q.push(make_pair(rr, cc+1));
                                }
                            }
                        }
                    }
                    
                    
                }
            }
        }
//         cout << count << endl;
//         cout << edges << endl;
        cout << count * 4 - edges << endl;
    }
};


int main() {
    
    int r, c;
    while (cin >> r >> c) {
        Solution s(r, c);
        
    }

    return 0;
}
