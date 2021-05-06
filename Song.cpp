#include "Song.h"

Song::Song(){
    name = "";
    play_count = 0;
}

Song::Song(string s, int i){
    name = s;
    play_count = 0;
    index = i;
}