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
//     cerr << "hello, world" << endl;

    int n,h;
    scanf("%d %d", &n, &h);
    
    vector<int> up, down;
    int o_up[h];
    int o_down[h];
    
    for (int i = 0; i < h; i++) {
        o_up[i] = 0;
        o_down[i] = 0;
    }
    
    // Read
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        ((i & 1) ? up : down).push_back(x);
    }
    sort(up.begin(), up.end());
    sort(down.begin(), down.end());
    
    int down_i = 0;
    int up_i = 0;
    for (int i = 0; i < h; i++) {
        while (down_i < down.size() && down[down_i] <= i) {
            down_i++;
        }
        o_down[i] = down.size() - down_i;
        
        while (up_i < up.size() && up[up_i] <= i) {
            up_i++;
        }
        o_up[h - i - 1] = up.size() - up_i;
    }
    
    // Down 1 2 3 3 3 3 4
    //  (5) 7 6 5 1 0

    // Up   2 2 3 3 3 4 4
    //      7 7 5 2 0
    //    R 0 2 5 7 7


    // Down 1 3 5
    //  (7) 3 2 2 1 1 0 0
    // Up   1 3 5
    //      3 2 2 1 1 0 0
    //    R 0 0 1 1 2 2 3
    
    
    
    int min = INT_MAX;
    int min_count = 0;
    for (int i = 0; i < h; i++) {
        int s = o_up[i] + o_down[i];
        if (s < min) {
            min = s;
            min_count = 1;
        } else if (min == s) {
            ++min_count;
        }
    }
    
//     cerr << "Down: ";
//     for (int i : down) {
//         cerr << i << " ";
//     }
//     cerr << endl;
//     cerr << "Up: ";
//     for (int i : up) {
//         cerr << i << " ";
//     }
//     cerr << endl;
//     for (int i = 0; i < h; i++) {
//         cerr << o_down[i] << " ";
//     }
//     cerr << endl;
//     for (int i = 0; i < h; i++) {
//         cerr << o_up[i] << " ";
//     }
//     cerr << endl;
//     cerr << "> ";
//     for (int i : result) {
//         cerr << i << " ";
//     }
//     cerr << endl;
    
    
//     sort(result.begin(), result.end());
//     cerr << "> ";
//     for (int i : result) {
//         cerr << i << " ";
//     }
//     cerr << endl;
//     int repeat_count = 1;
//     while (repeat_count < result.size()) {
//         if (result.at(0) != result.at(repeat_count)) {
//             break;
//         }
//         repeat_count++;
//     }
    printf("%d %d\n", min, min_count);
    
    return 0;
}

 

