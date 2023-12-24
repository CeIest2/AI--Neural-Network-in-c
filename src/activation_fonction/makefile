# Makefile dans le dossier activation_fonction

# Listez les fichiers sources
SOURCES = activation_function.c
DEPS = ../../include/activation_function.h

# Définissez le nom de la bibliothèque partagée
TARGET = libactivation_function.so

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