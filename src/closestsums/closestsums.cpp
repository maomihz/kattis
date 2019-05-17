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
    int n, m, x;
    int count = 1;
    while (cin >> n) {
        vector<int> numbers, queries;
        
        for (int i = 0; i < n; i++) {
            cin >> x;
            numbers.push_back(x);
        }
        
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> x;
            queries.push_back(x);
        }
        
        sort(numbers.begin(), numbers.end());
        
        
        printf("Case %d:\n", count++);
        for (int query : queries) {
            auto l = numbers.begin();
            auto r = numbers.end() - 1;
            int bestdiff = INT_MAX;
            
            while (l != r) {
                int sum = (*l) + (*r);
                int diff = sum - query;
                
                if (abs(diff) < abs(bestdiff)) {
                    bestdiff = diff;
                }
                
                if (bestdiff == 0) break;
                
                if (sum > query) r--;
                else l++;
            }
            printf("Closest sum to %d is %d.\n", query, query + bestdiff);
        }
    }
    

    return 0;
}
