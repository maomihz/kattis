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
    int n, q, x, t, a, b;
    while (cin >> n >> q) {
        int com[n];
        for (int i = 0; i < n; i++) {
            cin >> x;
            com[i] = x;
        }
        
        
        while (q--) {
            cin >> t >> a >> b;
            if (t == 2) {
                cout << abs(com[a-1] - com[b-1]) << endl;
            } else { // t == 1
                com[a-1] = b;
            }
        }
    }
    
    return 0;
}
