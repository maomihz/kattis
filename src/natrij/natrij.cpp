#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <climits>

#include <stdio.h>

using namespace std;

int main() {
    cerr << "hello, world" << endl;

    int h1, m1, s1;

    cin >> h1;
    cin.get();
    cin >> m1;
    cin.get();
    cin >> s1;

    int h2, m2, s2;

    cin >> h2;
    cin.get();
    cin >> m2;
    cin.get();
    cin >> s2;

    int ss1 = h1 * 3600 + m1 * 60 + s1;
    int ss2 = h2 * 3600 + m2 * 60 + s2;
    cerr << "ss1: " << ss1 << endl;
    cerr << "ss2: " << ss2 << endl;
    int ssd = ss2 - ss1;

    if (ssd <= 0) ssd += 86400;

    int dh, dm, ds;

    dh = ssd / 3600;
    dm = ssd % 3600 / 60;
    ds = ssd % 60;

    printf("%02d:%02d:%02d\n", dh, dm, ds);
    

    return 0;
}
