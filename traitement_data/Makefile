CC = gcc
CFLAGS = -Wall -Wextra -fsanitize=address -fsanitize=address
SRC = example.c
OBJ = $(SRC:.c=.o)
EXE = main

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE) -lm

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXE) $(OBJ)
example.o: example.c mnist.h
	$(CC) $(CFLAGS) -c example.c -o example.o
