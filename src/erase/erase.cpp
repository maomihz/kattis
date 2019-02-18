#include <iostream>
#include <stdexcept>

#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
    cerr << "hello, world" << endl;


    int n;
    cin >> n;

    n &= 1;

    string a, b;
    getline(cin, a);


    getline(cin, a);
    getline(cin, b);


    string ainv;
    for (char c : a) {
        if (c == '0') {
            ainv.push_back('1');
        } else {
            ainv.push_back('0');
        }
    }

    cerr << a << endl;
    cerr << b << endl;
    cerr << ainv << endl;


    
    // Need switch
    if (n == 1 && ainv == b) {
        cout << "Deletion succeeded" << endl;
    } else if (n == 0 && a == b) {
        cout << "Deletion succeeded" << endl;
    } else {
        cout << "Deletion failed" << endl;
    }


    return 0;
}



int helper() {
    return 0;
}