CC=gcc
OBJECTS_MAIN_SORT=sort.o sortmain.o
OBJECTS_MAIN_TXT_FIND=find.o main.o
FLAGS= -Wall -g -fPIC
PROGRAMS= sortmain main


all: $(PROGRAMS)
sortmain: $(OBJECTS_MAIN_SORT)
	$(CC) $(FLAGS) -o sortmain $(OBJECTS_MAIN_SORT) -lm
sort.o: sort.c sort.h
	$(CC) $(FLAGS) -c iSortUtils.c
sortmain.o: sortmain.c sort.h
	$(CC) $(FLAGS) -c sortmain.c


main: $(OBJECTS_MAIN_TXT_FIND)
	$(CC) $(FLAGS) -o txtfind $(OBJECTS_MAIN_TXT_FIND) -lm
find.o: find.c find.h
	$(CC) $(FLAGS) -c find.c
main.o: main.c find.h
	$(CC) $(FLAGS) -c main.c
.PHONY: clean all

clean:
	rm -f *.o *.so $(PROGRAMS)