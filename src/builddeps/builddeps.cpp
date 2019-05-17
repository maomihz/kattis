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

void dfs(unordered_map<string, unordered_set<string>>& deps, unordered_set<string>& seen, stack<string>& ans, string s) {
    if (seen.find(s) != seen.end()) {
        return;
    }
    seen.insert(s);
    for (string s2 : deps[s]) {
        dfs(deps, seen, ans, s2);
    }
    ans.push(s);
}


int main() {
    int n;
    string line, word, dep, file;
    while (cin >> n) {
        unordered_map<string, unordered_set<string>> deps;
        getline(cin, line);
        
        for (int i = 0; i < n; i++) {
            getline(cin, line);
            istringstream ss(line);
            ss >> word;
            word = word.substr(0, word.size() - 1);
            
            while (ss >> dep) {
                if (deps.find(dep) == deps.end()) {
                    deps[dep] = unordered_set<string>();
                }
                deps[dep].insert(word);
            }
        }
        
        
        cin >> file;
        stack<string> ans;
        unordered_set<string> seen;
        
        
        dfs(deps, seen, ans, file);
        
        while (!ans.empty()) {
            cout << ans.top() << endl;
            ans.pop();
        }
    }

}
