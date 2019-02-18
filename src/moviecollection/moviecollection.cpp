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
    cerr << "hello, world" << endl;
    int z;

    int t; // Number of test cases
    scanf("%d", &t);

    while (t--) {
        int m; // Number of movies in stack
        int r; // Number of requests
        scanf("%d%d", &m, &r);





        int order[m];
        for (int i = 0; i < m; i++) {
            order[i] = i;
        }


        while(r--) {
            int i; // Name of the movie
            scanf("%d",&i);
            printf("%d ", order[i-1]);
            for (int u = 0; u < i - 1; u++) {
                order[u]++;
            }
            order[i-1] = 0;
        }
        printf("%s", "\n");



    }

    return 0;
}
