# Makefile for library

# Change this value to select a different TestFile
t=1

all: my_scheduler.o threads.o libult.a libs project2 k2u

my_scheduler.o: threads.h my_scheduler.c
	gcc -g -c -std=gnu99 -Wall -Wextra -Wno-unused-parameter threads.h my_scheduler.c -lrt

threads.o: threads.c threads.h my_scheduler.c
	gcc -g -c -std=gnu99 -Wall -Wextra -Wno-unused-parameter threads.c threads.h my_scheduler.c -lrt

libult.a: threads.o my_scheduler.o
	ar rcs libult.a threads.o my_scheduler.o

libs: libult.a

project2: libult.a TestFile$(t).c
	gcc -g -std=gnu99 -o project2 TestFile$(t).c -L . -lult -lrt
#create regular project 2
k2u: libult.a ut_test.c
	gcc -g -std=gnu99 -o k2u ut_test.c -L . -lult -lrt
#creates seperate project with alternative test file for testing 3.2 tasks
		

clean:
	rm -rf *.o libult libult.a project2 k2u *.gch

.PHONY: all project2 clean

