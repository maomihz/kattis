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
    cin >> n;
    int c,x;
    while (n--) {
        cin >> c >> x;
        cout << c << " " << (1+x) * x / 2 + x << endl;
    }
    

    return 0;
}


