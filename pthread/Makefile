# HEADERS = program.h headers.h

default: kt_test

# program.o: program.c $(HEADERS)
#     gcc -c program.c -o program.o

p_func.o: p_func.c
	gcc -c -std=gnu99 -pthread p_func.c -o p_func.o -lrt

kt_test: kt_test.c p_func.o
	gcc -g -std=gnu99 -pthread kt_test.c p_func.o -o kt_test -lrt

clean:
	-rm -f kt_test p_func.o