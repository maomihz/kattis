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

using namespace std;

int main() {
    cerr << "hello, world" << endl;

    int l, d, n;
    cin >> l >> d >> n;

    if (l < 12) {
        cout << 0 << endl;
        return 0;
    }
    priority_queue<int> pq;

    pq.push(6 - d);
    pq.push(l - 6 + d);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }

    int total = 0;

    for (int i = 0; i < n + 1; i++) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();

        int space = a - b - d - d;
        int birds = (space / d) + 1;

        if (space >= 0) {
            total += birds;
        }
        cerr << a << " and " << b << "(" << space << ")" << " holds " << birds << " birds" << endl;
    }

    cout << total << endl;

    return 0;
}
