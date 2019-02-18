#include <iostream>
#include <stdexcept>

#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

#include <sstream>
using namespace std;


string range(int begin, int end) {
    ostringstream os;
    if (end - begin == 0) {
        os << begin;
    } else if (end - begin == 1) {
        os << begin << " " << end;
    } else {
        os << begin << "-" << end;
    }
    return os.str();
}
int main() {
    cerr << "hello, world" << endl;

    int n;
    cin >> n;

    vector<int> numbers;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        numbers.push_back(x);
    }

    sort(numbers.begin(), numbers.end());

    int last_num = -1;
    int begin = -1;
    for (int num : numbers) {
        if (last_num < 0) {
            last_num = num;
            begin = num;
            continue;
        }

        if (last_num + 1 == num) {
            last_num = num;
            continue;
        } else {
            cout << range(begin, last_num) << " ";
            begin = num;
            last_num = num;
        }
    }
    cout << range(begin, *(numbers.end() - 1)) << endl;


    return 0;
}



int helper() {
    return 0;
}