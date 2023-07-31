#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "struct.h"
#include "weight_function.h"

// Fonction pour initialiser un poids selon la méthode de Xavier (Glorot)
float xavier_weight_init(int n_in, int n_out) {
    // Calcul de la variance en fonction du nombre d'entrées (n_in) et de sorties (n_out)
    float variance = 2.0 / (n_in + n_out);

    // Calcul de l'écart-type (racine carrée de la variance)
    float std_deviation = sqrt(variance);

    // Génération d'un nombre aléatoire à partir d'une distribution gaussienne avec moyenne 0 et écart-type std_deviation
    float weight = ((float)rand() / RAND_MAX) * 2 * std_deviation - std_deviation;

    return weight;
}

void init_matrix_weight(matrix* matrix_to_init, int nb_in, int nb_out){
    srand(time(NULL));

    // dans cette fonction on va initialiser les poids pour une matrice
    // on va utiliser la méthode de Xavier pour initialiser les poids
    for(int i=0;i<matrix_to_init->rows;i++){
        for(int j=0;j<matrix_to_init->cols;j++){
            matrix_to_init->data[i][j]=xavier_weight_init(nb_in,nb_out);
        }
    }
    return ;
}



void init_weight_and_bias(neural_network* NN_to_initialized){
    // dans cette fonction on va initialiser les poids et les biais pour tout le réseau
    // on va utiliser la méthode de Xavier pour initialiser les poids

    list_hidden_layer_queue* current_hidden_layer = NN_to_initialized->list_hidden_layer_NN->head_of_list;

    int nb_in = NN_to_initialized->input_layer_NN->size;
    int nb_out;
    if (NN_to_initialized->list_hidden_layer_NN->head_of_list->next == NULL){
        nb_out = NN_to_initialized->output_layer_NN->size;
    }
    else{
        nb_out = NN_to_initialized->list_hidden_layer_NN->head_of_list->next->hidden_layer_object->number_hidden_neural;
    }
    
    while(current_hidden_layer->next !=NULL){
        init_matrix_weight(current_hidden_layer->hidden_layer_object->matrix_weight, nb_in, nb_out);
        init_matrix_weight(current_hidden_layer->hidden_layer_object->bias, nb_in, nb_out);
        nb_in = current_hidden_layer->hidden_layer_object->number_hidden_neural;
        current_hidden_layer = current_hidden_layer->next;
        if(current_hidden_layer->next ==NULL){
            nb_out = NN_to_initialized->output_layer_NN->size;
        }
        else{

            nb_out = current_hidden_layer->next->hidden_layer_object->number_hidden_neural;
        }
    }   

    // on init maintenant la dernière couche ( celle de l output)
    init_matrix_weight(NN_to_initialized->output_layer_NN->matrix_weight, nb_in, nb_out);
    init_matrix_weight(NN_to_initialized->output_layer_NN->bias, nb_in, nb_out);

}
