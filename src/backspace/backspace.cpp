#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <climits>

using namespace std;

int main() {
    cerr << "hello, world" << endl;
    char ch[1000000];
    int len = 0;
    
    string line;
    getline(cin, line);

    istringstream is(line);
    while (true) {
        char c = is.get();
        if (!is) break;

        if (c == '<') {
            len --;
        } else {
            ch[len] = c;
            len ++;
        }
    }

    ch[len] = '\0';


    cout << ch << endl;

    return 0;
}
