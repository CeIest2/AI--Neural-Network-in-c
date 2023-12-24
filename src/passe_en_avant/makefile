# Makefile dans le dossier passe_en_avant

# Listez les fichiers sources
SOURCES = forward_pass.c
DEPS = ../../include/forward_pass.h

# Définissez le nom de la bibliothèque partagée
TARGET = libforward_pass.so

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
