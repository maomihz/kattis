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

    int n;
    cin >> n;
    vector<int> p;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        p.push_back(x);
    }
    sort(p.begin(), p.end(), greater<int>());
    long long sum = 0;
    for (int i = 0; i < n / 3; i++) {
        sum += p.at(i * 3 + 2);
    }
    cout << sum << endl;

    return 0;
}
