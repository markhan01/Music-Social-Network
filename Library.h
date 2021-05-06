#ifndef Library_H
#define Library_H
#include "Song_BST.h"

class Library{
    public:
    Song_BST* songs;
    Song* heap[100];
    int heap_index;
    Library();
    void add_song(string, int);
    int song_exist(Song_Node*, string);
    //void recommend(string);
    void show_songs();
    void remove_song();
    void play(Song_Node*, string);
    void increase(int);

};

#endif