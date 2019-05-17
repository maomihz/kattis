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

double dist(pair<double, double> a, pair<double, double> b) {
    return (b.first - a.first) * (b.first - a.first) + (b.second + a.second) * (b.second + a.second);
}

int main() {
//     cerr << "hello, world" << endl;
    
    double l, w, n, r;
    cin >> l >> w >> n >> r;
    
    vector<pair<double, double>> cranes;
    vector<pair<double, double>> walls;
    
    walls.push_back(make_pair(-l / 2, 0));
    walls.push_back(make_pair(l / 2, 0));
    walls.push_back(make_pair(0, -w / 2));
    walls.push_back(make_pair(0, w / 2));
//     for (auto i : walls) {
//         cerr << i.first << "," << i.second << endl;
//     }
    
    while (n--) {
        double x, y;
        cin >> x >> y;
        cranes.push_back(make_pair(x, y));
    }
    
    
    // Case 1: one crane to reach all of them
    for (int i = 0; i < cranes.size(); i++) {
        int sum = 0;
        for (int w = 0; w < walls.size(); w++) {
            auto a = cranes.at(i);
            auto b = walls.at(w);
            if (dist(a, b) <= r * r) {
                sum |= 1 << w;
            }
        }
        if (sum == 15) {
            cout << 1 << endl;
            return 0;
        }
    }
    
    
    // Case 2: two cranes
    for (int i = 0; i < cranes.size(); i++) {
        for (int j = 0; j < cranes.size(); j++) {
            if (i == j) continue;
            int sum = 0;
            for (int w = 0; w < walls.size(); w++) {
                auto a = cranes.at(i);
                auto b = cranes.at(j);
                auto c = walls.at(w);
                if (dist(a, c) <= r * r) {
                    sum |= 1 << w;
                } else if (dist(b, c) <= r * r) {
                    sum |= 1 << w;
                }
            }
            if (sum == 15) {
                cout << 2 << endl;
                return 0;
            }
        }
    }
    
    // Case 3: three cranes
    for (int i = 0; i < cranes.size(); i++) {
        for (int j = 0; j < cranes.size(); j++) {
            for (int k = 0; k < cranes.size(); k++) {
                if (i == j || i == k || j == k) {
                    continue;
                }
                int sum = 0;
                for (int w = 0; w < walls.size(); w++) {
                    auto a = cranes.at(i);
                    auto b = cranes.at(j);
                    auto c = cranes.at(k);
                    auto d = walls.at(w);
                    if (dist(a, d) <= r * r) {
                        sum |= 1 << w;
                    } else if (dist(b, d) <= r * r) {
                        sum |= 1 << w;
                    } else if (dist(c, d) <= r * r) {
                        sum |= 1 << w;
                    }
                }
                if (sum == 15) {
                    cout << 3 << endl;
                    return 0;
                }
            }
        }
    }
    
    // Case 4: four cranes
    int sum = 0;
    for (int i = 0; i < cranes.size(); i++) {
        for (int w = 0; w < walls.size(); w++) {
            auto a = cranes.at(i);
            auto b = walls.at(w);
            if (dist(a, b) <= r * r) {
                sum |= 1 << w;
            }
        }
    }
    if (sum == 15) {
        cout << 4 << endl;
        return 0;
    }
    
    cout << "Impossible" << endl;

    

    return 0;
}
