#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <climits>
#include <queue>

#include <algorithm>

using namespace std;

int main() {
    cerr << "hello, world" << endl;

    vector<int> q;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push_back(x);
    }

    sort(q.begin(), q.end());


    int count = 0;
    while (!q.empty()) {
        auto x = q.end() - 1;
        if (*x > q.size()) {
            q.erase(x);
        } else {
            for (int a = 0; a < q.size();) {
                if (q.at(a) <= 1) {
                    q.erase(q.begin() + a);
                } else {
                    q.at(a) -= 1;
                    a++;
                }
            }
        }
        count ++;
    }
    cout << count << endl;

    return 0;
}
