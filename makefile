
# Special target .PHONY is used to declare non-file targets.
.PHONY = all clean 

# Compiler to use
CC=gcc

# Target object files
TARGET=my_mat.o  my_graph.o

# The final executable to build
all=connections

# Compiler flags: -Wall for all warnings, -g for debugging information
CFLAGS = -Wall -g

# The default target: Compiles the TARGET object files and links them into the final executable named 'connections'.
all: $(TARGET)
	$(CC) $(TARGET) -o $(all)

# Compiles my_mat.c into my_mat.o
my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFLAGS) -c my_mat.c

# Compiles my_graph.c into my_graph.o
my_graph.o: my_graph.c my_mat.h
	$(CC) $(CFLAGS) -c my_graph.c

# Cleans up the directory by removing the object files and the 'connections' executable.
clean:
	rm -f *.o *.a connections