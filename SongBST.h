#ifndef SongBST_H
#define SongBST_H
#include "SongNode.h"

class SongBST{
    public:
    SongNode* root;
    int size;
    int song_added;

    SongBST();
    void insert(SongNode*&, SongNode*, Song*);   
    void delete_song(SongNode*, string);
    void show(SongNode*);
    Song* get_song(SongNode*, string);
};
#endif