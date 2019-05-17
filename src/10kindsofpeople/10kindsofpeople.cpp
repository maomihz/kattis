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

    int find(int i) {
        if (p[i] == i) {
            return i;
        } else {
            return p[i] = find(p[i]);
        }
    }

    bool equal(int i, int j) {
//         cerr << "e? (" << i << "," << j << ")" << endl;
        return find(i) == find(j);
    }

    void u(int i, int j) {
//         cerr << "u (" << i << "," << j << ")" << endl;
        if (!equal(i, j)) {
            int x = find(i);
            int y = find(j);
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




int main() {
    int r, c, q, r1, c1, r2, c2;
    char x;
    
    while (cin >> r >> c) {
        UnionFind uf(r * c);
        char map[r][c];
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> x;
                
                int ki = i * c + j;
//                 printf("k=%d,p=%d,r=%d\n", ki, pi, ri);
                
                if (i > 0 && map[i-1][j] == x) {
                    uf.u(ki, ki - c);
                }
                if (j > 0 && map[i][j-1] == x) {
                    uf.u(ki, ki - 1);
                }
                
                map[i][j] = x;
            }
        }
        
        cin >> q;
        while (q--) {
            cin >> r1 >> c1 >> r2 >> c2;
            r1--;
            c1--;
            r2--;
            c2--;
            if (uf.equal(r1 * c + c1, r2 * c + c2)) {
                if (map[r1][c1] == '0') {
                    cout << "binary" << endl;
                } else {
                    cout << "decimal" << endl;
                }
            } else {
                cout << "neither" << endl;
            }
        }
        
    }
    

    return 0;
}
