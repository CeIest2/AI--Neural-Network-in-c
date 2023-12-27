#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "mnist.h"



label_vector* creat_label_vector(int size_label_vector){
    label_vector* new_label_vector = (label_vector*)malloc(sizeof(label_vector));
    new_label_vector->size = size_label_vector;
    new_label_vector->labels = (int*)malloc(sizeof(int)*size_label_vector);

    return new_label_vector;
}

list_mini_batch* create_mini_batch(double** data_set, int* data_label, int size_mini_batch, int start_index){
    list_mini_batch* new_list_mini_batch = (list_mini_batch*)malloc(sizeof(list_mini_batch));
    new_list_mini_batch->mini_batch_object = (mini_batch*)malloc(sizeof(mini_batch));
    new_list_mini_batch->mini_batch_object->size_input = SIZE;
    new_list_mini_batch->mini_batch_object->size_batch = size_mini_batch;
    new_list_mini_batch->next = NULL;
    new_list_mini_batch->mini_batch_object->data_matrix_input = create_matrix(size_mini_batch, SIZE);
    new_list_mini_batch->mini_batch_object->data_vector_label = creat_label_vector(size_mini_batch);

    // on va maintenant remplir la matrice avec les données
    int i, j;
    for(i = 0; i < size_mini_batch; i++){
        new_list_mini_batch->mini_batch_object->data_vector_label->labels[i] = data_label[start_index + i];
        for(j = 0; j < SIZE; j++){
            new_list_mini_batch->mini_batch_object->data_matrix_input->data[i][j] = data_set[start_index + i][j];
        }
    }

    return new_list_mini_batch;
}

batch* create_list_mini_batch(int nb_mini_batch, double** data_set, int* data_label){
    // on calcul le nombre d'input dans chaque mini batch
    int size_mini_batch = NUM_TRAIN / nb_mini_batch;

    // on calcul le nombre d'input dans le dernier mini batch du data set
    int size_last_mini_batch = NUM_TRAIN % nb_mini_batch;

    // on crée la tête de la liste
    batch* new_batch = (batch*)malloc(sizeof(batch));
    int i;
    list_mini_batch* current_mini_batch = NULL;
    for(i = 0; i < nb_mini_batch; i++){
        if(current_mini_batch == NULL){
            new_batch->head_of_list = create_mini_batch(data_set, data_label, size_mini_batch, 0);
            current_mini_batch = new_batch->head_of_list;
        }
        else if(i == nb_mini_batch - 1){
            current_mini_batch->next = create_mini_batch(data_set, data_label, size_last_mini_batch, i * size_mini_batch);
            current_mini_batch = current_mini_batch->next;
        }
        else{
            current_mini_batch->next = create_mini_batch(data_set, data_label, size_mini_batch, i * size_mini_batch);
            current_mini_batch = current_mini_batch->next;
        }
    }
    return new_batch;
}



void free_label_vector(label_vector* lv) {
    if (lv != NULL) {
        free(lv->labels);
        free(lv);
    }
}

void free_matrix(matrix* mat) {
    if (mat != NULL) {
        int i;
        for (i = 0; i < mat->rows; i++) {
            free(mat->data[i]);
        }
        free(mat->data);
        free(mat);
    }
}

void free_mini_batch(mini_batch* mb) {
    if (mb != NULL) {
        free_matrix(mb->data_matrix_input);
        free_label_vector(mb->data_vector_label);
        free(mb);
    }
}

void free_list_mini_batch(list_mini_batch* lmb) {
    if (lmb != NULL) {
        list_mini_batch* current = lmb;
        while (current != NULL) {
            list_mini_batch* next = current->next;
            free_mini_batch(current->mini_batch_object);
            free(current);
            current = next;
        }
    }
}

void free_batch(batch* b) {
    if (b != NULL) {
        free_list_mini_batch(b->head_of_list);
        free(b);
    }
}
    

