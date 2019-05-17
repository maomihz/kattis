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

int find(string a, string b) {
    int i;
    for (i = 0; i < a.size(); i++) {
        bool done = true;
        for (int j = 0; j < a.size() - i; j++) {
            if (b[j] != a[j+i]) {
                done = false;
                break;
            }
        }
        if (done) break;
    }
    return i;
}

int main() {
    int c,k,w;
    string word, last;
    cin >> c;
    
    while (c--) {
        cin >> k >> w;
        int sum = k;
        cin >> last;
        
        for (int i = 1; i < w; i++) {
            cin >> word;
            sum += find(last, word);
            last = word;
        }
        cout << sum << endl;
    }
    
//     cout << find("ABC", "AAA") << endl;

    return 0;
}
