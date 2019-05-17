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
    
    int n;
    while (cin >> n) {
        int t = 0;
        for (int i = 2; i <= n; i++) {
            t = t * 2 + i - 1;
        }
        cout << t << endl;
    }

    return 0;
}
