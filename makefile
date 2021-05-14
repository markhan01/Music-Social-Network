# makefile

all: Driver

Driver: Library.o Song.o SongBST.o SongNode.o System.o User.o
	g++ Library.o Song.o SongBST.o SongNode.o System.o User.o -o Driver

Library.o: Library.cpp
	g++ -c Library.cpp

Song.o: Song.cpp
	g++ -c Song.cpp

SongBST.o: SongBST.cpp
	g++ -c SongBST.cpp

SongNode.o: SongNode.cpp
	g++ -c SongNode.cpp

System.o: System.cpp
	g++ -c System.cpp

User.o: User.cpp
	g++ -c User.cpp

clean:
	rm -f *.o Driver
