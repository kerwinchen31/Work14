all: work14.o
	gcc -o go work14.o

work13.o: work14.c
	gcc -c work14.c

run:
	./go

clean:
	rm *.o
	rm ./go

