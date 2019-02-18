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

int main() {
    cerr << "hello, world" << endl;

    int n;
    cin >> n;

    unordered_map<int, int> seats;

    bool no = true;
    int min = INT_MAX;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (seats.find(x) != seats.end()) {
            no = false;
            if (i - seats[x] < min) {
                min = i - seats[x];
            }
        }
        seats[x] = i;
    }

    if (no) {
        cout << n << endl;
    } else {
        cout << min << endl;
    }



    return 0;
}
