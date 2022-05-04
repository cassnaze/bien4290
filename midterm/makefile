# This is the makefile created for the midterm
CC = g++
brennanb_corr.o:brennanb_corr.cpp brennanb_corr.hpp
	$(CC) -c $^
brennanb_stats.o:brennanb_stats.cpp brennanb_stats.hpp
	$(CC) -c $^
Simple.o:brennanb_corr.o brennanb_stats.o
	$(CC) -c $@ $^
all:Simple.o
clean:
	rm -f *.o
	rm -f *.gch
