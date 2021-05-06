#include "User.h"
User::User(){
    name = "";
    size = 0;
}

User::User(string s){
    name = s;
    size = 0;
}

void User::add_friend(User u){
    friendlist.push_back(u);
    size++;
}

void User::delete_friend(User u){
    vector<User>::iterator it;
    for(it = friendlist.begin(); it != friendlist.end(); it++){
        if((*it).name == u.name){
            friendlist.erase(it);
        }
    }   
}
