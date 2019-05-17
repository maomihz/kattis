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

int main2() {
    int n, t;
    while (scanf("%d %d", &n, &t) != EOF) {
        vector<pair<int, int>> people;
        
        for (int i = 0; i < n; i++) {
            int ci, ti;
            scanf("%d %d", &ci, &ti);
            people.push_back(make_pair(ci, ti));
        }
        
        int L[n + 1][t + 1];
        for (int b = 0; b <= n; b++) {
            for (int a = 0; a <= t; a++) {
                if (b == 0 || a == 0) {
                    L[a][b] = 0;
                } else {
                    if (people[b - 1].second >= a - 1) {
                        L[a][b] = max(L[a][b - 1], people[b - 1].first + L[a - 1][b - 1]);
                    } else {
                        L[a][b] = max(L[a - 1][b], L[a][b - 1]);
                    }
                }
                fprintf(stderr, "%15d ", L[a][b]);
            }
            fprintf(stderr, "\n");
        }
        
        printf("%d\n", L[n][t]);
    }
    
    
    return 0;
}

int main() {
    
    int n, t;
    while (scanf("%d %d", &n, &t) != EOF) {
        vector<int> people[t];
        
        for (int i = 0; i < n; i++) {
            int ci, ti;
            scanf("%d %d", &ci, &ti);
            people[ti].push_back(ci);
        }
    
        priority_queue<int> choices;
        long long sum = 0;
        for (int i = t - 1; i >= 0; i--) {
            for (int x : people[i]) {
                choices.push(x);
            }
            if (!choices.empty()) {
                sum += choices.top();
                choices.pop();
            }
        }
        cout << sum << endl;
    }
    
    
    
    
    return 0;
}
