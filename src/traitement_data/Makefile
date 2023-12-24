# Makefile dans le dossier traitement_data

CC = gcc
CFLAGS = -Wall -Wextra -fsanitize=address -fsanitize=address
SRC = example.c
OBJ = $(SRC:.c=.o)
EXE = example

# Ajoutez ici la règle pour construire le fichier objet .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I../../include

# Ajoutez ici la règle pour construire l'exécutable
$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE) -lm

clean:
	rm -f $(EXE) $(OBJ)