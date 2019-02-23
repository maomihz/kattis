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
    
    vector<int> n;
    for (int i = 0; i < 3; i++) {
        int x;
        cin >> x;
        n.push_back(x);
    }
    sort(n.begin(), n.end());
    int x = 0;
    for (int i = 0; i < 2; i++) {
        x = max(x, n[i+1]-n[i]);
    }
    
    cout << x - 1 << endl;
    

    return 0;
}
