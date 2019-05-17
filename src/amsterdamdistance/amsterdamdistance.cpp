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
#include <iomanip>

#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
    int m, n, ax, ay, bx, by;
    double r;
    
    while (cin >> m >> n >> r >> ax >> ay >> bx >> by) {
        double slice = r * M_PI / m / n;
        double segmt = r / n;
        
        cerr << "slice=" << slice << ", segmt=" << segmt << endl;
        
        // Walk rings
        double result = abs(ax - bx) * slice * min(ay, by) + abs(ay - by) * segmt;
        double result2 = (ay + by) * segmt;
        
        cout << setprecision(15) << endl;
        cout << min(result, result2) << endl;
    }

    return 0;
}
