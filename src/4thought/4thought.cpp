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

    unordered_map<int, string> m = {
{256, "4 * 4 * 4 * 4"},
{68, "4 + 4 * 4 * 4"},
{60, "4 * 4 * 4 - 4"},
{16, "4 / 4 * 4 * 4"},
{32, "4 * 4 + 4 * 4"},
{24, "4 + 4 + 4 * 4"},
{17, "4 / 4 + 4 * 4"},
{0, "4 / 4 / 4 / 4"},
{8, "4 / 4 * 4 + 4"},
{15, "4 * 4 - 4 / 4"},
{1, "4 / 4 - 4 + 4"},
{9, "4 / 4 + 4 + 4"},
{-8, "4 - 4 - 4 - 4"},
{7, "4 - 4 / 4 + 4"},
{4, "4 / 4 / 4 + 4"},
{-60, "4 - 4 * 4 * 4"},
{-16, "4 - 4 - 4 * 4"},
{-1, "4 - 4 / 4 - 4"},
{2, "4 / 4 + 4 / 4"},
{-15, "4 / 4 - 4 * 4"},
{-7, "4 / 4 - 4 - 4"},
{-4, "4 / 4 / 4 - 4"},
    };

    
    int n;
    cin >> n;
    int x;
    while (cin >> x) {
        if (m.find(x) == m.end()) {
            cout << "no solution" << endl;
        } else {
            cout << m[x] << " = " << x << endl;
        }
    }

    

    return 0;
}
