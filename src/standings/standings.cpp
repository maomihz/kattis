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
    int c, n;
    string name;
    cin >> c;
    
    while (cin >> n) {
        vector<pair<int, string>> teams;
        teams.reserve(n);
        
        for (int i = 0; i < n; i++) {
            cin >> name >> c;
            teams.push_back(make_pair(c, name));
        }
        
        sort(teams.begin(), teams.end());
        
        long long sum = 0;
        for (int i = 0; i < n; i++) {
//             cerr << "teams[" << i << "]=" << teams[i].first << endl;
//             cerr << "+=" << i - teams[i].first + 1 << endl;
            sum += abs(i - teams[i].first + 1);
        }
        cout << sum << endl;
    }

    return 0;
}
