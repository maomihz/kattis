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

#define ALPHABET 26
#define START 'a'

using namespace std;


struct TrieNode {
    TrieNode* children[ALPHABET];
    int end;
    
    // Constructor
    TrieNode() {
        end = 0;
        for (int i = 0; i < ALPHABET; i++) {
            children[i] = nullptr;
        }
    }
    
    ~TrieNode() {
        for (int i = 0; i < ALPHABET; i++) {
            if (children[i]) {
                delete children[i];
            }
        }
    }
    
    void insert(string s, int begin = 0) {
        if (begin >= s.size()) {
            end++;
            return;
        }
        
        int idx = s[begin] - START;
        if (!children[idx]) {
            children[idx] = new TrieNode();
        }
        
        children[idx]->insert(s, begin + 1);
    }
    
    int count() {
        int sum = end;
        
        for (int i = 0; i < ALPHABET; i++) {
            if (children[i]) {
                sum += children[i]->count();
            }
        }
        return sum;
    }
    
    int search(string s, int begin = 0) {
        if (begin >= s.size()) {
            return count();
        }
        
        int idx = s[begin] - START;
        if (!children[idx]) return 0;
        return children[idx]->search(s, begin+1);
    }
};

int main(){
    int n;
    string word;
    while (cin >> n) {
        TrieNode root;

        for (int i = 0; i < n; i++) {
            cin >> word;
            cout << root.search(word) << endl;
            root.insert(word);
        }
    }
    
}

