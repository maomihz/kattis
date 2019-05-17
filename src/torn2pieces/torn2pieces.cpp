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

struct node {
    string value;
    vector<string> hist;
};

int main() {
    int n;
    string x, line;
    while (cin >> n) {
        unordered_map<string, unordered_set<string>> g;
        unordered_set<string> e;
        cin.ignore();
        
        for (int i = 0; i < n; i++) {
            getline(cin, line);
           
            istringstream ss(line);
            string name;
            ss >> name;

//             cerr << line << endl;
            
            while (ss >> x) {
                if (g.find(name) == g.end()) {
                    g[name] = e;
                }
                if (g.find(x) == g.end()) {
                    g[x] = e;
                }

                g[name].insert(x);
                g[x].insert(name);
            }
            
        }
        
        
        // BFS
        queue<node*> q;
        unordered_set<string> seen;
        string start, end;
        cin >> start >> end;
        q.push(new node{start, vector<string>()});
        
        
        bool noroute = true;
        while (!q.empty()) {
            node* current = q.front();
            q.pop();
            if (seen.find(current->value) != seen.end()) {
                continue;
            }
            seen.insert(current->value);
//             cerr << "search " << current->value << endl;
            
            if (current->value == end) {
                for (string s : current->hist) {
                    cout << s << " ";
                }
                cout << end << endl;
                noroute = false;
                break;
            }
            
            vector<string> vst = current->hist;
            vst.push_back(current->value);
            if (g.find(current->value) != g.end()) {
                for (string s : g[current->value]) {
                    q.push(new node{s, vst});
                }
            }
        }
        
        if (noroute) {
            cout << "no route found" << endl;
        }
        
    }

    return 0;
}
