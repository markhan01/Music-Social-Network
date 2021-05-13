#include "SongNode.h"

SongNode::SongNode(){
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

SongNode::SongNode(Song* s){
    data = s;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}