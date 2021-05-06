#include "Library.h"
Library::Library(){
    songs = new Song_BST();
    heap_index = 0;
}

void Library::add_song(string str, int i){
    Song s(str, i);
    songs->insert(songs->root, s);
    
    if(songs->song_added == 1){
       heap[heap_index] = &s;
       heap_index++;
       songs->song_added = 0;
    }   
}

int Library::song_exist(Song_Node* node, string s){
    if(node == nullptr){
        return 0;
    }

    else if(node->data.name == s){
        return 1;
    }

    else if(node->data.name < s){
        song_exist(node->left, s);
    }

    else{
        song_exist(node->right, s);
    }
}

void Library::show_songs(){
    songs->show(songs->root);
}

void Library::play(Song_Node* node, string s){
    if(node == nullptr){
        cout << "Song doesn't exist" << endl;
        return;
    }

    else if(node->data.name == s){
        node->data.play_count++;
        //heap[node->data.index].index++;
        cout << "You played the song " << node->data.name << " " << node->data.play_count << " times" << endl;   
        increase(node->data.index);
        return;
    }

    else if(node->data.name < s){
        play(node->right, s);
    }

    else{
        play(node->left, s);
    }
}

void Library::increase(int i){
    while( i > 0 && heap[(i-1)/2]->play_count < heap[i]->play_count ){
        swap(heap[i], heap[(i-1)/2]);
        swap(heap[i]->index, heap[(i-1)/2]->index);
    }
}



