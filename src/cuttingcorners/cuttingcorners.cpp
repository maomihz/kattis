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

#include <cmath>

#include <stdio.h>
#include <stdlib.h>

using namespace std;

double dist(pair<int, int> v1, pair<int, int> v2) {
    int a = abs(v1.first  - v2.first);
    int b = abs(v1.second - v2.second);
    
    return sqrt(a * a + b * b);
}

double angle(pair<int, int> v1, pair<int, int> v2, pair<int, int> v3) {
    double g1 = atan2(v1.second - v2.second, v1.first - v2.first);
    double g2 = atan2(v3.second - v2.second, v3.first - v2.first);
    
    double a = g2 - g1;
    if (a < 0) a += 2 * M_PI;
    return a * 180 / M_PI;
}

double vangle(vector<pair<int, int>>& v, int index) {
    double a = angle(
        v.at((index - 1 + v.size()) % v.size()),
        v.at((index)     % v.size()),
        v.at((index + 1) % v.size()));
    
    return a;
}

vector<pair<int, int>> cut(vector<pair<int, int>> v, bool& docut) {
    docut = false;
    if (v.size() <= 3) return v;
    
    int ang = 1000;
    int idx = 0;
    for (int i = 0; i < v.size(); i++) {
        double a = vangle(v, i);
//         cerr << a << ", ";
        if (a < ang) {
            ang = a;
            idx = i;
        }
    }
//     cerr << " idx = " << idx;
//     cerr << endl;
    
    v.erase(v.begin() + idx);
    if (vangle(v, idx) >= ang && vangle(v, idx - 1) >= ang) {
        docut = true;
    }
    return v;
}

int main() {
    int n, a, b;
    while (cin >> n, n != 0) {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            v.push_back(make_pair(a, b));
        }
        bool cont = true;
//         cout << vangle(v, 0) << endl;
        
        while (true) {
            vector<pair<int, int>> v2 = cut(v, cont);
            if (cont) {
                v = v2;
            } else {
                break;
            }
        }
        
        cout << v.size() << " ";
        for (pair<int, int> pv : v) {
            cout << pv.first << " " << pv.second << " ";
        }
        cout << endl;
        
    }
    
    
//     cout << dist(make_pair(1, 1), make_pair(10, 3)) << endl;
//     cout << dist(make_pair(5, 3), make_pair(9, 6)) << endl;
//     cout << angle(make_pair(5, 0), make_pair(0, 0), make_pair(-5, -1)) << endl;
//     cout << angle(make_pair(5, 0), make_pair(0, 0), make_pair(-5, 1)) << endl;
//     cout << angle(make_pair(4, 0), make_pair(0, 3), make_pair(4, 7)) << endl;

    return 0;
}
