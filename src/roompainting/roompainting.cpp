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

struct dp {
    int* arr;
    vector<int>* paints;
    dp(int max_goal, vector<int>& p) {
        arr = new int[max_goal];
        paints = &p;
        
        for (int goal = 1; goal <= max_goal; goal++) {
            int minval = INT_MAX;
            
            for (int i = 0; i < paints->size(); i++) {
                int volume = paints->at(i);
                int value = volume + get(goal - volume);
                
                if (value >= goal && value < minval) {
                    minval = value;
                }
                if (minval == goal) break;
            }
            set(goal, minval);
        }
    }
    
    int get(int i) {
        if (i <= 0) {
            return 0;
        }
        return arr[i - 1];
    }
    int set(int i, int value) {
        arr[i - 1] = value;
    }
};

int main0() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    vector<int> paints, goals;
//     bool seen[1001];
//     for (int i = 0; i < 1001; i++) {
//         seen[i] = false;
//     }
    
    while (n--) {
        int x;
        scanf("%d", &x);
//         if (!seen[x]) {
            paints.push_back(x);
//             seen[x] = true;
//         }
    }
    
    int max_goal = 0;
    while (m--) {
        int x;
        scanf("%d", &x);
        goals.push_back(x);
        
        if (x > max_goal) {
            max_goal = x;
        }
    }
    
    
    int sum = 0;
    dp dp1(max_goal, paints);
    
    for (int i = 0; i < goals.size(); i++) {
        int goal = goals[i];
        sum += dp1.get(goal) - goal;
    }
    
    printf("%d\n", sum);

    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    vector<int> paints, goals;
    
    while (n--) {
        int x;
        scanf("%d", &x);
        paints.push_back(x);
    }
    
    while (m--) {
        int x;
        scanf("%d", &x);
        goals.push_back(x);
    }
    
    sort(paints.begin(), paints.end());
    sort(goals.begin(), goals.end());
    
    long long sum = 0;
    int i = 0;
    
    for (int goal : goals) {
        // Find the smallest paint can that satisfies the need
        while (paints[i] < goal) i++;
        sum += paints[i] - goal;
    }
    
    
    cout << sum << endl;
    
    return 0;
}
