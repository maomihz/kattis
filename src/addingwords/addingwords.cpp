#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <climits>
#include <deque>
#include <queue>

using namespace std;

int main() {
    cerr << "hello, world" << endl;

    unordered_map<string, int> forward_map;
    unordered_map<int, string> backward_map;

    while (true) {
        string command;
        cin >> command;
        if (!cin) break;

        if (command == "def") {
            string var;
            int val;
            cin >> var >> val;

            // Erase previous content
            try {
                int prev = forward_map.at(var);
                backward_map.erase(prev);
            } catch (out_of_range e) {
                ;
            }

            forward_map[var] = val;
            backward_map[val] = var;
        } else if (command == "calc") {
            string var;
            string op;

            cin >> var;
            int total;
            bool unknown = false;

            try {
                total = forward_map.at(var);
            } catch (out_of_range e) {
                unknown = true;
            }

            cout << var << " ";

            while (cin >> op) {
                cout << op << " ";
                if (op == "=") {
                    break;
                }

                cin >> var;
                cout << var << " ";

                if (unknown) continue;

                int val;
                try {
                    val = forward_map.at(var);
                } catch (out_of_range e) {
                    unknown = true;
                }

                if (op == "+") {
                    total += val;
                } else { // op == "-"
                    total -= val;
                }
            }

            string total_var;

            try {
                total_var = backward_map.at(total);
            } catch (out_of_range e) {
                unknown = true;
            }


            // Print result
            if (unknown) {
                cout << "unknown" << endl;
            } else {
                cout << total_var << endl;
            }
        } else if (command == "clear") {
            forward_map.clear();
            backward_map.clear();
        }
    }

    return 0;
}
