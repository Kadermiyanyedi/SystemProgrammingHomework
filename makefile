LIBS = ./libfdr.a

run: clean make kriptola

make:
	gcc -I ./ -o kripto main.c $(LIBS)

kriptola:
	./kripto -e ./input.txt ./encripted.txt
	./kripto -d ./encripted.txt ./decripted.txt

clean:
	rm -rf kripto encripted.txt decripted.txt *.o

cleanall:
	rm -rf *.o
	rm -rf *.txt
	rm -rf .kilit
	rm rrf kripto