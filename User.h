#ifndef User_H
#define User_H
#include "Library.h"
class User{
    public:
    string name;
    int size;
    Library library;
    vector<User> friendlist;
    User();
    User(string);
    void add_friend(User);
    void delete_friend(User);
};
#endif