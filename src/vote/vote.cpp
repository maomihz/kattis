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

    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        
        int best;
        int bestindex = 0;
        cin >> best;
        int total = best;

        bool goodbest = true;

        for (int j = 1; j < n; j++) {
            int x;
            cin >> x;

            total += x;
            if (x == best){
                goodbest = false;
            } else if (x > best) {
                best = x;
                goodbest = true;
                bestindex = j;
            }
        }

        double half = (double)best / total;
        if (!goodbest) {
            cout << "no winner" << endl;
        } else {
            if (half > 0.5) {
                cout << "majority winner " << bestindex + 1 << endl;
            } else {
                cout << "minority winner " << bestindex + 1 << endl;
            }
        }
    }

    return 0;
}
