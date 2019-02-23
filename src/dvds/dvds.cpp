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

    int k;
    cin >> k;
    int prev = -1;
    while (k--) {
        int n;
        cin >> n;
        int c = 1;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (c == x) {
                c++;
            }
        }
        cout << n - c + 1 << endl;
    }
    
    

    return 0;
}
