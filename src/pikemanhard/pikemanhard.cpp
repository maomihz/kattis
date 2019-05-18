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

long long next(long long a, long long b, long long c, long long t) {
    return (a * t + b) % c + 1;
}

int main() {
    long long T, N, a, b, c, t, t0, n, o, r, v, count, sum, penalty;
    
    while (cin >> N >> T >> a >> b >> c >> t0) {
        // Find cycles
        int occurance[c + 1];
        for (int i = 0; i <= c; i++) {
            occurance[i] = 0;
        }
        
        
        t = t0;
        count = 0;           // Dangling elements + one cycle
        int cyclecount = 0;  // Elements count in one cycle
        int cyclebegin = -1; // Beginning element of a cycle
        
        while ((count + cyclecount) < N) {
            if      (occurance[t] == 0) count++;
            else if (occurance[t] == 1) cyclecount++;
            else if (occurance[t] == 2) {
                cyclebegin = t;
                break;
            }
            occurance[t]++;
            t = next(a,b,c,t);
        }
        
//         cerr << "count=" << count << endl;
//         cerr << "cyclecount=" << cyclecount << endl;
//         cerr << "cyclebegin=" << cyclebegin << endl;
        
        // re-calculate occurance in a more efficient way
        if (cyclebegin >= 0) {
            // Elements count exclude dangling
            int cycletotal = N - (count - cyclecount);
            
            t = cyclebegin;
            v = cycletotal / cyclecount;
            r = cycletotal % cyclecount;
            for (int i = 0; i < cyclecount; i++) {
                if (i < r) occurance[t] = v + 1;
                else       occurance[t] = v;
                t = next(a,b,c,t);
            }
        }
        
        count = 0;    // # of problem solved
        sum = 0;      // Total time of solved problems
        penalty = 0;  // Total time penalty of problems
        
        // 1 <= i <= c
        for (int i = 1; i <= c; i++) {
            o = occurance[i];
            if (o > 0) {
                n = min((T - sum) / i, o);
                if (n == 0) break;
                penalty = (penalty + sum * n) % 1000000007;
                penalty = (penalty + i * (n + 1) * n / 2) % 1000000007;
                
//                 cerr << penalty << " " << sum << endl;
                sum += (n * i) % 1000000007;
                count += n;
//                 cerr << i << "x" << n << endl;
                if (n < o) break;
            }
        }
        
        cout << count << " " << penalty << endl;
    }
    
    
    

    return 0;
}





