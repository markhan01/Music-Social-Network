#include "Song_Node.h"

Song_Node::Song_Node(){
    left = nullptr;
    right = nullptr;
}


Song_Node::Song_Node(Song s){
    data = s;
    left = nullptr;
    right = nullptr;
}