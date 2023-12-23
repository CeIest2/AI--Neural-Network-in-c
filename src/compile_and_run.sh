#!/bin/bash

# Partie 1 : Compilation de la partie principale (src)
echo "Compilation de la partie principale (src)..."
cd /mnt/c/Users/Win10/Documents/projet\ info/reseau\ de\ neuronnes/src
make

# Vérification si la compilation a réussi
if [ $? -eq 0 ]; then
    echo "Compilation réussie. Exécution de l'exécutable..."
    # Exécution de l'exécutable généré
    ./output/nom_de_votre_executable
else
    echo "Erreur lors de la compilation de la partie principale (src)."
fi

# Partie 2 : Compilation du sous-projet OpenGL (test_open_gl)
echo "Compilation du sous-projet OpenGL (src)..."
cd /mnt/c/Users/Win10/Documents/projet\ info/reseau\ de\ neuronnes/src/build
cmake ..
make

# Vérification si la compilation a réussi
if [ $? -eq 0 ]; then
    echo "Compilation réussie. Exécution de l'exécutable..."
    # Exécution de l'exécutable généré
    ./OpenGLTest
else
    echo "Erreur lors de la compilation du sous-projet OpenGL (test_open_gl)."
fi
