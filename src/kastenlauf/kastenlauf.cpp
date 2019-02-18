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

int comp(coord a, coord b) {
    return distance(origin, a) < distance(origin, b);
}


bool findpath(coord& begin, coord& dest, vector<coord>& stores, bool* visited) {
    if (distance(begin, dest) <= 1000) {
        return true;
    }

    for (int i = 0; i < stores.size(); i++) {
        if (visited[i]) continue;
        if (distance(begin, stores.at(i)) > 1000) continue;

        visited[i] = true;
        if (findpath(stores.at(i), dest, stores, visited)) {
            return true;
        }
    }
    return false;
}

int main() {
    cerr << "hello, world" << endl;

    int n;
    cin >> n;

    while (n--) {
        vector<coord> stores;

        int nstore;
        cin >> nstore;

        bool visited[nstore];
        for (int i = 0; i < nstore; i++) {
            visited[i] = false;
        }

        int beginx, beginy;
        cin >> beginx >> beginy;
        coord begin = make_pair(beginx, beginy);

        while (nstore--) {
            int storex, storey;
            cin >> storex >> storey;

            stores.push_back(make_pair(storex, storey));
        }

        int destx, desty;
        cin >> destx >> desty;
        coord dest = make_pair(destx, desty);


        if (findpath(begin, dest, stores, visited)) {
            cout << "happy" << endl;
        } else {
            cout << "sad" << endl;
        }

        


        
    }

    return 0;
}
