#include "User.h"
User::User(){
    name = "";
}

User::User(string s){
    name = s;
    visited = 0;
}

int User::friend_exist(string u){
    for(int i = 0; i < friendlist.size(); i++){
        if(friendlist[i]->name == u){
            return 1;
        }
    }
    return 0;
}

void User::add_friend(User* u){
    if(friend_exist(u->name)){
        cout << "Error: " << u->name << " already exist in your friendlist!" << endl;
    }
    else{
        friendlist.push_back(u);
        cout << "Success: " << u->name << " has been added to your friendlist!" << endl;
    }
}


void User::show_friends(){
    vector<User*>::iterator it;
    for(it = friendlist.begin(); it != friendlist.end(); it++){
        cout << (*it)->name << endl;
    }   
}

void User::delete_friend(string u){
    vector<User*>::iterator it;
    for(it = friendlist.begin(); it != friendlist.end(); it++){
        if((*it)->name == u){
            friendlist.erase(it);
            cout << "Sucess: " << u << " has been deleted from your friendlist!" << endl;
            return;
        }
    }
    cout << "Error: " << u << " doesn't exist in your friendlist!" << endl;   
}
