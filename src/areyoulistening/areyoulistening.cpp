#include <iostream>
#include <sstream>
#include <stdexcept>

#include <vector>
#include <string>
#include <map>
#include <set>

#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    cerr << "hello, world" << endl;

    int cx, cy, n;
    cin >> cx >> cy >> n;

    vector<int> maxranges;

    for (int i = 0; i < n; i++) {
        int x, y, r;
        cin >> x >> y >> r;

        int a = abs(cx - x);
        int b = abs(cy - y);
        int distance = sqrt(pow(a, 2) + pow(b, 2)) - r;

        maxranges.push_back(distance);
    }

    sort(maxranges.begin(), maxranges.end());

    for (int i = 0; i < n; i++) {
        cerr << maxranges[i] << ",";
    }
    cerr << endl;

    int mr = maxranges[2];
    if (mr < 0) {
        mr = 0;
    }
    cout << mr << endl;


    return 0;
}



int helper() {
    return 0;
}