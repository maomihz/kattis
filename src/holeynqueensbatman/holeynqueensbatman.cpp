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

#define mp make_pair

using namespace std;
typedef pair<int, int> coord;

bool findpath(bool** board, int n,
    bool* row, bool* col, bool* diag1, bool* diag2,
    int depth, int& count)
{
    if (depth >= n) {
        // fprintf(stderr, "Success");
        count++;
        return true;
    }

    for (int x = 0, y = depth; x < n; x++) {
        int d1 = x + y;
        int d2 = x - y + n - 1;

        if (!row[x] && !col[y] && !diag1[d1] && !diag2[d2] && !board[x][y])  {
            row[x] = true;
            col[y] = true;
            diag1[d1] = true;
            diag2[d2] = true;
            // fprintf(stderr, "Place %d, %d\n", x, y);
            bool result = findpath(board, n, row, col, diag1, diag2, depth+1, count);
            row[x] = false;
            col[y] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    }
    return false;
}

int main() {
    cerr << "hello, world" << endl;


    int n, m;
    while (scanf("%d %d", &n, &m), n || m) {
        bool **board = new bool*[n];
        bool row[n];
        bool col[n];
        bool diag1[n * 2 - 1];
        bool diag2[n * 2 - 1];
        int count = 0;
        for (int i = 0; i < n; i++) {
            board[i] = new bool[n];
            row[i] = false;
            col[i] = false;
            diag1[i] = false;
            diag2[i] = false;
            diag1[i + n - 1] = false;
            diag2[i + n - 1] = false;
            for (int j = 0; j < n; j++) {
                board[i][j] = false;
            }
        }

        while (m--) {
            int x, y;
            scanf("%d %d", &x, &y);

            board[y][x] = true;
        }

        findpath(board, n, row, col, diag1, diag2, 0, count);
        printf("%d\n", count);
    }


    

    return 0;
}
