#ifndef Song_Node_H
#define Song_Node_H
#include "Song.h"
class Song_Node{

    public:
    Song data;
    Song_Node* left;
    Song_Node* right;

    Song_Node();
    Song_Node(Song);
};

#endif