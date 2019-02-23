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

int dist(pair<int, int> a, pair<int, int> b) {
    return 
}

int main() {
    cerr << "hello, world" << endl;
    
    int l, w, n, r;
    cin >> l >> w >> n >> r;
    
    vector<pair<int, int>> cranes;
    vector<pair<int, int>> walls;
    
    walls.push_back(make_pair(-l / 2, 0));
    walls.push_back(make_pair(l / 2, 0));
    walls.push_back(make_pair(0, -w / 2));
    walls.push_back(make_pair(0, w / 2));
    
    while (n--) {
        int x, y;
        cin >> x >> y;
        cranes.push_back(make_pair(x, y));
    }
    
    
    // Case 1: one crane to reach all of them
    for (int i = 0; i < cranes.size(); i++) {
        bool reachable = false;
        int sum = 0;
        for (int j = 0; j < walls.size; j++) {
            auto a = cranes.at(i);
            auto b = walls.at(j);
            if (abs(a.first - b.first) * abs(a.first - b.first) + abs(a.second - b.second) * abs(a.second - b.second)) {
                
            }
        }
    }

    

    return 0;
}
