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
#include <cmath>

using namespace std;

int factor(int x, int begin=2) {
    if (x <= 1) return 0;
    int s = sqrt(x);
    for (int i = begin; i <= s; i++) {
        if (x % i == 0) {
            return i + factor(x / i, i);
        }
    }
    return x;
}

int main() {
    int m, n, c;
    while (cin >> n, n != 4) {
        c = 1;
        while (n != (m = factor(n))) {
            c++;
            n = m;
        }
        cout << n << " " << c << endl;
    }
    return 0;
}
