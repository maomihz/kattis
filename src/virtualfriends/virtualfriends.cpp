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
    int n;
    cin >> n;

    while (n--) {

        cerr << "case!" << endl;

        unordered_map<string, int> friends;
        vector<vector<string>> m;

        int f;
        cin >> f;

        int c = 0;
        while (f--) {
            string f1, f2;
            cin >> f1 >> f2;
            // cerr << f << ", " << f1 << ", " << f2 << endl;
            bool find1 = (friends.find(f1) != friends.end());
            bool find2 = (friends.find(f2) != friends.end());

            if (!find1 && !find2) {
                vector<string> n = {f1, f2};
                m.push_back(n);
                friends[f1] = c;
                friends[f2] = c;
                c++;
                cout << 2 << endl;
            } else if (find1 && !find2) {
                m[friends[f1]].push_back(f2);
                friends[f2] = friends[f1];
                cout << m[friends[f1]].size() << endl;
            } else if (!find1 && find2) {
                m[friends[f2]].push_back(f1);
                friends[f1] = friends[f2];
                cout << m[friends[f2]].size() << endl;
            } else if (find1 && find2) {
                int circle1 = friends.at(f1);
                int circle2 = friends.at(f2);
                // cerr << "c1 " << circle1 << " c2 " << circle2 << endl;
                if (circle1 != circle2) {
                    //merge circle
                    for (string s : m.at(circle2)) {
                        m.at(circle1).push_back(s);
                        friends[s] = circle1;
                    }
                    m.at(circle2).clear();
                }

                cout << m.at(circle1).size() << endl;
            }
        }
    }
    return 0;
}
