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

    string line;
    while (getline(cin, line)) {
        int n = atoi(line.c_str());
        if (n == 0) break;


        int fcount = 0;
        int ccount = 0;
        vector<string> items[256];
        int collision[256];
        for (int x = 0; x < 256; x++) collision[x] = 0;

        while (n--) {
            getline(cin, line);
            char hash = 0;
            for (char c : line) {
                hash = hash ^ c;
            }
            // cerr << "hash is " << (int) hash << endl;

            int cc = 0;
            bool ok = true;
            for (int i = 0; i < items[hash].size(); i++) {
                if (items[hash][i] != line) {
                    cc++;
                } else
                {
                    ok = false;
                }
            }

            ccount += cc;


            if (ok) {
                fcount ++;
            }

            items[hash].push_back(line);
        }

        cout << fcount << " " << ccount << endl;
    }


    return 0;
}
