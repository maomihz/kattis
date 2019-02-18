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
#include <stack>
#include <climits>
#include <algorithm>

using namespace std;

bool compareWord(string a, string b) {
	return a.substr(0, 2) < b.substr(0, 2);
}

int main() {
    cerr << "hello, world" << endl;

    while (true) {
    	int n;
    	cin >> n;
    	if (n <= 0) {
    		break;
    	}

    	vector<string> words;

    	for (int i = 0; i < n; i++) {
    		string word;
    		cin >> word;

    		words.push_back(word);
    	}

    	stable_sort(words.begin(), words.end(), compareWord);

    	for (int i = 0; i < n; i++) {
    		cout << words[i] << endl;
    	}
    	cout << endl;
    }

    return 0;
}
