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
    int starlist[] = {
        2,2,2,2,2,
        3,3,3,3,3,
        4,4,4,4,4,
        5,5,5,5,5,
        5,5,5,5,5
    };

    int stars = 0;
    int rank = 0;
    int consecutive = 0;
    bool legend = false;

    while (true) {
        char c = cin.get();
        if (!cin) break;

        if (c == 'W') {
            consecutive ++;
            stars++;
            if (rank <= 19 && consecutive >= 3) {
                stars++;
            }

            if (stars > starlist[rank]) {
                stars -= starlist[rank];
                rank++;
            }
        } else if (c == 'L') {
            consecutive = 0;
            if ((rank >= 6 && rank <= 24) || (rank == 5 && stars > 0)) {
                stars--;
            }
            
            if (stars < 0) {
                rank--;
                stars = starlist[rank] + stars;
            }
        }
        // cerr << c << " -- " << "s: " << stars << " r: " << rank << endl; 
        // cerr << c << " -- " << "star: " << stars << " rank: " << rank << endl; 

        if (rank >= 25) {
            legend = true;
        }
    }

    if (legend) {
        cout << "Legend" << endl;
    } else {
        cout << 25 - rank << endl;
    }

    return 0;
}
