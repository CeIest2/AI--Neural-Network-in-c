# Makefile dans le dossier structures

# Listez les fichiers sources
SOURCES = struct.c weight_function.c
DEPS = ../../include/struct.h ../../include/weight_function.h

# Définissez le nom de la bibliothèque partagée
TARGET = libstructures.so

# Options de compilation
CC = gcc
CFLAGS = -Wall -Wextra -fsanitize=address -fsanitize=address -shared -fPIC
LDFLAGS = -lm

# Règle pour tout compiler
all: $(TARGET)

# Compilation des fichiers sources en bibliothèque partagée
$(TARGET): $(SOURCES) $(DEPS)
	$(CC) $(CFLAGS) $(SOURCES) -o $@ -I../../include $(LDFLAGS)

# Règle pour nettoyer les fichiers générés
clean:
	rm -f $(TARGET)