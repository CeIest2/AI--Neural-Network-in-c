# Compilateur à utiliser
CC := gcc

# Options de compilation
CFLAGS := -Wall -Wextra -fsanitize=address,undefined

# Nom de l'exécutable à générer
TARGET := main

# Liste des sources (ajoutez plus de fichiers .c ici si nécessaire)
SOURCES := main.c struct.c

# Liste des fichiers d'en-tête (ajoutez plus de fichiers .h ici si nécessaire)
HEADERS := struct.h

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)
