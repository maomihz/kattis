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
    
    int cs;
    cin >> cs;
    for (int i = 1; i <= cs; i++) {
        int n;
        cin >> n;
        vector<long long> a, b;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            b.push_back(x);
        }
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<int>());
        
        long long product = 0;
        for (int j = 0; j < n; j++) {
            product += a.at(j) * b.at(j);
        }
        cout << "Case #" << i << ": " << product << endl;
    }
    

    

    return 0;
}
