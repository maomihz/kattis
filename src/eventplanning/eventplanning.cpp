#include <iostream>
#include <stdexcept>
#include <climits>

#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
    cerr << "hello, world" << endl;

    int n, b, h, w;
    cin >> n >> b >> h >> w;

    int min_price = INT_MAX;

    for (int i = 0; i < h; i++) {
        int p;
        cin >> p;
        for (int j = 0; j < w; j++) {
            int av;
            cin >> av;
            // Available greater than # participants
            if (av >= n) {
                int price = p * n;
                if (price < min_price) {
                    min_price = price;
                }
            }

        }
    }

    // More than budget
    if (min_price > b) {
        cout << "stay home" << endl;
    } else {
        cout << min_price << endl;
    }

    return 0;
}



int helper() {
    return 0;
}