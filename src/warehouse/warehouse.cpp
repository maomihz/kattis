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

bool sorter(pair<int, string>& p1, pair<int, string>& p2) {
    if (p1.first != p2.first) {
        return p1.first >= p2.first;
    } else {
        return p1.second < p2.second;
    }
}

int main() {
    cerr << "hello, world" << endl;

    int t;
    cin >> t;
    while (t--) {
        int c;
        cin >> c;
        unordered_map<string, int> m;
        while (c--) {
            string name;
            int x;
            cin >> name >> x;
            if (m.find(name) == m.end()) {
                m[name] = x;
            } else {
                m[name] += x;
            }
        }

        vector<pair<int, string>> result;

        for (auto it = m.begin(); it != m.end(); it++) {
            result.push_back(make_pair(it->second, it->first));
        }
        sort(result.begin(), result.end(), sorter);

        cout << result.size() << endl;
        for (pair<int, string> p : result) {
            cout << p.second << " " << p.first << endl;
        }
    }

    return 0;
}
