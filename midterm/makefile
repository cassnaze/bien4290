# This is the makefile created for the midterm
CC = g++
toss_a_coin.o: toss_a_coin.cpp toss_a_coin.hpp
	$(CC) -c $^
valley_of_plenty.o: valley_of_plenty.cpp valley_of_plenty.hpp
	$(CC) -c $^
wolf.o: wolf.cpp wolf.hpp
	$(CC) -c $^
dandelion.o: toss_a_coin.o valley_of_plenty.o wolf.o
	$(CC) -c /lab/bien4290/midterm2022/Simple $^
clean:
	rm -f *.o
all: dandelion.o toss_a_coin.o valley_of_plenty.o wolf.o
