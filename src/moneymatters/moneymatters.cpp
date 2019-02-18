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
    cerr << "hello, world" << endl;

    int n, m;
    cin >> n >> m;
    int owes[n];
    int sums[n];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        owes[i] = x;
        sums[i] = 0;
    }

    UnionFind uf(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        uf.unionSet(a, b);
    }

    for (int i = 0; i < n; i++) {
        sums[uf.findSet(i)] += owes[i];
        // cerr << sums[uf.findSet(i)] << endl;
    }
    // for (int i = 0; i < n; i++) {
    //     cerr << sums[i] << " ";
    // }
    // cerr << endl;

    for (int i = 0; i < n; i++) {
        if (sums[i] != 0) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    cout << "POSSIBLE" << endl;
    

    return 0;
}
