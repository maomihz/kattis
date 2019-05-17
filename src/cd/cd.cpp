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
    int m, n;
    int a, b, c;
    
    while (cin >> m >> n, m != 0 && n != 0) {
        int mown[m], nown[n];
        
        for (int i = 0; i < m; i++) {
            cin >> mown[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> nown[i];
        }
        
        a = b = c = 0;
        
        while (a < m || b < n) {
            if (mown[a] == nown[b]) {
                c++;
                a++;
                b++;
            } else if (mown[a] > nown[b]) {
                b++;
            } else {
                a++;
            }
        }
        cout << c << endl;
    }

    return 0;
}
