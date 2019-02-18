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

class UF {
private:
    int * p;
    int * rank;
    int n;

public:
    UF(int n) {
        this->n = n;
        p = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            p[i] = i;
            rank[i] = 0;
        }
    }

    int find(int a) {
        if (p[a] == a) {
            return a;
        } else {
            return p[a] = find(p[a]);
        }
    }

    int eq(int a, int b) {
        return find(a) == find(b);
    }

    void merge(int a, int b) {
        if (!eq(a, b)) {
            int pa = find(a);
            int pb = find(b);

            if (rank[pa] < rank[pb]) {
                p[pa] = pb;
            } else {
                p[pb] = pa;
            }
            if (rank[pa] == rank[pb]) {
                rank[pa]++;
            }
        }
    }

    bool check() {
        for (int i = 1; i < n; i++) {
            if (find(0) != find(i)) return false;
        }
        return true;
    }
};

int main() {
    cerr << "hello, world" << endl;

    int n, m;
    scanf("%d%d", &n, &m);

    UF uf(n+1);

    vector<int> notconnected;
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        uf.merge(a, b);
    }

    for (int i = 2; i <= n; i++) {
        if (uf.find(1) != uf.find(i)) {
            notconnected.push_back(i);
        }
    }

    if (notconnected.empty()) {
        cout << "Connected" << endl;
    } else {
        for (int i : notconnected) {
            cout << i << endl;
        }
    }

    return 0;
}
