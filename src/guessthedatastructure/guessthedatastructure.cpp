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

int main() {
    int n;
    while (cin >> n) {
        bool isQueue = true, isStack = true, isPriorityQueue = true;
        queue<int> q;
        stack<int> s;
        priority_queue<int> pq;

        for (int i = 0; i < n; i++) {
            int type, value;
            cin >> type >> value;
            if (type == 1) {
                q.push(value);
                s.push(value);
                pq.push(value);
            } else if (type == 2) {
                // Prevent Empty
                if (q.empty()) {
                    isQueue = false;
                    isStack = false;
                    isPriorityQueue = false;
                    // break;
                }


                if (isQueue) {
                    if (q.front() != value) {
                        isQueue = false;
                    }
                    q.pop();
                }

                if (isStack) {
                    if (s.top() != value) {
                        isStack = false;
                    }
                    s.pop();
                }

                if (isPriorityQueue) {
                    if (pq.top() != value) {
                        isPriorityQueue = false;
                    }
                    pq.pop();
                }

                // if (isQueue) {
                //     if (q.empty() || q.front() != value) {
                //         isQueue = false;
                //     } else {
                //         q.pop();
                //     }
                // }

                // if (isStack) {
                //     if (s.empty() || s.top() != value) {
                //         isStack = false;
                //     } else {
                //         s.pop();
                //     }
                // }

                // if (isPriorityQueue) {
                //     if (pq.empty() || pq.top() != value) {
                //         isPriorityQueue = false;
                //     } else {
                //         pq.pop();
                //     }
                // }
            }
        }

        if ((isQueue && isStack) || (isQueue && isPriorityQueue) || (isStack && isPriorityQueue)) {
            cout << "not sure" << endl;
        } else if ((!isQueue) && (!isStack) && (!isPriorityQueue)) {
            cout << "impossible" << endl;
        } else if (isQueue) {
            cout << "queue" << endl;
        } else if (isStack) {
            cout << "stack" << endl;
        } else {
            cout << "priority queue" << endl;
        }

    }

    return 0;
}
