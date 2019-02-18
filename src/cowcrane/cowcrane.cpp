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
#include <stdarg.h>

using namespace std;

int abs(int a) {
    if (a >= 0) return a;
    return -a;
}

int path(int nargs, ...) {
    va_list valist;
    va_start(valist, nargs);

    int last = 0;
    int sum = 0;
    int i, r;
    for (i = 0; i < nargs; i++) {
        r = va_arg(valist, int);
        sum += abs(last - r);
        last = r;
    }

    return sum;
}

int main() {

    int s1, s2, d1, d2, t1, t2;
    int S = 0;

    while (scanf("%d %d\n%d %d\n%d %d", &s1, &s2, &d1, &d2, &t1, &t2) != EOF) {
        // printf("s1(%d) -> d1(%d), s2(%d) -> d2(%d)\n", s1, d1, s2, d2);

        // cout << boolalpha;
        // cout << (path(2, s1, d1) <= t1 && path(4, s1, d1, s2, d2) <= t2) << endl;
        // cout << (path(2, s2, d2) <= t2 && path(4, s2, d2, s1, d1) <= t1) << endl;
        // cout << (path(2, s1, d1) <= t1 && path(4, s1, d1, s1, d2) <= t2) << endl;
        // cout << (path(2, s2, d2) <= t2 && path(4, s2, d2, s2, d1) <= t2) << endl;
        // cout << path(2, s2, d2) << ", " << path(4, s2, d2, s2, d1) << endl;

        if (
            (path(2, s1, d1) <= t1 && path(4, s1, d1, s2, d2) <= t2) ||
            (path(2, s2, d2) <= t2 && path(4, s2, d2, s1, d1) <= t1) ||
            (path(2, s1, d1) <= t1 && path(4, s1, d1, s1, d2) <= t2) ||
            (path(2, s2, d2) <= t2 && path(4, s2, d2, s2, d1) <= t1)
        ) {
            printf("possible\n");
        } else {
            printf("impossible\n");
        }

        // // Case 1
        // T1 = abs(S - s1) + abs(s1 - d1);
        // T2 = abs()
    }

    return 0;
}
