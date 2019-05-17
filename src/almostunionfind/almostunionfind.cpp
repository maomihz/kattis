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

int find(vector<int> vals, int i) {
    if (vals[i - 1] == i - 1) {
        return i - 1;
    }
    int v = find(vals, vals[i - 1]);
    vals[i - 1] = v;
    return v;
}

void u(vector<int> parents, vector<int> sizes, vector<int> sums, int i, int j) {
    if (find(parents, i) == find(parents, j)) {
        return;
    }
    int ip = find(parents, i);
    int jp = find(parents, j);
    if (sizes[ip] < sizes[jp]) {
        parents[ip] = parents[jp];
        sizes[jp] += sizes[ip];
        sums[jp] += sums[ip]; 
    } else {
        parents[jp] = parents[ip];
        sizes[ip] += sizes[jp];
        sums[ip] += sums[jp];
    }
}

void s(vector<int> parents, vector<int> sizes, vector<int> sums, int i, int j) {
    if (find(parents, i) == find(parents, j)) {
        return;
    }
    int ip = find(parents, j);
    int jp = find(parents, j);
    sizes[ip] -= 1;
    sums[ip] -= i;

    sizes[jp] += 1;
    sums[jp] += i;

    parents[i] = jp;

}

int main2() {
    int num, commands;

    cin >> num;

    while (!cin.eof()) {
        cin >> commands;

        vector<int> parents(num);
        vector<int> sizes(num);
        vector<int> sums(num);

        for (int i = 0; i < num; i++) {
            parents[i] = i;
            sizes[i] = 1;
            sums[i] = i;
        }

        for (int i = 0; i < commands; i++) {
            int c, p, q;
            cin >> c >> p;
            if (c == 1) {
                cin >> q;
                u(parents, sizes, sums, p, q);
            } else if (c == 2) {
                cin >> q;
                s(parents, sizes, sums, p, q);
            } else {
                cout << sizes[find(parents, p)] << " " << sums[find(parents, p)] << endl;
            }
        }

        cin >> num;
    }

    

    


    

    return 0;
}



class UF {
private:
    vector<int> p, rank;
    vector<int> sums, el;
    int n;

public:
    UF(int N) {
        rank.assign(N, 0);
        p.assign(N, 0);
        sums.assign(N, 0);
        el.assign(N, 0);

        for (int i = 0; i < N; i++) {
            // Point to itself
            p[i] = i;
            sums[i] = i;
            el[i] = 1; // 1 element
        }

        n = N;
    }

    int find(int i) {
        if (p[i] == i) {
            return i;
        } else {
            return p[i] = find(p[i]);
        }
    }

    bool equal(int i, int j) {
        return find(i) == find(j);
    } 

    void mv(int a, int b) {
        if (!equal(a, b)) {

            for (int i = 0; i < n; i++) {
                find(i);
            }

            if (p[a] == a) { // if is root
                int newp = -1;
                for (int i = 0; i < n; i++) {
                    if (p[i] == a && i != a) {
                        if (newp < 0) {
                            newp = i;
                        }
                        p[i] = newp;
                    }
                }
            }

            sums[find(a)] -= a;
            el[find(a)] -= 1;
            sums[find(b)] += a;
            el[find(b)] += 1;

            p[a] = find(b);
        }
    }

    void u(int i, int j) {
        if (!equal(i, j)) {
            int x = find(i);
            int y = find(j);

            if (rank[x] > rank[y]) {
                p[y] = x;
                sums[x] += sums[y];
                sums[y] = 0;

                el[x] += el[y];
                el[y] = 0;
            } else {
                p[x] = y;
                sums[y] += sums[x];
                sums[x] = 0;

                el[y] += el[x];
                el[x] = 0;
            }

            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    }

    int sum(int i) {
        return sums[find(i)];
    }

    int size(int i) {
        return el[find(i)];
    }
};



struct MyUnionFind {
    vector<int> p;
    vector<int> rank;
    MyUnionFind(int n) {
        p.assign(n, 0);
        rank.assign(n, 0);
    }
}

int main() {
    while (true) {
        int n, m;
        cin >> n >> m;
        if (!cin) break;

        UF uf(n + 1);
        while (m--) {
            int op, a, b;
            cin >> op >> a;
            // cerr << "op " << op << " " << a << endl;

            if (op == 1) {
                cin >> b;
                uf.u(a, b);
            } else if (op == 2) {
                cin >> b;
                uf.mv(a, b);
            } else if (op == 3) {
                int x = uf.size(a);
                int y = uf.sum(a);
                cout << x << " " << y << endl;
            }

            // for (int i = 0; i < n; i++) {
            //     cerr << i + 1 << "(" << uf.find(i+1) << "): " << uf.size(i+1) << " " << uf.sum(i+1) << endl;
            // }
            // cerr << endl;
        }
    }
}