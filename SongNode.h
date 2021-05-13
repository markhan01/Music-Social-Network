#ifndef SongNode_H
#define SongNode_H
#include "Song.h"
class SongNode{

    public:
    Song* data;
    SongNode* left;
    SongNode* right;
    SongNode* parent;

    SongNode();
    SongNode(Song*);
};

#endif