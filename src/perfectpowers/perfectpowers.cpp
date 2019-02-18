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

typedef long long int64;

int get(int x) {
    if (x == -2147483648) {
        return 31;
    }

    for (int base = 2;; base++) {
        if (base > 46340) return 1;
        if (base > 1290 && x < 0) return 1;


        int sum = 1;
        int power = 0;

        while (sum <= (2147483647 / base)) {
            sum *= base;
            power++;

            if (x >= 0) {
                if (sum == x) return power;
            } else {
                if (power % 2 == 0) continue;
                if (sum == -x) return power;
            }
        }

    }
    return -1;
}

int main() {
    int n;
    
    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;
        printf("%d\n", get(n));
    }

    

    return 0;
}
