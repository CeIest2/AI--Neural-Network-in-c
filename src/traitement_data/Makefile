# Makefile dans le dossier traitement_data

# Listez les fichiers sources
SOURCES = creat_mini_batch.c

# Définissez le nom de la bibliothèque partagée
TARGET = libcreat_mini_batch.so

# Options de compilation
CC = gcc
CFLAGS = -Wall -Wextra -fsanitize=address -shared -fPIC
LDFLAGS = -lm

# Chemin vers la bibliothèque partagée de structures
STRUCTURES_LIB = ../structures/libstructures.so

# Règle pour tout compiler
all: $(TARGET)

# Compilation des fichiers sources en bibliothèque partagée
$(TARGET): $(SOURCES) $(STRUCTURES_LIB)
	$(CC) $(CFLAGS) $^ -o $@ -I../../include -L../structures -lstructures $(LDFLAGS)

# Règle pour nettoyer les fichiers générés
clean:
	rm -f $(TARGET)
