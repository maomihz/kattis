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


bool cmp(tuple<int, int, int>& a, tuple<int, int, int>& b) {
    return get<2>(a) < get<2>(b);
}

int main2() {
    int n, m, c, i, j, d;
    cin >> n;

    vector<tuple<int, int, int>> edges;

    while (n--) {
        cin >> m >> c;
        UnionFind uf(c);

        for (int a = 0; a < c * (c-1) / 2; a++) {
            cin >> i >> j >> d;
            edges.push_back(make_tuple(i, j, d));
        }

        sort(edges.begin(), edges.end(), cmp);

        int count = 0;
        long long weights = 0;
        for (tuple<int, int, int>& edge : edges) {
            cerr << "Cat " << get<0>(edge) << "," << get<1>(edge) << "," << get<2>(edge) << endl;

            int a = get<0>(edge);
            int b = get<1>(edge);

            if (uf.isSameSet(a, b)) {
                cerr << "No" << endl;
                continue;
            }
            uf.unionSet(a, b);
            weights += get<2>(edge);

            if (++count >= c - 1) break;
        }

        cerr << "weight = " << weights << endl;
        if (weights + c <= m) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}




int main() {
    int n, m, c, i, j, d;
    cin >> n;


    while (n--) {
        vector<tuple<int, int, int>> edges;
        cin >> m >> c;
        UnionFind uf(c);

        for (int a = 0; a < c * (c-1) / 2; a++) {
            cin >> i >> j >> d;
            edges.push_back(make_tuple(i, j, d));
        }

        sort(edges.begin(), edges.end(), cmp);

        int count = 0;
        long long weights = 0;
        for (tuple<int, int, int>& edge : edges) {
            cerr << "Cat " << get<0>(edge) << "," << get<1>(edge) << "," << get<2>(edge) << endl;

            int a = get<0>(edge);
            int b = get<1>(edge);

            if (uf.isSameSet(a, b)) {
                cerr << "No" << endl;
                continue;
            }
            uf.unionSet(a, b);
            weights += get<2>(edge);

            if (++count >= c - 1) break;
        }

        cerr << "weight = " << weights << endl;
        if (weights + c <= m) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}