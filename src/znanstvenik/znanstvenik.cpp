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
    int r, c;
    char ch;
    while (cin >> r >> c) {
        char cr[c][r+1];
        // Rebuild the string, from bottom to top transpose
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> cr[j][r - i - 1];
            }
        }
        
        vector<string> st;
        st.reserve(c);
        
        for (int i = 0; i < c; i++) {
            cr[i][r] = '\0';
            st.push_back(cr[i]);
        }
        sort(st.begin(), st.end());
        
//         for (int i = 0; i < c; i++) {
//             cout << st[i] << endl;
//         }
        
        int ans = 0;
        for (int i = 1; i < c; i++) {
            int count = 0;
            for (int j = 0; j < r; j++) {
                if (st[i][j] == st[i-1][j]) count++;
                else break;
            }
            ans = max(ans, count);
        }
        
        cout << r - ans - 1 << endl;
        
    }
    return 0;
}
