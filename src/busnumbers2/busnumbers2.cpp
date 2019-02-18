#include <iostream>
#include <stdexcept>

#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
    cerr << "hello, world" << endl;
    vector<int> busnumbers = {
        1729, 4104, 13832, 20683, 32832, 39312, 40033, 46683, 64232, 65728, 110656, 110808, 134379, 149389, 165464, 171288, 195841, 216027, 216125, 262656, 314496, 320264, 327763, 373464, 402597, 439101, 443889, 513856
    };

    int m;
    cin >> m;

    bool done = false;
    for (int i = 0; i < busnumbers.size(); i++) {
        if (busnumbers[i] > m) {
            if (i > 0) {
                cout << busnumbers[i - 1] << endl;
                done = true;
            }
            break;
        }
    }

    if (!done) {
        cout << "none" << endl;
    }

    return 0;
}



int helper() {
    return 0;
}