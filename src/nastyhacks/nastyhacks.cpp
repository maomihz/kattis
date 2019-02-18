#include <iostream>
#include <stdexcept>

#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
    cerr << "hello, world" << endl;

    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int r, e, c;
        cin >> r >> e >> c;

        if ((r + c) < e) {
            cout << "advertise" << endl;
        } else if (r + c == e) {
            cout << "does not matter" << endl;
        } else {
            cout << "do not advertise" << endl;
        }
    }

    return 0;
}



int helper() {
    return 0;
}