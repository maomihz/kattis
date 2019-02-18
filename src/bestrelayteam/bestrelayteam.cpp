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

typedef tuple<string, double, double> tp;

bool sort2(tp a, tp b) {
    return get<2>(a) < get<2>(b);
}

bool sort1(tp a, tp b) {
    return get<1>(a) < get<1>(b);
}


int main() {
    cerr << "hello, world" << endl;

    int n;
    cin >> n;
    vector<tp> people;
    while (n--) {
        string s;
        double a, b;
        cin >>s >> a>>b;

        people.push_back(make_tuple(s, a, b));
    }

    sort(people.begin(), people.end(), sort2);

    double min = 100;
    vector<tp> minteam;

    for (int i = 0; i < people.size(); i++) {
        tp first = people.at(i);
        double sum = get<1>(first);
        vector<tp> names{first};

        for (int j = 0; names.size() < 4; j++) {
            if (i == j) continue;
            names.push_back(people.at(j));
            sum += get<2>(people.at(j));
        }

        if (sum < min) {
            min = sum;
            minteam = names;
        }
    }

    cout << min << endl;
    for (tp x : minteam) {
        cout << get<0>(x) << endl;
    }

    

    return 0;
}
