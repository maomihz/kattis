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
    cerr << "hello, world" << endl;

    long long x, y;

    while (cin>>x>>y) {
        if (x > y) {
            cout << x - y << endl;
        } else {
            cout << y - x << endl;
        }
    }

    return 0;
}
