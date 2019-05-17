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

int main() {
    int c,n,nc;
    string resident, party, club;
    cin >> c;
    
    while (c--) {
        cin >> n;
        unordered_map<string, int> party_index;    // Party name => index
        unordered_map<string, int> club_index;     // Club name => index
        unordered_map<string, int> resident_index; // Resident name => index
        
        unordered_set<int> residents;
        unordered_set<int> clubs;
        unordered_set<int> parties;
        
        int source_index, sink_index;
        vector<string> names;   // Index => Resident, party, club names
        
        // Map: [resident + parties + clubs], [source], [sink]
        vector<unordered_map<int, int>> map;
        
        for (int i = 0; i < n; i++) {
            cin >> resident >> party >> nc;
            
            // Add new resident entry to the map
            resident_index[resident] = map.size();
            residents.insert(map.size());
            map.push_back(unordered_map<int, int>());
            names.push_back(resident);
            
            
            // Add new entry of party if necessary
            if (party_index.find(party) == party_index.end()) {
                party_index[party] = map.size();
                parties.insert(map.size());
                map.push_back(unordered_map<int, int>());
                names.push_back(party);
            }
            
            // Connect resident ==> party
            map[resident_index[resident]][party_index[party]] = 1;
            
            
            for (int j = 0; j < nc; j++) {
                cin >> club;
                // Add new entry of club if necessary
                if (club_index.find(club) == club_index.end()) {
                    club_index[club] = map.size();
                    clubs.insert(map.size());
                    map.push_back(unordered_map<int, int>());
                    names.push_back(club);
                }
                
                // Connect club ==> residents
                map[club_index[club]][resident_index[resident]] = 1;
            }
        }
        
        
        // Connect source ==> clubs
        source_index = map.size();
        map.push_back(unordered_map<int, int>());
        names.push_back("source");
        for (auto it: club_index) {
            map[source_index][it.second] = 1;
        }
        
        
        // Connect party ==> sink
        sink_index = map.size();
        map.push_back(unordered_map<int, int>());
        names.push_back("sink");
        int party_max;
        if (club_index.size() % 2 == 0) {
            party_max = club_index.size() / 2 - 1;
        } else {
            party_max = club_index.size() / 2;
        }
        
        // You can't have less than 2 clubs
        if (party_max < 1) {
            cout << "Impossible." << endl << endl;
            continue;
        }
        for (auto it: party_index) {
            map[it.second][sink_index] = party_max;
        }
        
        
        
        // Max flow
        int max_flow = 0;
//         vector<pair<string, string>> outputs;
        while (true) {
            int parents[map.size()];
            for (int i = 0; i < map.size(); i++) {
                parents[i] = -1;
            }
            
            // Find a path from source to sink
            queue<int> q;
            q.push(source_index);
            parents[source_index] = source_index; // point to itself
            
            
            bool done = false;
            while (!done && !q.empty()) {
                int x = q.front();
                q.pop();
                
                // Iterate through its child
                for (auto edge : map[x]) {
                    int n = edge.first;
                    int w = edge.second;
                    // Do not consider negative edge
                    if (w <= 0) continue;
                    if (parents[edge.first] >= 0) continue;

                    q.push(n);
                    parents[n] = x;
                    if (n == sink_index) {
                        done = true;
                        break;
                    }
                }
            }
            
            if (!done) break; // No more paths
            
            // Find a bottleneck
            int current = sink_index;
            int min_weight = INT_MAX;
            while (parents[current] != current) {
                min_weight = min(min_weight, map[parents[current]][current]);
                current = parents[current];
            }
            
            
            // Augument the path
            current = sink_index;
//             pair<string, string> output;
            while (parents[current] != current) {
                if (map[current].find(parents[current]) == map[current].end()) {
                    map[current][parents[current]] = 0;
                }
                
                map[parents[current]][current] -= min_weight;
                map[current][parents[current]] += min_weight;
                
                // Keep track of council items
//                 output.first = output.second;
//                 output.second = names[current];
                
                current = parents[current];
            }
//             outputs.push_back(output);
            max_flow += min_weight;
        }
        
        
        if (max_flow < club_index.size()) {
            cout << "Impossible." << endl;
        } else {
            // Go through the graph and check for back edges
            for (auto it: club_index) {
                for (auto club: map[it.second]) {
                    // club.second == weight
                    if (residents.find(club.first) == residents.end()) {
                        continue;
                    }
                    
                    if (club.second == 0) {
                        cout << names[club.first] << " " << names[it.second] << endl;
                        break;
                    }
                }
            }
        }
        
        
        
        cout << endl;
        
    }

    return 0;
}
