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
#include <stack>
#include <climits>
#include <algorithm>
#include <stdio.h>

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



int main() {
    int n, q;
    cin >> n >> q;


    UnionFind uf(n);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    char op[2];
    int a, b;
    while (q--) {
        scanf("%2s%d%d", op, &a, &b);
        
        if (op[0] == '?') {
            if (uf.isSameSet(a, b)) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        } else {
            uf.unionSet(a, b);
        }
    }


    return 0;
}
