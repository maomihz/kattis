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

#define long long int

int get(int n, int x, int y) {
    if (n <= 1) return 1;
    else {
        int half = n / 2;
        int next = get(half, x % half, y % half);
        
        if (x >= half && y >= half) {
            return -next;
        }
        return next;
    }
}



int main() {
    int c,n,x,y,w,h;
    cin >> c;
    
    for (int i = 0; i < c; i++) {
        cin >> n >> y >> x >> w >> h;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cout << get(n, x + i, y + j) << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    

    return 0;
}
