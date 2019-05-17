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
    int n, x;
    while (cin >> n) {
        // Initial A2 paper size
        double size = pow(2, -3.0 / 4);
        double tape = 0;
        
        // Now I want one A1 paper, but I don't have any.
        double need = 1;
        for (int i = 2; i <= n && need > 0; i++) {
            cin >> x;
            tape += need * size; // Extend tape size
            need = need * 2 - x;
            size /= sqrt(2);
        }
        
        if (need > 0) {
            cout << "impossible" << endl;
        } else {
            cout << setprecision(10) << tape << endl;
        }
    }
    
    return 0;
}
