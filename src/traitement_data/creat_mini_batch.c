#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

// Fonction pour créer un mini-batch à partir d'un tableau de données
matrix* createMiniBatch(double** data, int dataSize, int batchSize) {
    matrix* miniBatch = create_matrix(batchSize, dataSize);
    double train_image[NUM_TRAIN][SIZE];
    if (miniBatch == NULL) {
        printf("Erreur lors de l'allocation de mémoire pour le mini-batch.\n");
        return NULL;
    }

    for (int i = 0; i < batchSize; i++) {
        miniBatch[i] = (int*)malloc(dataSize * sizeof(int));
        if (miniBatch[i] == NULL) {
            printf("Erreur lors de l'allocation de mémoire pour le mini-batch.\n");
            return NULL;
        }
        for (int j = 0; j < dataSize; j++) {
            miniBatch[i][j] = data[i][j];
        }
    }

    return miniBatch;
}

// Fonction pour libérer la mémoire allouée pour un mini-batch
void freeMiniBatch(int** miniBatch, int batchSize) {
    for (int i = 0; i < batchSize; i++) {
        free(miniBatch[i]);
    }
    free(miniBatch);
}

int main() {
    // Exemple d'utilisation des fonctions createMiniBatch et freeMiniBatch
    double train_image[NUM_TRAIN][SIZE];

    // Création d'un tableau de données
    for (int i = 0; i < dataSize; i++) {
        data[i] = (int*)malloc(dataSize * sizeof(int));
        for (int j = 0; j < dataSize; j++) {
            data[i][j] = i + j;
        }
    }

    // Création d'un mini-batch à partir du tableau de données
    int** miniBatch = createMiniBatch(data, dataSize, batchSize);

    // Affichage du mini-batch
    printf("Mini-batch :\n");
    for (int i = 0; i < batchSize; i++) {
        for (int j = 0; j < dataSize; j++) {
            printf("%d ", miniBatch[i][j]);
        }
        printf("\n");
    }

    // Libération de la mémoire allouée pour le mini-batch
    freeMiniBatch(miniBatch, batchSize);

    // Libération de la mémoire allouée pour le tableau de données
    for (int i = 0; i < dataSize; i++) {
        free(data[i]);
    }
    free(data);

    return 0;
}
