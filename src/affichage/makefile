# Makefile dans le dossier affichage

# Listez les fichiers sources
SOURCES = display_struct.c
DEPS = ../../include/display_struct.h

# Définissez le nom de la bibliothèque partagée
TARGET = libdisplay_struct.so

# Options de compilation
CC = gcc
CFLAGS = -Wall -Wextra -fsanitize=address -fsanitize=address -shared -fPIC
LDFLAGS = -lm

# Règle pour tout compiler
all: $(TARGET)

# Compilation des fichiers sources en bibliothèque partagée
$(TARGET): $(SOURCES) $(DEPS)
	$(CC) $(CFLAGS) $< -o $@ -I../../include $(LDFLAGS)

# Règle pour nettoyer les fichiers générés
clean:
	rm -f $(TARGET)