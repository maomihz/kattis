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

int lcs(string x, string y) {
    int mylcs[x.size()+1][y.size()+1];
    
    for (int i = 0; i <= x.size(); i++) {
        for (int j = 0; j <= y.size(); j++) {
            if (i == 0 || j == 0) {
                mylcs[i][j] = 0;
            } else if (x[i - 1] == y[j - 1]) {
                mylcs[i][j] = mylcs[i - 1][j - 1] + 1;
            } else {
                mylcs[i][j] = max(mylcs[i - 1][j], mylcs[i][j - 1]);
            }
        }
    }
    return mylcs[x.size()][y.size()];
}

int sub(string x, string y) {
    int begin, end;
    for (begin = 0; begin < x.size() && begin < y.size(); begin++) {
        if (x[begin] != y[begin]) {
            break;
        }
    }
    
    for (end = 0; end < x.size() - begin && end < y.size() - begin; end++) {
//         cerr << x[x.size() - i] << ":" << y[(y.size() - i)] << endl;
        if (x[x.size() - end - 1] != y[y.size() - end - 1]) {
            break;
        }
    }
//     cerr << end << ":" << begin << endl;
    return y.size() - end - begin;
}

int main() {
//     cerr << "hello, world" << endl;

    string x, y;
    while (cin >> x >> y) {
//         if (x.size() <= y.size()) {
//             cout << y.size() - lcs(x, y) << endl;
//         } else {
//             cout << sub(x, y) << endl;
//         }
        cout << sub(x, y) << endl;
    }
    
    

    return 0;
}
