#ifndef Song_BST_H
#define Song_BST_H
#include "Song_Node.h"

class Song_BST{
    public:
    Song_Node* root;
    int size;
    int song_added;

    Song_BST();
    void insert(Song_Node*&, Song);
    void remove();
    void show(Song_Node*);
};
#endif