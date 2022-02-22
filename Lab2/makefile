# This is the makefile to compile the vector_ops.cpp and the Lab 1 stats.cpp

# Compiler command to use
CC = g++

# The .o is what compiles
nazec_stats.o: nazec_stats.cpp nazec_stats.hpp
	$(CC) -c $^
nazec_vector_ops.o: nazec_vector_ops.cpp nazec_vector_ops.hpp
	$(CC) -c $^
nazec_pre_processing.o: nazec_pre_processing.cpp nazec_pre_processing.hpp nazec_vector_ops.o nazec_stats.o
	$(CC) -o $@ $^

# Run all of the things that we just did above
# The executable will be the nazec_pre_processing.o in the folder
all: nazec_pre_processing.o nazec_stats.o nazec_vector_ops.o

clean:
	rm -f *.o
	rm -f *.gch