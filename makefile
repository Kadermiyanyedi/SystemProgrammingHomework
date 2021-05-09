all: build run

build:
	gcc -o ./lib/dllist.o -c ./libfdr/dllist.c
	gcc -o ./lib/fields.o -c ./libfdr/fields.c
	gcc -o ./lib/jrb.o -c ./libfdr/jrb.c
	gcc -o ./lib/jval.o -c ./libfdr/jval.c
	gcc -o ./lib/main.o -c ./src/main.c
	gcc -o ./bin/main ./lib/main.o ./lib/jval.o ./lib/jrb.o ./lib/fields.o ./lib/dllist.o

run:
	./bin/main