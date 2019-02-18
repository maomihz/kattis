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
#include <stack>
#include <climits>
#include <algorithm>

using namespace std;


class median_queue {
private:
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;

    void balance() {
        while (pq1.size() < pq2.size()) {
            pq1.push(pq2.top());
            pq2.pop();
        }

        while (pq1.size() > pq2.size()) {
            pq2.push(pq1.top());
            pq1.pop();
        }

    }

public:
    void push(int e) {
        // cerr << "PUSH " << e << endl;
        if (pq2.empty() || e >= pq2.top()) {
            pq2.push(e);
        } else {
            pq1.push(e);
        }
        balance();
    }

    int pop() {
        // cerr << "POP" << endl;
        int x = pq2.top();
        pq2.pop();
        balance();
        return x;
    }

};

int main() {
    string s;
    median_queue q;

    while (cin >> s) {
        if (s == "#") {
            cout << q.pop() << endl;
        } else {
            int n = stoi(s);
            q.push(n);
        }
    }

    return 0;
}
