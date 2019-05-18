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

// Convert binary to integer
int bin2int(string bin) {
    int sum = 0;
    for (int i = bin.length() - 1; i >= 0; i--) {
        sum |= (bin.at(i) - '0') << i;
    }
    return sum;
}



int main() {
    int v; // Length-Required
    string bstr;
    cin >> v;
    
    // v = Length-Required
    while (cin >> v >> bstr) {
        int blen = bstr.length(); // Binary string length
        
        // If binary length is 1, then there is only one way.
        if (blen == 1) {
            cout << 1 << endl;
            continue;
        }
        
        // If required is less than binary length, then we don't need
        // any processing
        if (v < blen) {
            cout << (1 << v) << endl;
            continue;
        }
        
        
        int b = bin2int(bstr);    // Binary to decimal
        // How many previous states we need to keep track of
        int btotal = 1 << (blen - 1);
        int bprev = b / 2;
        int bcurr = b % btotal;
        
        // Initially, set all states to 1.
        // Second half is temp storage
        int count[btotal];
        int tmp[btotal];
        
        
        for (int i = 0; i < btotal; i++) {
            count[i] = 1;
            tmp[i] = 0;
        }
        
        // We need to iterate from (blen - 1) to v
        for (int i = 0; i <= v - blen; i++) {
            // Accumulate
            for (int j = 0; j < btotal; j++) {
                // Iterate through #digits in base 2
                for (int k = 0; k < 2; k++) {
                    int curr = ((j << 1) + k) % btotal;
                    if (!(j == bprev && curr == bcurr)) {
                        tmp[curr] = (tmp[curr] + count[j]) % (int)(1e9+7);
                    }
                }
            }
            
            // Transfer from tmp to count
            for (int j = 0; j < btotal; j++) {
                count[j] = tmp[j];
                tmp[j] = 0;
            }
        }
        
        
        int sum = 0;
        for (int i = 0; i < btotal; i++) {
            sum = (sum + count[i]) % (int)(1e9+7);
        }
        
        cout << sum << endl;
        
        
    }

    

    return 0;
}


