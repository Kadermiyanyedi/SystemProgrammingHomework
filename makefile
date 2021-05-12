all: make cleanoutputfile run clean

make:
	gcc -o ./dllist.o -c ./dllist.c
	gcc -o ./fields.o -c ./fields.c
	gcc -o ./jrb.o -c ./jrb.c
	gcc -o ./jval.o -c ./jval.c
	gcc -o ./main.o -c ./main.c
	gcc -o ./kripto ./main.o ./jval.o ./jrb.o ./fields.o ./dllist.o

run: cleanoutputfile
	./kripto -e ./input.txt ./output.txt
	./kripto -d ./output.txt ./output2.txt


clean:
	rm *.o

cleanoutputfile: 
	rm -rf output.txt
	rm -rf output2.txt
cleanall:
	rm -rf *.o
	rm -rf *.txt
	rm -rf .kilit
	rm kripto