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

struct State {
    int price;
    int power;
    int location;
    
    State() {
        price = 0;
        power = 0;
        location = 0;
    }
    State(const State& another) {
        price = another.price;
        power = another.power;
        location = another.location;
    }
    
    bool operator()(State& a, State& b) {
        return a.price < b.price;
    }
};

int main() {
    int n;
    cin >> n;
    
    vector<int> price;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        price.push_back(x);
    }
    
    State init;
    
    queue<State> pq;
    pq.push(init);
    
//     bool stop = false;
    int min = INT_MAX;
    
    while (!pq.empty()) {
        const State s = pq.front();
//         cerr << s.location + 1 << " " << s.price << endl;
//         if (s.location == n - 1) {
//             stop = true;
//         }
//         cout << s.location << endl;
        pq.pop();
        
        if (s.location == n - 1) {
            if (s.price < min) {
                min = s.price;
            }
        } else {
            State n1(s);
            n1.location += s.power + 1;
            if (n1.location < n) {
                n1.price+= price[n1.location];
                n1.power++;
                pq.push(n1);
            }
            
            State n2(s);
            n2.location -= s.power;
            if (s.power > 0 && n2.location >= 0) {
                n2.price+= price[n2.location];
                pq.push(n2);
            }
        }
    }
    cout << min << endl;
    
    
    

    return 0;
}
