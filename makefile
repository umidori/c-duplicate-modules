all: get_line

clean:
	rm -f get_line main.o get_line1.o get_line2.o

get_line: main.o get_line1.o get_line2.o
	cc -o get_line main.o get_line1.o get_line2.o

main.o: main.c get_line1.h get_line2.h
	cc -c main.c

get_line1.o: get_line1.c get_line1.h
	cc -c get_line1.c

get_line2.o: get_line2.c get_line2.h
	cc -c get_line2.c
