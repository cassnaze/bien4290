# This is the makefile to compile the vector_ops.cpp and the Lab 1 stats.cpp

# Compiler command to use
CC = g++

nazec_stats.o: nazec_stats.cpp nazec_stats.hpp
	$(CC) -c $^
nazec_vector_ops.o: nazec_vector_ops.cpp nazec_vector_ops.hpp
	$(CC) -c $^
nazec_pre_processing.o: nazec_pre_processing.cpp nazec_pre_processing.hpp nazec_vector_ops.cpp nazec_vector_ops.hpp nazec_stats.cpp nazec_stats.hpp
	$(CC) -c $^

machine: nazec_pre_processing.o nazec_stats.o nazec_vector_ops.o