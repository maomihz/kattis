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

typedef pair<int, int> coord;

coord dest, home, origin;

int distance(coord a, coord b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int x(coord a) {
    return a.first;
}
int y(coord a) {
    return a.second;
}

const pair<int, int> LEFT = make_pair(-1, 0);
const pair<int, int> RIGHT = make_pair(1, 0);
const pair<int, int> DOWN = make_pair(0, 1);
const pair<int, int> UP = make_pair(0, -1);

const vector<pair<int, int>> dirs = {
    LEFT, RIGHT, DOWN, UP
}

bool canmove(vector<vector<int>> board, coord c, pair<int, int> dir) {
    if (board[x(c)][y(c)] != 'o') {
        return false;
    }
    
    if (board[x(c) + x(dir)][y(c) + y(dir)] != 'o') {
        return false;
    }

    int destx = x(c) + x(dir) + x(dir);
    int desty = y(c) + y(dir) + y(dir);

    if (destx < 0) return false;
    if (destx >= 9) return false;
    if (desty < 0) return false;
    if (destx >= 5) return false;

    if (board[destx][desty] != '.') {
        return false;
    }
    return true;
}

bool findpath(vector<vector<int>> board, int depth) {
    int min = 0;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            char c = board[i][j];
            coord begin = make_pair(i, j);
            if (c == 'o') {
                for (pair<int, int> dir : dirs) {
                    if (canmove(board, begin, dir)) {
                        vector<vector<int>> board_new = board;
                        board_new[x(begin) + x(dir)][y(begin) + y(dir)] = '.';
                        board_new[x(begin) + x(dir) + x(dir)][y(begin) + y(dir) + y(dir)] = 'o';

                        int new_depth = findpath(board_new, depth+1);
                        if (new_dept)
                        if (new_depth = ) {
                            return ;
                        }
                    }
                }

            }
        }
    }
    return false;
}

int main() {
    cerr << "hello, world" << endl;

    int n = 0;
    cin >> n;
    while (n--) {
        vector<vector<int>> board;
        for (int i = 0; i < 5; i++) {
            string x;
            cin >> x;
            board.push_back(vector<int>());

            for (int j = 0; j < 9; j++) {
                board[i].push_back(p);
            }
        }

        if (find_path(board)) {

        }
    }

    return 0;
}
