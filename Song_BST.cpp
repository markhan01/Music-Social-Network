#include "Song_BST.h"

Song_BST::Song_BST(){
    root = nullptr;
    size = 0;
    song_added = 0;
}

void Song_BST::insert(Song_Node*& root, Song s){
    if(root == nullptr){
        root = new Song_Node(s);
        size++;
        song_added = 1;
    }
    if(s.name > root->data.name){
        insert(root->right, s);
    }
    else if(s.name < root->data.name){
        insert(root->left, s);
    }
    else{
        cout << "Song already exist" << endl;
    }
}

void Song_BST::show(Song_Node* node){
    if(node == nullptr){
        return;
    }
    show(node->left);
    cout << node->data.play_count << endl;
    show(node->right);
}

//delete