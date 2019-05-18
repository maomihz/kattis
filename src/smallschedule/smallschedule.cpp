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
    int q,m,s,l;
    cin >> q >> m >> s >> l;
    
    int t = ((l + m - 1) / m * q);
    int rem = (m - l % m) * q;
    if (l % m == 0) rem = 0;
    s -= rem;
    
    if (s > 0) {
        t += (s + m - 1) / m;
    }
    
    cout << t << endl;
    
    return 0;
}


