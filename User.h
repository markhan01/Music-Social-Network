#ifndef User_H
#define User_H
#include "Library.h"
class User{
    public:
    string name;
    Library library;
    int visited;
    vector<User*> friendlist;
    User();
    User(string);
    int friend_exist(string);
    void add_friend(User*);
    void show_friends();
    void delete_friend(string);
};
#endif