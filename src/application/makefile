# Makefile dans le dossier application

# Listez les fichiers sources
SOURCES = application.c

# Définissez le nom de l'exécutable
EXECUTABLE = application

# Options de compilation
CC = gcc
CFLAGS = -Wall -Wextra -fsanitize=address
LDFLAGS = -I../../include -L../traitement_data -L../structures -lcreat_mini_batch -lstructures -lm

# Règle pour tout compiler
all: $(EXECUTABLE)

# Compilation des fichiers sources en exécutable
$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Règle pour nettoyer les fichiers générés
clean:
	rm -f $(EXECUTABLE)
