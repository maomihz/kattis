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
#include <cstring>

using namespace std;


int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int x;
        cin >> x;
        vector<int> v;
        while (x--) {
            int a;
            cin >> a;
            v.push_back(a);
        }
        
        // Initialize cells
        int table[n + 1];
        memset(table, -1, sizeof table);
        
        for (int i = 0; i < v.size(); i++) {
            table[v[i]] = 1;
        }
        
        for (int i = 0; i < n + 1; i++) {
            if (table[i] == -1) {
                table[i] = 0;
                for (int j = 0; j < v.size(); j++) {
                    int diff = i - v[j];
                    if (diff > 0 && table[diff] == 0) {
                        table[i] = 1;
                        break;
                    }
                }
            }
        }
        
        if (table[n] == 0) {
            cout << "Ollie wins" << endl;
        } else {
            cout << "Stan wins" << endl;
        }
        
    }
    
    return 0;
}
