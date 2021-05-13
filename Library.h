#ifndef Library_H
#define Library_H
#include "SongBST.h"

class Library{
    public:
    SongBST* songs;
    vector<Song*> heap;
    
    Library();
    void add_song(string, int);
    int song_exist(SongNode*, string);
    void recommend(Song*);
    void show_songs();
    Song* get_song(string);
    void play(SongNode*, string, int);
    void increase(int);
    Song* extract_max();
    void max_heapify(int);
};

#endif