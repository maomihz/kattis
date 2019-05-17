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
    char c;
    while (cin >> n) {
        unsigned long long zoo = 0;

        for (int i = n - 1; i >= 0; i--) {
            cin >> c;
            if (c != 'O') {
                long long x = 1LL << i;
                zoo += x;
            }
        }
        cout << (1LL << n) - zoo - 1 << endl;
    }

    return 0;
}
