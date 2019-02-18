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

#include <algorithm>

using namespace std;

int main() {
    cerr << "hello, world" << endl;
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<string> numbers;

        for (int j = 0; j < n; j++) {
            string x;
            cin >> x;

            numbers.push_back(x);
            cerr << "!" << x << endl;
        }
        sort(numbers.begin(), numbers.end());

        bool yes = true;
        for (int j = 0; j < n - 1; j++) {
            string& s0 = numbers.at(j);
            string& s1 = numbers.at(j+1);
            if (s0.size() <= s0.size()) {
                if (s0 == s1.substr(0, s0.size())) {
                    cerr << s0 << ":" << s1 << endl;
                    yes = false;
                    break;
                }
            }
        }

        cout << (yes ? "YES" : "NO") << endl;





    }

    return 0;
}
