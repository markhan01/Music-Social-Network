#ifndef Song_H
#define Song_H

using namespace std;
#include <string>
#include <iostream>
#include <vector>

class Song{
    public:
    string name;
    int play_count;
    int index;

    Song();
    Song(string, int);
};

#endif
