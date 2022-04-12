
# Compiler command to use
CC = g++
SHELL = /bin/bash
CFLAGS = -fPIC -g
LDFLAGS = -lm -lstats
LIBDIR = /home/nazec/bien4290/Lab1 
# where stats library will be
INCDIR = /home/nazec/bien4290/Lab1 
# where stats header is

libstats.so:
	cd "/home/nazec/Lab1" && make libstats.so

airspeed: nazec_MiniProject1.cpp
	make libstats.so
	$(CC) $(CFLAGS)	-I$(INCDIR) -o $@ $^ -Wl,-rpath=$(LIBDIR) -L$(LIBDIR) $(LDFLAGS)
