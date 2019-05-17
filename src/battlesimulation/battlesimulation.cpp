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
    char ch, counter;
    char moves[1000001];
    
    char check[3];
    int ci = 0; // Check index
    int mi = 0; // Move index
    
    
    while (cin >> ch) {
        if (ch == 'R') {
            counter = 'S';
        } else if (ch == 'B') {
            counter = 'K';
        } else if (ch == 'L') {
            counter = 'H';
        }
        
        moves[mi++] = counter;
        
        if (ci++ >= 2) {
            unordered_set<char> us;
            us.insert(moves[mi - 3]);
            us.insert(moves[mi - 2]);
            us.insert(moves[mi - 1]);
            if (us.size() == 3) {
                moves[mi - 3] = 'C';
                mi -= 2;
                ci = 0;
            }
        }
    }
    
    moves[mi] = '\0';
    cout << moves << endl;

    return 0;
}
