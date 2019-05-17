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

typedef pair<double, double> coord;

vector<coord> coords;

// Calculate max distance given a meeting location x
double max_dist(double x) {
    // (x, 0)
    double maxdist = 0;
    for (coord& c : coords) {
        double dist = (c.first - x) * (c.first - x) + c.second * c.second;
        maxdist = max(maxdist, dist);
    }
    return maxdist;
}

int main() {
    int n;
    while (cin >> n, n != 0) {
        coords.clear();
        while (n--) {
            double x, y;
            cin >> x >> y;
            coords.push_back(make_pair(x, y));
        }
        
    
        double left  = -200000;
        double right = 200000;

        while (fabs(left - right) > 0.00000001) {
            // Divide into three parts, and then search
            double midl = left + (right - left) / 3;
            double midr = left + (right - left) / 3 * 2;
            double max_midl = max_dist(midl);
            double max_midr = max_dist(midr);
            
            if (max_midl < max_midr) {
                right = midr;
            } else {
                left = midl;
            }
        }
        
        printf("%.8f %.8f\n", left, sqrt(max_dist(left)));
    }

    return 0;
}
