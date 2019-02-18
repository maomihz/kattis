#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <climits>

using namespace std;

int filter(vector<int>& array, int item, int& switchcount) {
    int count = 0;
    int begin = 0;
    
    for (int i = 0; i < array.size(); i++) {
        if (array[i] < item) continue;
        if (array[i] == item) {
            switchcount += begin - count;
            count ++;
        }
        begin++;
    }

    return count;
}

int main() {
    cerr << "hello, world" << endl;

    vector<int> array;

    while (cin) {
        char c = cin.get();
        if (c >= '0' && c <= '2') {
            array.push_back((int)c - (int)'0');
        } else {
            break;
        }
    }

    // for (int i = 0; i < array.size(); i++) {
    //     cerr << array.at(i);
    // }
    // cerr << endl;

    int switchcount = 0;
    int count = 0;

    // Apply the algorithm
    count += filter(array, 0, switchcount);
    // for (int i = 0; i < array.size(); i++) {
    //     cerr << array.at(i);
    // }
    // cerr << " " << count << endl;


    count += filter(array, 1, switchcount);
    // for (int i = 0; i < array.size(); i++) {
    //     cerr << array.at(i);
    // }
    // cerr << endl;
    // cerr << " " << count << " " << switchcount << endl;
    cout << switchcount << endl;
    // cerr << endl;


    return 0;
}


// 10210
// 01210
// 01201
// 01021
// 00121
// 00112
