#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <climits>

using namespace std;

unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y'};

int get(string s) {
    int count = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        if (vowels.find(s.at(i)) != vowels.end()) {
            if (s.at(i) == s.at(i + 1)) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    cerr << "hello, world" << endl;

    while (true) {
        int x;
        cin >> x;
        cerr << "!x = " << x << endl;

        if (x == 0) break;

        string bestword;
        cin >> bestword;
        int bestcount = get(bestword);
        

        for (int i = 1; i < x; i++) {
            string s;
            cin >> s;
            cerr << "!" << s << endl;
            int count = get(s);

            if (count > bestcount) {
                bestcount = count;
                bestword = s;
            }
        }

        cout << bestword << endl;
    }

    return 0;
}
