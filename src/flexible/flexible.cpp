#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <climits>

#include <algorithm>

using namespace std;

int main() {
    cerr << "hello, world" << endl;

    int w, p;

    cin >> w >> p;

    vector<int> spaces = {0};
    for (int i = 0; i < p; i++) {
        int s;
        cin >> s;

        spaces.push_back(s);
    }
    spaces.push_back(w);

    vector<int> intervals;

    for (int i = 0; i < spaces.size(); i++) {
        for (int j = i + 1; j < spaces.size(); j++) {
            intervals.push_back(spaces[j] - spaces[i]);
        }
    }

    sort(intervals.begin(), intervals.end());

    int last = -1;
    for (int i = 0; i < intervals.size(); i++) {
        if (last != intervals[i]) {
            cout << intervals[i] << " ";
        }

        last = intervals[i];
    }

    cout << endl;


    return 0;
}
