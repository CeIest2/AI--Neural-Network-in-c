#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "mnist.h"
#include "creat_mini_batch.h"

int main(void){
    // Charger le dataset MNIST
    printf("hello 1 \n");
    load_mnist();
    printf("hello 1 \n");
    // Créer les mini-batchs
    int batch_size = 32;

    double** train_image_ptr = malloc(NUM_TRAIN * sizeof(double*));
    for (int i = 0; i < NUM_TRAIN; i++) {
        train_image_ptr[i] = train_image[i];
    }
    batch* batch_data = create_list_mini_batch(batch_size, train_image_ptr, train_label);
 

    printf("hello 1 \n");


    // Libérer la mémoire
    free_batch(batch_data);
    printf("hello 1 \n");
    return 0;
}
    
