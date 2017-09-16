# HEADERS = program.h headers.h

default: kt_test

# program.o: program.c $(HEADERS)
#     gcc -c program.c -o program.o

p_func.o: p_func.c
	gcc -c -pthread p_func.c -o p_func.o

kt_test: kt_test.c p_func.o
	gcc -g -pthread kt_test.c p_func.o -o kt_test

clean:
	-rm -f kt_test p_func.o