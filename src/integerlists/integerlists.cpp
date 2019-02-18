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

using namespace std;

int main() {
    cerr << "hello, world" << endl;
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
    	string instructions;
    	cin >> instructions;

    	int n;
    	cin >> n;

    	string list;
    	cin >> list;

    	list.erase(list.begin());
    	list.erase(list.end() - 1);

    	istringstream os(list);
    	deque<int> nums;

    	while (true) {
    		int x;
    		os >> x;
    		if (!os) break;
    		os.get();

    		nums.push_back(x);
    	}

    	// for (int a = 0; a < nums.size(); a++) {
    	// 	cerr << nums[a] << ",";
    	// }
    	// cerr << endl;

    	// cerr << list << endl;

    	bool reverse = false;
    	bool error = false;
    	for (char c : instructions) {
    		if (c == 'R') {
    			reverse = !reverse;
    		} else if (c == 'D') {
    			if (nums.empty()) {
    				error = true;
    				break;
    			}
    			if (reverse) {
    				nums.pop_back();
    			} else {
    				nums.pop_front();
    			}
    		}
    	}

    	if (error) {
    		cout << "error" << endl;
    	} else {
    		cout << "[";
	    	for (int a = 0; a < nums.size(); a++) {
	    		if (reverse) {
		    		cout << nums[nums.size() - a - 1];
	    		} else {
	    			cout << nums[a];
	    		}
	    		if (a != nums.size() - 1) {
	    			cout << ",";
	    		}
	    	}
	    	cout << "]" << endl;
    	}

    }


    return 0;
}
