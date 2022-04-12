CC = g++
SHELL = /bin/bash
CFLAGS = -fPIC -c

nazec_stats.o: nazec_stats.cpp nazec_stats.hpp
	$(CC) $(CLFLAGS) -o $@ -lm

libstats.so: nazec_stats.cpp nazec_stats.hpp
	$(CC) -shared $^ -o $@

clean: libstats.so nazec_stats.o
	rm -f *.o
	rm -f *.so