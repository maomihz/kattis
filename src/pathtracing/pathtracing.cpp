#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <climits>

using namespace std;

#define EMPTY ' '
#define START 'S'
#define END 'E'
#define PATH '*'

int main() {
    cerr << "hello, world" << endl;

    int x = 0;
    int y = 0;

    string line;

    vector<int> stepsx, stepsy;

    int maxx = 0;
    int minx = 0;
    int maxy = 0;
    int miny = 0;

    while (true) {
        getline(cin, line);
        if (!cin) break;

        if (line.at(0) == 'u') {
            y += -1;
            stepsx.push_back(0);
            stepsy.push_back(-1);
        } else if (line.at(0) == 'd') {
            y += 1;
            stepsx.push_back(0);
            stepsy.push_back(1);
        } else if (line.at(0) == 'l') {
            x += -1;
            stepsx.push_back(-1);
            stepsy.push_back(0);
        } else if (line.at(0) == 'r') {
            x += 1;
            stepsx.push_back(1);
            stepsy.push_back(0);
        }

        cerr << line << endl;

        if (x < minx) {
            minx = x;
        }
        if (x > maxx) {
            maxx = x;
        }
        if (y < miny) {
            miny = y;
        }
        if (y > maxy) {
            maxy = y;
        }
    }

    int width = maxx - minx + 1;
    int height = maxy - miny + 1;

    char map[width][height];
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            map[i][j] = EMPTY;
        }
    }

    int startx = -minx;
    int starty = -miny;

    int xx = startx;
    int yy = starty;


    for (int i = 0; i < stepsx.size(); i++) {
        xx += stepsx[i];
        yy += stepsy[i];
        map[xx][yy] = PATH;
    }

    map[startx][starty] = START;
    map[xx][yy] = END;

    for (int i = 0; i < width + 2; i++) {
        cout << "#";
    }
    cout << endl;

    for (int j = 0; j < height; j++) {
        cout << "#";
        for (int i = 0; i < width; i++) {
            cout << map[i][j];
        }
        cout << "#";
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++) {
        cout << "#";
    }
    cout << endl;
    

    return 0;
}
