#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
  cerr << "hello, world" << endl;

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    
    unordered_map<string, unordered_set<string>> forward;
    unordered_map<string, unordered_set<string>> backward;


    while (n--) {
      string name;
      cin >> name;
      cerr << name << endl;
      vector<string> foreign;
      vector<string> native;

      int a;
      string p;

      cin >> a;
      while (a--) {
        cin >> p;
        foreign.push_back(p);
      }

      cin >> a;
      while (a--) {
        cin >> p;
        native.push_back(p);
      }

      unordered_set<string> foreign_set(foreign.begin(), foreign.end());
      unordered_set<string> native_set(native.begin(), native.end());

      for (string word : foreign) {
        if (forward.find(word) == forward.end()) {
          forward[word] = native_set;
        } else {
          unordered_set<string> new_set;
          unordered_set<string> old_set = forward[word];

          for (string s : old_set) {
            if (native_set.find(s) != native_set.end()) {
              new_set.insert(s);
            }
          }
          forward[word] = new_set;
        }
      }

      for (string word : native) {
        if (backward.find(word) == backward.end()) {
          backward[word] = foreign_set;
        } else {
          unordered_set<string> new_set;
          unordered_set<string> old_set = backward[word];
          for (string s : old_set) {
            if (foreign_set.find(s) != foreign_set.end()) {
              new_set.insert(s);
            }
          }
          backward[word] = new_set;
        }
      }


    }

    vector<pair<string, string>> matches;

    for (auto it = forward.begin(); it != forward.end(); it++) {
      string a = it->first;
      for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
        string b = *it2;

        cerr << "find match " << a << ", " << b << endl;

        if (backward[b].find(a) != backward[b].end()) {
          matches.push_back(make_pair(a, b));
        }

      }
    }

    sort(matches.begin(), matches.end());

    for (auto it = matches.begin(); it != matches.end(); it++) {
      cout << "(" << it->first << ", " << it->second << ")" << endl;
    }
    cout << endl;
  }

  return 0;
}
