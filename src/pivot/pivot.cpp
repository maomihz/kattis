#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <climits>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
    cerr << "hello, world2" << endl;

    int n;
    cin >> n;

    vector<int> array;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        array.push_back(x);
        cerr << x << ",";
    }
    cerr << endl;

    set<int> increasing;
    set<int> decreasing;

    int mymax = array.at(0);
    increasing.insert(mymax);
    for (int i = 1; i < n; i++) {
        if (array.at(i) >= mymax) {
            mymax = array.at(i);
            increasing.insert(mymax);
        }
    }

    int mymin = *(array.end() - 1);
    decreasing.insert(mymin);

    for (int i = n - 2; i >= 0; i--) {
        if (array.at(i) <= mymin) {
            mymin = array.at(i);
            decreasing.insert(mymin);
        }
    }

    set<int> result;

    set_intersection(increasing.begin(), increasing.end(),
    decreasing.begin(), decreasing.end(),
    inserter(result, result.begin()));

    cout << result.size();

    return 0;
}


int main2() {
    cerr << "hello, world" << endl;

    int n;
    cin >> n;

    vector<int> array;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        array.push_back(x);
        cerr << x << ",";
    }
    cerr << endl;

    int count = 0;
    for (int i = 0; i < array.size(); i++) {
        bool no = false;
        for (int j = 0; j < i; j++) {
            if (array[j] > array[i]) {
                // cerr << array[j] << ">" << array[i] << endl;
                no = true;
                break;
            }
        }

        if (no) continue;

        for (int j = i + 1; j < array.size(); j++) {
            if (array[j] < array[i]) {
                // cerr << array[j] << "<" << array[i] << endl;
                no = true;
                break;
            }
        }
        
        // If no is still false
        if (!no) {
            count++;
            cerr << "pivot: " << array[i] << endl;
        }
    }

    cout << count << endl;

    return 0;
}
