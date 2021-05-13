#include "SongBST.h"

SongBST::SongBST(){
    root = nullptr;
    size = 0;
    song_added = 0;
}

void SongBST::insert(SongNode*& root, SongNode* p, Song* s){
    if(root == nullptr){
        root = new SongNode(s);
        root->parent = p;
        size++;
        song_added = 1;
        cout << "Success: " << s->name << " added to the library!" << endl;
        return;
    }
    if(s->name > root->data->name){
        insert(root->right, root, s);
    }
    else if(s->name < root->data->name){
        insert(root->left, root, s);
    }
    else{
        cout << "Error: " << s->name << " already exist in the library!" << endl;
    }
}

Song* SongBST::get_song(SongNode* node, string s){
    if (node == nullptr){
        return nullptr;
    }
    if(s > node->data->name){
        return get_song(node->right, s);
    }
    else if(s < node->data->name){
        return get_song(node->left, s);
    }
    else{
        return node->data;
    }
}


void SongBST::show(SongNode* node){
    if(node == nullptr){
        return;
    }
    show(node->left);
/*
    if(node->parent != nullptr){
        cout << "Name: " << node->data->name << " Playcount: " << node->data->play_count << " Parent: " << node->parent->data->name << endl;
    }
    else{
        cout << "Name: " << node->data->name << " Playcount: " << node->data->play_count << " Parent: Nullptr" << endl;
    }
*/   
    cout << node->data->name << endl;
    show(node->right);
}

void SongBST::delete_song(SongNode* node, string s){
    if(node == nullptr){
        cout << "Error: " << s << " doesn't exist in the library!" << endl;
    }

    else if(s > node->data->name){
        delete_song(node->right, s);
    }

    else if(s < node->data->name){
        delete_song(node->left, s);
    }

    else{
        node->data->play_count = 0;
        cout << "Success: " << s << " has been deleted!" << endl;
        if(node->left == nullptr && node->right == nullptr){
            if(node == root){
                root = nullptr;
                return;
            }
            if(node->parent->left != nullptr && node->parent->left->data->name == s){
                node->parent->left = nullptr;
                return;
            }
            else{
                node->parent->right = nullptr;
                return;
            }
        }

        else if(node->left == nullptr){ 
            if(node == root){
                root = node->right;
                node->right->parent = nullptr;
                return;
            }
            if(node->parent->left != nullptr && node->parent->left->data->name == s){
                node->parent->left = node->right;
                node->right->parent = node->parent;
                return;
            }
            else{
                node->parent->right = node->right;
                node->right->parent = node->parent;
                return;
            }            
        }

        else if(node->right == nullptr){
            if(node == root) {
                root = node->left;
                node->left->parent = nullptr;
                return;
            }
            if(node->parent->left != nullptr && node->parent->left->data->name == s){
                node->parent->left = node->left;
                node->left->parent = node->parent;
                return;
            }
            else{
                node->parent->right = node->left;
                node->left->parent = node->parent;
                return;
            } 
        } 

        else{
            if(node == root){
                SongNode* temp = node->left;
                if(temp->right == nullptr){
                    temp->right = node->right;
                    node->right->parent = temp;
                    root = temp;
                    temp->parent = nullptr;
                    return;
                }
                else{
                    while(temp->right != nullptr){
                        temp = temp->right;
                    }

                    temp->parent->right = nullptr;
                    temp->left = node->left;
                    node->left->parent = temp;
                    temp->right = node->right;
                    node->right->parent = temp;
                    root = temp;
                    temp->parent = nullptr;
                    return;
                }

            }
            if(node->parent->left != nullptr && node->parent->left->data->name == s){
                SongNode* temp = node->left;
                if(temp->right == nullptr){
                    node->parent->left = temp;
                    temp->parent = node->parent;
                    temp->right = node->right;
                    node->right->parent = temp;
                    return;
                }
                else{
                    while(temp->right != nullptr){
                        temp = temp->right;
                    }
                    temp->parent->right = nullptr;
                    node->parent->left = temp;
                    temp->parent = node->parent;
                    temp->left = node->left;
                    node->left->parent = temp;
                    temp->right = node->right;
                    node->right->parent = temp;
                    return;
                }              
            }
            else{
                SongNode* temp = node->left;
                if(temp->right == nullptr){
                    node->parent->right = temp;
                    temp->parent = node->parent;
                    temp->right = node->right;
                    node->right->parent = temp;
                    return;
                }
                else{
                    while(temp->right != nullptr){
                        temp = temp->right;
                    }
                    temp->parent->right = nullptr;
                    node->parent->right = temp;
                    temp->parent = node->parent;
                    temp->left = node->left;
                    node->left->parent = temp;
                    temp->right = node->right;
                    node->right->parent = temp;
                    return;
                }
            }
        }
    }
}


