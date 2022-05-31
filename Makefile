


main: main.o league.o schedule.o game.o team.o
	clang++-9 main.o league.o schedule.o game.o team.o -o main

main.o: main.cpp
	clang++-9 -std=c++2a -g -Wall -c main.cpp

league.o: league.cpp
	clang++-9 -std=c++2a -g -Wall -c league.cpp

schedule.o: schedule.cpp
	clang++-9 -std=c++2a -g -Wall -c schedule.cpp

game.o: game.cpp
	clang++-9 -std=c++2a -g -Wall -c game.cpp

team.o: team.cpp
	clang++-9 -std=c++2a -g -Wall -c team.cpp

clean: 
	rm -f *.o main