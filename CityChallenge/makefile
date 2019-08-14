#
# This is an example Makefile for a countwords program.  This
# program uses both the scanner module and a counter module.
# Typing 'make' or 'make count' will create the executable file.
#

# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
#
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#
# for C++ define  CC = g++
CC = g++
CFLAGS  = -g -Wall

# typing 'make' will invoke the first target entry in the file 
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
#
default: all clean

# all
all: main.o lib.o metric.o sortList.o config.h lib.h metric.h  sortList.h
	$(CC) $(CFLAGS) -o all main.o lib.o metric.o sortList.o

# main.o
main.o:  main.cpp config.h lib.h metric.h
	$(CC) $(CFLAGS) -c main.cpp

# lib.o
lib.o:  lib.cpp lib.h config.h
	$(CC) $(CFLAGS) -c lib.cpp

# metric.o
metric.o: metric.cpp metric.h lib.h sortList.h
	$(CC) $(CFLAGS) -c metric.cpp

# sortList
sortList.o: sortList.cpp sortList.h config.h
	$(CC) $(CFLAGS) -c sortList.cpp

# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean: 
	$(RM) *.o *~