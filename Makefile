
CC=gcc
AR=ar
FLAGS= -Wall -g

all: mysort isort myfind txtfind


txtfind: txtfind_main.o myfind
	$(CC) $(FLAGS) -o txtfind txtfind_main.o libmyFind.a
myfind: libmyFind.a
libmyFind.a: txtfind.o
	$(AR) -rcs libmyFind.a txtfind.o
txtfind.o: txtfind.c txtfind.h
	$(CC) $(FLAGS) -c txtfind.c
txtfind_main.o: txtfind_main.c txtfind.h
	$(CC) $(FLAGS) -c txtfind_main.c -o txtfind_main.o



isort: isort_main.o mysort
	$(CC) $(FLAGS) -o isort isort_main.o libmySort.a
mysort: libmySort.a
libmySort.a: isort.o
	$(AR) -rcs libmySort.a isort.o
isort.o: isort.c isort.h
	$(CC) $(FLAGS) -c isort.c
isort_main.o: isort_main.c isort.h
	$(CC) $(FLAGS) -c isort_main.c -o isort_main.o

.PHONY: clean all mysort myfind

clean:
	rm -f *.o *.a *.so isort txtfind
