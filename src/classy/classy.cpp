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

bool s(pair<int, string> a, pair<int, string> b) {
    if (a.first > b.first) {
        return true;
    }
    if (a.first < b.first) {
        return false;
    }
    return a.second < b.second;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        // vector<int>
        vector<pair<int, string>> items;
        while (n--) {
            string name, cls, trash;
            cin >> name >> cls >> trash;
            name.erase(name.end() - 1);


            int N = 10;
            int digits[N];
            for (int i = 0; i < N; i++) {
                digits[i] = 1;
            }

            // cerr << name << cls << trash;

            int count = N - 1;
            for (int i = cls.size() - 1; i >= 0; i--) {
                if (cls[i] == 'u') { // Upper
                    digits[count--] = 2;
                } else if (cls[i] == 'o') { // lOwer
                    digits[count--] = 0;
                } else if (cls[i] == 'm') { // Middle
                    digits[count--] = 1;
                }
            }

            for (int i = 0; i < N; i++) {
                cerr << digits[i] << " ";
            }
            cerr << endl;

            int sum = 0;
            int current = 1;
            for (int i = 0; i < N; i++) {
                sum += digits[i] * current;
                current *= 3;
            }

            items.push_back(make_pair(sum, name));
        }

        sort(items.begin(), items.end(), s);
        // reverse(items.begin(), items.end());
        for (int i = 0; i < items.size(); i++) {
            cout << items.at(i).second;
            cerr << " " << items.at(i).first;
            cout << endl;
        }
        cout << "==============================" << endl;
    }

    return 0;
}
