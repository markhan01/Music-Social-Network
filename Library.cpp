#include "Library.h"
Library::Library(){
    songs = new SongBST();

}

void Library::add_song(string str, int i){
    Song* s = new Song(str, i);
    songs->insert(songs->root, nullptr, s);
    
    if(songs->song_added == 1){
       heap.push_back(s);   
       songs->song_added = 0;
    }   
}

void Library::recommend(Song* s){
    songs->insert(songs->root, nullptr, s);
}

int Library::song_exist(SongNode* node, string s){
    if(node == nullptr){
        return 0;
    }

    if(node->data->name == s){
        return 1;
    }

    else if(node->data->name < s){
        return song_exist(node->right, s);
    }

    else{
        return song_exist(node->left, s);
    }
}

void Library::show_songs(){
    songs->show(songs->root);
}

Song* Library::get_song(string s){
    return songs->get_song(songs->root, s);
}

void Library::play(SongNode* node, string s, int count){
    if(node == nullptr){
        cout << "Error: "<< s << " doesn't exist in the library!" << endl;
        return;
    }

    else if(node->data->name == s){
        node->data->play_count += count;
        cout << "Update: " << node->data->name << " has been played " << node->data->play_count << " times!" << endl; 
        increase(node->data->index);
        return;        
    }

    else if(node->data->name < s){
        play(node->right, s, count);
    }

    else{
        play(node->left, s, count);
    }
}

void Library::increase(int i){
    cout << heap[i]->name << endl;
    while( i > 0 && heap[(i-1)/2]->play_count < heap[i]->play_count ){
        swap(heap[i]->index, heap[(i-1)/2]->index);
        swap(heap[i], heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

Song* Library::extract_max(){
    Song* s = heap[0];
    swap(heap[0]->index, heap[heap.size()-1]->index);
    swap(heap[0], heap[heap.size()-1]);
    heap.erase(heap.end()-1);
    max_heapify(0);
    return s;
}

void Library::max_heapify(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap.size() && heap[left]->play_count> heap[largest]->play_count) {
        largest = left;
    }

    if (right < heap.size() && heap[right]->play_count > heap[largest]->play_count) {
        largest = right;
    }

    if (largest != i) {
        swap(heap[i]->index, heap[largest]->index);
        swap(heap[i], heap[largest]);
        max_heapify(largest);
    }
}

