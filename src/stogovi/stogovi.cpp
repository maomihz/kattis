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

struct node {
    unordered_map<int, node*> next;
    node* prev = nullptr;
    int val;

    node* push(int x) {
        if (next.find(x) != next.end()) {
            return next[x];
        } else {
            node* no = new node;
            no->val = x;
            no->prev = this;
            return no;
        }
    }
    node* pop() {
        return prev;
    }

    unordered_set<int> set() {
        unordered_set<int> s;
        node* n = this;
        while (n->prev != nullptr) {
            s.insert(n->val);
            n = n->prev;
        }
        return s;
    }
};


int main() {
    cerr << "hello, world" << endl;

    int n;
    cin >> n;

    vector<node*> nums;

    nums.push_back(new node);
    int c = 0;

    while (n--) {
        string op;
        int arg1, arg2;

        cin >> op >> arg1;

        c++;
        if (op == "a") {
            // Push Operation
            nums.push_back(nums.at(arg1)->push(c));
        } else if (op == "b") {
            // Pop operation
            cout << nums.at(arg1)->val << endl;
            nums.push_back(nums.at(arg1)->pop());
        } else {
            cin >> arg2;
            nums.push_back(nums.at(arg1));

            unordered_set<int> s = nums.at(arg1)->set();

            int c = 0;
            for (int x : nums.at(arg2)->set()) {
                if (s.find(x) != s.end()) {
                    c++;
                }
            }
            cout << c << endl;
        }
    }


    return 0;
}
