all: build run

build:
	g++ -I ./include/ -o ./lib/dllist.o -c ./libfdr/dllist.c
	g++ -I ./include/ -o ./lib/fields.o -c ./libfdr/fields.c
	g++ -I ./include/ -o ./lib/jrb.o -c ./libfdr/jrb.c
	g++ -I ./include/ -o ./lib/jval.o -c ./libfdr/jval.c
	g++ -I ./include/ -o ./lib/main.o -c ./src/main.c
	g++ -I ./include/ -o ./bin/Test ./lib/main.o ./lib/jval.o ./lib/jrb.o ./lib/fields.o ./lib/dllist.o ./src/main.c

run:
	./bin/Test