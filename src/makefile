CC = gcc
CFLAGS = -Wall -Wextra -fsanitize=address -fsanitize=address
SRC = main.c struct.c function.c
OBJ = $(SRC:.c=.o)
EXE = main

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE) -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXE) $(OBJ)
