#include <iostream>
#include <stdexcept>

#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
    cerr << "hello, world" << endl;

    vector<char> letters;

    letters.push_back(cin.get());

    char t;
    while (cin) {
        if (cin.get() == '-') {
            letters.push_back(cin.get());
        }
    }

    for (auto x : letters) {
        cout << x;
    }
    cout << endl;

    return 0;
}



int helper() {
    return 0;
}