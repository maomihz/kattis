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

struct Location {
    int location;
    int nletters;
};

bool cmp(Location& a, Location& b) {
    return a.location < b.location;
}



int deliverhelper(vector<Location> locations, int k, int currentDelivery, int letters, int sum) {
    Location& current = locations.at(currentDelivery);
    // Required delivery amount
    int required = current.nletters % k;
    // Actual delivery amount
    int delivered = min(letters, required);
    int remain = required - delivered;
    
//     fprintf(stderr, "deliver to %d {%d, n=%d} %d letters.\n", currentDelivery, currentDelivery.location, currentDelivery.nletters, delivered);
    letters -= delivered;
    current.nletters -= delivered;
    
    if (letters == 0) { // I have to go back
        return deliverhelper(locations, k, currentDelivery, k, sum + 2 * current.location);
    }
    
    // Base condition
    if (currentDelivery == locations.size() - 1) {
        if (remain == 0) {
            return sum + current.location; // Go back to 0
        } else {
            // Go back and deliver again
            return deliverhelper(locations, k, currentDelivery, k, sum + 2 * current.location);
        }
    }
    
    // Two choices
    Location& next = locations.at(currentDelivery + 1);
    int a = 0;
    int b = 0;
    
    // Continue delivering
    b = deliverhelper(locations, k, currentDelivery + 1, letters, sum + next.location - current.location);
    if (delivered == 0)  {
        return b; // I have to go next
    }
    // Try Go back and deliver
    a = deliverhelper(locations, k, currentDelivery + 1, k, sum + current.location + next.location);
    return min(a, b);
}

int deliver(vector<Location>& locations, int k) {
    if (locations.empty()) {
        return 0;
    }
    sort(locations.begin(), locations.end(), cmp);
    int preDeliver = deliverhelper(locations, k, 0, k, locations.at(0).location);
    
    cerr << "Deliver: " << preDeliver << endl;
    int sum = preDeliver;
    for (int i = 0; i < locations.size(); i++) {
        sum += 2 * locations.at(i).location * (locations.at(i).nletters / k);
    }
    return sum;
    
}

long long deliverGreedy(vector<Location>& locations, int k) {
    if (locations.empty()) {
        return 0;
    }
    sort(locations.begin(), locations.end(), cmp);
    
    int i = locations.size() - 1;
    long long sum = 0;
    int letters = 0;
    while (true) {
        // Find a location for delivery
        while (i > 0 && locations[i].nletters == 0) {
            i--;
        }
        // Reach the end
        if (i == 0 && locations[i].nletters == 0) {
            break;
        }
        // Refill the letters when necessary
        if (letters == 0) {
            sum += 2 * locations[i].location;
            letters = k;
        }
        // Deliver the letters
        int delivered = min(locations[i].nletters, letters);
        locations[i].nletters -= delivered;
        letters -= delivered;
    }
    return sum;
}
int main() {
    
    int n, k;
    while (scanf("%d %d", &n, &k) != EOF) {
        vector<Location> locations_p;
        vector<Location> locations_n;

        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            if (a < 0) {
                locations_n.push_back(Location {-a, b});
            } else {
                locations_p.push_back(Location {a, b});
            }
        }

        int d1 = deliverGreedy(locations_p, k);
        int d2 = deliverGreedy(locations_n, k);
//         fprintf(stderr, "> %d, %d\n", d1, d2);
        printf("%d\n", d1 + d2);
    }
    
    return 0;
}
