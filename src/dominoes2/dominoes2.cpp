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

void knock(bool* knocked, unordered_set<int>* domino, int start) {
    if (knocked[start]) return;
    knocked[start] = true;
    for (int x : domino[start]) {
        knock(knocked, domino, x);
    }
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        int n,m,l,a,b,x,count;
        cin >> n >> m >> l;
        unordered_set<int> domino[n];
        bool knocked[n];
        
        for (int i = 0; i < n; i++) {
            knocked[i] = false;
        }
        
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            domino[a - 1].insert(b - 1);
        }
        
        for (int i = 0; i < l; i++) {
            cin >> x;
            knock(knocked, domino, x - 1);
        }
        
        count = 0;
        for (int i = 0; i < n; i++) {
            if (knocked[i]) count++;
        }
        cout << count << endl;
    }
        

    return 0;
}
