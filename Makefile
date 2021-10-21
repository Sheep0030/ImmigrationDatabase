# This makefile is intended to build the two test programs for
# CPE100 Lab Lab. It also shows how to create and use a simple
# makefile
#
# Note that this makefile assumes a Linux environment. The executables
# have no extension.
#
# Updated 21 October 2014 by Sally Goldin
#
# Chotiya Pertpring (Fon) ID: 62070503413

EXECUTABLES =  ImmigrationDatabase

all : $(EXECUTABLES)

validate.o : validate.c validate.h
	gcc -c validate.c

option.o : option.c option.h validate.h dateFunctions.h 
	gcc -c option.c

dateFunctions.o : dateFunctions.c dateFunctions.h
	gcc -c dateFunctions.c

fileoption.o : fileoption.c fileoption.h
	gcc -c fileoption.c

ImmigrationDatabase.o : ImmigrationDatabase.c option.h
	gcc -c ImmigrationDatabase.c

ImmigrationDatabase : ImmigrationDatabase.o validate.o option.o dateFunctions.o fileoption.o
	gcc -o ImmigrationDatabase ImmigrationDatabase.o validate.o option.o dateFunctions.o fileoption.o

clean : 
	-rm *.o
	-rm ImmigrationDatabase

