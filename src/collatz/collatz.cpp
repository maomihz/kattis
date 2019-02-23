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
    long long a, b;
    
    while (scanf("%lld %lld", &a, &b)) {
        if (a == 0 && b == 0) {
            break;
        }
        long long oa = a;
        long long ob = b;
        unordered_map<long long, int> aset;
        
        for (int i = 0;; i++) {
            aset[a] = i;
            if (a == 1) break;
            if (a & 1) {
                a = a * 3 + 1;
            } else {
                a >>= 1;
            }
        }
        
        int bsteps;
        for (bsteps = 0; aset.find(b) == aset.end(); bsteps++) {
            if (b & 1) {
                b = b * 3 + 1;
            } else {
                b >>= 1;
            }
        }
        
        printf("%lld needs %d steps, %lld needs %d steps, they meet at %lld\n",
               oa, aset[b], ob, bsteps, b);
    }
    

    return 0;
}
