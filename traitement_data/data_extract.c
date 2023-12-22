#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char* data; // Vecteur d'image
    char label; // Étiquette de l'image sous forme de chaîne de caractères
} MNIST_Image;

// Lire le fichier IDX d'images
void read_mnist_images(const char* filename, MNIST_Image** images, int* num_images, int* image_size) {
    // Ouverture du fichier en mode binaire
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    // Lecture de l'en-tête
    int magic_number;
    fread(&magic_number, sizeof(int), 1, file); // Lire le magic number
    fread(num_images, sizeof(int), 1, file); // Lire le nombre d'images
    fread(image_size, sizeof(int), 1, file); // Lire la taille de l'image

    // Allocation de la mémoire pour les images
    *images = (MNIST_Image*)malloc(*num_images * sizeof(MNIST_Image));
    if (*images == NULL) {
        perror("Erreur lors de l'allocation de mémoire");
        exit(EXIT_FAILURE);
    }

    // Allocation de la mémoire pour les données d'une image
    unsigned char* image_data = (unsigned char*)malloc(*image_size * sizeof(unsigned char));
    if (image_data == NULL) {
        perror("Erreur lors de l'allocation de mémoire");
        exit(EXIT_FAILURE);
    }

    // Lecture des images
    for (int i = 0; i < *num_images; i++) {
        fread(image_data, sizeof(unsigned char), *image_size, file);

        (*images)[i].data = image_data;

        // Remplacer le code ci-dessous par la conversion des étiquettes en chaînes de caractères
        // (*images)[i].label = ???;
    }

    fclose(file);
}

int main() {
    MNIST_Image* images;
    int num_images, image_size;

    read_mnist_images("../data/train-images-idx3-ubyte", &images, &num_images, &image_size);

    // Maintenant vous avez accès à chaque image sous forme de vecteur dans 'images' et à son étiquette dans 'images[i].label'

    // N'oubliez pas de libérer la mémoire une fois que vous avez fini d'utiliser les données
    for (int i = 0; i < num_images; i++) {
        free(images[i].data);
    }
    free(images);

    return 0;
}
