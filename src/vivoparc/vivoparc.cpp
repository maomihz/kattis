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

bool search(unordered_set<int>* visible, int* assignment, int depth, int maxdepth) {
    if (depth >= maxdepth) {
        return true;
    }
    for (int i = 0; i < 4; i++) {
        int no = false;

        for (int x : visible[depth]) {
            if (assignment[x] == i) {
                no = true;
                break;
            }
        }
        if (no) continue;


        assignment[depth] = i;
        bool result = search(visible, assignment, depth + 1, maxdepth);
        if (result) {
            return true;
        }


        assignment[depth] = -1;
    }
    return false;
}

int main() {
    cerr << "hello, world" << endl;


    int n;
    scanf("%d", &n);
    unordered_set<int> visible[n];

    // unordered_set 

    int a, b;
    int assignment[n];
    for (int i = 0; i < n; i++) {
        assignment[i] = -1;
    }
    while (scanf("%d-%d", &a, &b) != EOF) {
        a--;
        b--;
        visible[a].insert(b);
        visible[b].insert(a);
    }

    if (search(visible, assignment, 0, n)) {
        for (int i = 0; i < n; i++) {
            printf("%d %d\n", i + 1, assignment[i] + 1);
        }
    }







    return 0;
}
