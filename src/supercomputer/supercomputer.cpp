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

class Computer {
private:
    int * bits;
    int * tree;
    int n;

    int left(int p) {
        return p << 1;
    }
    int right(int p) {
        return (p << 1) + 1;
    }
public:
    Computer (int n) {
        this->n = n;
        bits = new int[n];
        tree = new int[4 * n];
        for (int i = 0; i < n; i++) {
            bits[i] = 0;
            tree[i] = 0;
        }
    }

    void update(int p, int L, int R, int v) {
        if (L == R) {
            bits[p] = x
        }
    }
}

int main() {
    cerr << "hello, world" << endl;

    

    return 0;
}
