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
    int v,a,b;
    cin >> v;
    
    while (cin >> v) {
        a = 1;
        b = 2;
        
        while (v--) {
            int tmp = a;
            a = b;
            b = (b + tmp) % (int)(1e9+7);
        }
        
        cout << a << endl;
    }
    
    

    return 0;
}


