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
    int n;
    cin >> n;
    string s;
    
    unordered_map<string, int> count1, count2;
    
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (count1.find(s) == count1.end()) {
            count1[s] = 0;
        }
        count1[s] ++;
    }
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (count2.find(s) == count2.end()) {
            count2[s] = 0;
        }
        count2[s] ++;
    }
    
    int total = 0;
    for (auto it = count1.begin(); it != count1.end(); it++) {
        if (count2.find(it->first) != count2.end()) {
            total += min(count2[it->first], it->second);
        }
    }
    cout<<total<<endl;
    
    
    return 0;
}
