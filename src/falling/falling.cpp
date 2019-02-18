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

int main() {
    cerr << "hello, world" << endl;

    int n, a, b;
    scanf("%d", &n);
    if (n % 4 != 0 && !(n & 1)){
        printf("impossible\n");
        return 0;
    } else if (n % 4 == 0) {
        a = (n / 2 - 2) / 2;
        b = (n / 2 + 2) / 2;
    } else {
        a = (n - 1) / 2;
        b = (n + 1) / 2;
    }
    printf("%d %d\n", a, b);

    return 0;
}
