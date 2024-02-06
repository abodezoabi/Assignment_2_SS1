PHONY = all clean 
CC=gcc
TARGET=my_mat.o  my_graph.o
all=connections

CFLAGS = -Wall -g



all: $(TARGET)
	$(CC) $(TARGET) -o $(all)
my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFLAGS) -c my_mat.c
main.o: my_graph.c my_mat.h
	$(CC) $(CFLAGS) -c my_graph.c

clean:
	rm -f *.o *.a connections