
CC=gcc
AR=ar
FLAGS= -Wall -g

all: mysort isort myfind txtfind


txtfind: main.o myfind
	$(CC) $(FLAGS) -o txtfind main.o libmyFind.a
myfind: libmyFind.a
libmyFind.a: find.o
	$(AR) -rcs libmyFind.a texter.o
find.o: find.c find.h
	$(CC) $(FLAGS) -c find.c
main.o: main.c find.h
	$(CC) $(FLAGS) -c main.c -o main.o





isort: sortmain.o mysort
	$(CC) $(FLAGS) -o isort sortmain.o libmySort.a
mysort: libmySort.a
libmySort.a: sort.o
	$(AR) -rcs libmySort.a sort.o
sort.o: sort.c sort.h
	$(CC) $(FLAGS) -c sort.c
sortmain.o: sortmain.c sort.h
	$(CC) $(FLAGS) -c sortmain.c -o sortmain.o

.PHONY: clean all mysort myfind

clean:
	rm -f *.o *.a *.so isort txtfind)