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
#include <stack>
#include <climits>
#include <algorithm>

using namespace std;


int main() {
    int n;
    cin >> n;
    for (int c = 0; c < n; c++) {
        int light, snaps;
        cin >> light >> snaps;
        
        int x = 1 << light;

        cout << "Case #" << c + 1 << ": "
             << (x - 1 == snaps % x ? "ON" : "OFF") << endl;
    }

    return 0;
}
