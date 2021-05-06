#include "User.h"

int main(){
    Library system_library;
    vector<User> system_users;

    User u0("MainUser");
    User u1("u1");
    User u2("u2");
    User u3("u3");
    User u4("u4");
    User u5("u5");
    User u6("u6");
    User u7("u7");
    User u8("u8");
    User u9("u9");
    User u10("u10");

    system_users.push_back(u0);
    system_users.push_back(u1);
    system_users.push_back(u2);
    system_users.push_back(u3);
    system_users.push_back(u4);
    system_users.push_back(u5);
    system_users.push_back(u6);
    system_users.push_back(u7);
    system_users.push_back(u8);
    system_users.push_back(u9);
    system_users.push_back(u10);

    system_library.add_song("song0", 0);
    system_library.add_song("song1", 1);
    system_library.add_song("song2", 2);
    system_library.add_song("song3", 3);
    system_library.add_song("song4", 4);
    system_library.add_song("song5", 5);
    system_library.add_song("song5", 5);
    system_library.add_song("song6", 6);
    system_library.add_song("song7", 7);
    system_library.add_song("song7", 7);


    


    
   
    
    cout << "***********************************************************************" << endl;

    system_library.play(system_library.songs->root, "song7");
    system_library.play(system_library.songs->root, "song7");
    system_library.play(system_library.songs->root, "song7");
    system_library.play(system_library.songs->root, "song7");

    system_library.play(system_library.songs->root, "song2");
    system_library.play(system_library.songs->root, "song2");
    system_library.play(system_library.songs->root, "song2");

    system_library.show_songs();

    for(int i = 0; i < system_library.heap_index; i++){
        cout << system_library.heap[i]->name << endl;
        cout << system_library.heap[i]->play_count << endl;
    }

   
    return 0;
}