/*
Commands:
show system songs
add song ()
show MainUser songs
add user ()
friend () ()
show users
show friends ()
unfriend () ()
set radius ()
set count ()
play (user) (song)
recommend () songs
delete song ()
exit
*/

#include "User.h"
#include "PARSER.h"
#include <fstream>
int withinEFN = 0;
vector<User*> system_users;

int user_exist(string n){
    for(int i = 0; i < system_users.size(); i++){
        if(system_users[i]->name == n){
            return i;
        }
    }
    return -1;
}

void def_not_DFS(User* currentUser, User* MainUser, int radius){ 
    if (radius < 0) {
        return;
    }  

    currentUser->visited = 1;
    if (currentUser->name == MainUser->name) {
        withinEFN = 1;
        return;
    }

    for(int i = 0; i < currentUser->friendlist.size(); i++){
        if(withinEFN == 1){
            return;
        }

        if(currentUser->friendlist[i]->visited == 0){
            def_not_DFS(currentUser->friendlist[i], MainUser, radius - 1);
        }

        else if(currentUser->friendlist[i]->visited == 1 && radius - 1 >= 0){
            def_not_DFS(currentUser->friendlist[i], MainUser, radius - 1);
        }
    } 
}

int main(){
    Library system_library;  
    string input;
    int radius = -1;
    int count = -1;

    User* MainUser = new User("MainUser");
    system_users.push_back(MainUser);

    ifstream file1("Songs.txt");
    string line1;
    while(getline(file1, line1)){
        system_library.add_song(line1, system_library.heap.size());
    }

    ifstream file2("Users.txt");
    string line2;
    while(getline(file2, line2)){
        User* u = new User(line2);
        system_users.push_back(u);
    }

    system_users[0]->add_friend(system_users[1]);
    system_users[1]->add_friend(system_users[0]);
    system_users[0]->add_friend(system_users[2]);
    system_users[2]->add_friend(system_users[0]);
    system_users[1]->add_friend(system_users[2]);
    system_users[2]->add_friend(system_users[1]);
    system_users[2]->add_friend(system_users[5]);
    system_users[5]->add_friend(system_users[2]);
    system_users[2]->add_friend(system_users[8]);
    system_users[8]->add_friend(system_users[2]);
    system_users[2]->add_friend(system_users[7]);
    system_users[7]->add_friend(system_users[2]);
    system_users[7]->add_friend(system_users[8]);
    system_users[8]->add_friend(system_users[7]);
    system_users[1]->add_friend(system_users[3]);
    system_users[3]->add_friend(system_users[1]);
    system_users[3]->add_friend(system_users[4]);
    system_users[4]->add_friend(system_users[3]);
    system_users[4]->add_friend(system_users[6]);
    system_users[6]->add_friend(system_users[4]);
    system_users[6]->add_friend(system_users[9]);
    system_users[9]->add_friend(system_users[6]);



    while(1){
        cout << "Enter command: " << endl;
        getline(cin, input);
		Parser command(input);

        if(command.getOperation() == "show" && command.getArg1() == "system" && command.getArg2() == "songs"){
            system_library.show_songs();
        }

        else if(command.getOperation() == "add" && command.getArg1() == "song" && command.getArg2() != ""){
            system_library.add_song(command.getArg2(), system_library.heap.size());
        }

        else if(command.getOperation() == "show" && command.getArg1() == "MainUser" && command.getArg2() == "songs"){
            system_users[0]->library.show_songs();
        }

        // add user user_name
		else if (command.getOperation() == "add" && command.getArg1() == "user" && command.getArg2() != "") {
            if(user_exist(command.getArg2()) == -1){
                User* u = new User(command.getArg2());
                system_users.push_back(u);
            }
            else{
                cout << "Error: " << command.getArg2() << " already exist!" << endl;
            }
        }

        // friend user_name1 user_name2
        else if(command.getOperation() == "friend" && command.getArg1() != "" && command.getArg2() != ""){
            int f1 = -1;
            int f2 = -1;
            for(int i = 0; i < system_users.size(); i++){
                if(system_users[i]->name == command.getArg1()){
                    f1 = i;
                }
                if(system_users[i]->name == command.getArg2()){
                    f2 = i;
                }
            }
            if(f1 != -1 && f2 != -1){
                system_users[f1]->add_friend(system_users[f2]);
                system_users[f2]->add_friend(system_users[f1]);
            }
            else{
                cout << "Error: Friend(s) cannot be found!" << endl;
            }
        }

        // show users
        else if(command.getOperation() == "show" && command.getArg1() == "users" && command.getArg2() == ""){
            for(int i = 0; i < system_users.size(); i++){
                cout << system_users[i]->name << endl;
            }
        }

        // show friends user_name
        else if(command.getOperation() == "show" && command.getArg1() == "friends" && command.getArg2() != ""){
            if(user_exist(command.getArg2()) != -1){
                system_users[user_exist(command.getArg2())]->show_friends();
            }
            else{
                cout << "Error: User not found!" << endl;
            }
        }

        // unfriend friend1 friend2
        else if(command.getOperation() == "unfriend" && command.getArg1() != "" && command.getArg2() != ""){
            if(user_exist(command.getArg1()) != -1 && user_exist(command.getArg2()) != -1){
                system_users[user_exist(command.getArg1())]->delete_friend(command.getArg2());
                system_users[user_exist(command.getArg2())]->delete_friend(command.getArg1());
            }
            else{
                cout << "Error: User not found!" << endl;
            }
        }

        else if(command.getOperation() == "set" && command.getArg1() == "radius" && command.getArg2() != ""){
            radius = stoi(command.getArg2());
        }

        else if(command.getOperation() == "set" && command.getArg1() == "count" && command.getArg2() != ""){
            count = stoi(command.getArg2());
        }
        
        // play user1 song1
        else if(command.getOperation() == "play" && command.getArg1() != "" && command.getArg2() != ""){
            if(radius < 1 || count < 1){
                cout << "Error: Invalid radius or count!" << endl;
                continue;
            }
            if(user_exist(command.getArg1()) == -1 || system_library.song_exist(system_library.songs->root, command.getArg2()) == 0){
                cout << "Error: user/song not found!" << endl;
            }
            else{
                def_not_DFS(system_users[user_exist(command.getArg1())], MainUser, radius);
                if(withinEFN == 1 && MainUser->library.song_exist(MainUser->library.songs->root, command.getArg2()) == 0){
                    system_library.play(system_library.songs->root, command.getArg2(), count);
                    withinEFN = 0;
                }
                else{
                    cout << "Error: The user is either not within EFN or the song already exist in MainUser's library!" << endl;
                }
            }
        }

        else if(command.getOperation() == "recommend" && command.getArg1() != "" && command.getArg2() == "songs"){
            for(int i = 0; i < stoi(command.getArg1()); i++){
                if(system_library.heap[0]->play_count == 0){
                    cout << "Error: No recommendation!" << endl;
                    break;
                }
                system_users[0]->library.recommend(system_library.extract_max());
            }
        }

        else if(command.getOperation() == "delete" && command.getArg1() == "song" && command.getArg2() != ""){
            system_users[0]->library.songs->delete_song(system_users[0]->library.songs->root, command.getArg2());

            if(system_library.get_song(command.getArg2()) != nullptr){

                system_library.get_song(command.getArg2())->index = system_library.heap.size();              
                system_library.heap.push_back(system_library.get_song(command.getArg2()));
            }
        }

        else if(command.getOperation() == "show" && command.getArg1() == "heap" && command.getArg2() == ""){
            for(int i = 0; i < system_library.heap.size(); i++){
                cout << system_library.heap[i]->name << endl;
                cout << system_library.heap[i]->index << endl;
            }

        }
        
        else if(command.getOperation() == "exit" && command.getArg1() == "" && command.getArg2() == ""){
            break;
        }
        else{
            cout << "Invalid input" << endl;
        }
    }   

    cout << "\ndone" << endl;
    return 0;
}

/*  
    g++ User.cpp System.cpp Song.cpp SongNode.cpp SongBST.cpp Library.cpp -o driver
*/



