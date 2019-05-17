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
    int n, p, x;
    while (cin >> n >> p) {
        int ans = 0;
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> x;
            int profit = x - p;
            sum += profit;
            if (sum > ans) ans = sum;
            if (sum < 0) sum = 0;
        }
        cout << ans << endl;
    }

    return 0;
}
