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

#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
    int i;
    cin >> i;

    if (i <= 3) {
        cout << '1' << endl;
    } else {
        cout << (i - 2) << endl;
    }

    

    return 0;
}
