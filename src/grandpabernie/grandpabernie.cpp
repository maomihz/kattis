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

    int a;
    cin >> a;

    unordered_map<string, vector<int>> m;

    while (a--) {
        string place;
        int year;
        cin >> place >> year;

        if (m.find(place) == m.end()) {
            vector<int> v;
            v.push_back(year);
            m[place] = v;
        } else {
            m[place].push_back(year);
        }
    }

    for (auto it = m.begin(); it != m.end(); it++) {
        sort(it->second.begin(), it->second.end());
    }

    int q;
    cin >> q;

    while (q--) {
        string place;
        int index;
        cin >> place >> index;
        cout << m[place][index-1] << endl;
    }

    return 0;
}
