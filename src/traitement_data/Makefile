# Makefile dans le dossier activation_fonction

# Listez les fichiers sources
SOURCES = creat_mini_batch.c
DEPS = ../../include/creat_mini_batch.h

# Définissez le nom de la bibliothèque partagée
TARGET = libcreat_mini_batch.so
EXECUTABLE = creat_mini_batch

# Options de compilation
CC = gcc
CFLAGS = -g -Wall -Wextra -fsanitize=address -shared -fPIC
LDFLAGS = -lm

# Règle pour tout compiler
all: $(TARGET) $(EXECUTABLE)

# Compilation des fichiers sources en bibliothèque partagée
$(TARGET): $(SOURCES) $(DEPS)
	$(CC) $(CFLAGS) $< -o $@ -I../../include $(LDFLAGS)

# Compilation du fichier exécutable
$(EXECUTABLE): $(SOURCES) $(DEPS)
	$(CC) $(CFLAGS) $^ -o $@ -I../../include $(LDFLAGS)

# Règle pour nettoyer les fichiers générés
clean:
	rm -f $(TARGET) $(EXECUTABLE)
