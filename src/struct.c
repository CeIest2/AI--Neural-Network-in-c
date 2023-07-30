#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "struct.h"



matrix* create_matrix(int rows, int cols){
    matrix* matrix_data      = malloc(sizeof(matrix));
    matrix_data->rows        = rows;
    matrix_data->cols        = cols;
    matrix_data->data        = malloc(sizeof(float*)*rows);
    for(int i=0;i<rows;i++){
        matrix_data->data[i] = malloc(sizeof(float)*cols);
    }
    return matrix_data;
}

void destroy_matrix(matrix* matrix_data){
    if(matrix_data == NULL){
        return ;
    }
    printf("destroy matrix in function\n");
    for(int i=0;i<matrix_data->rows;i++){
        if(matrix_data->data[i] != NULL){
            free(matrix_data->data[i]);
        }
    }
    printf(" after boucle\n");
    printf(" matrix_data->data = %p\n",matrix_data->data);
    if(matrix_data->data != NULL){
        printf("oui\n");
        free(matrix_data->data);
        printf("non \n");
    }
    printf(" after free data\n");
    free(matrix_data);
    printf(" after free matrix\n");
}

input* create_input(int size){
    input* input_object             = malloc(sizeof(input));
    input_object->size              = size;
    input_object->data_vector_input = create_matrix(size,1);
    input_object->bias              = create_matrix(size,1);
    return input_object;
}

void destroy_input(input* input_data){
    if(input_data != NULL){
        destroy_matrix(input_data->data_vector_input);
        destroy_matrix(input_data->bias);
        free(input_data);
    }
}

input_layer* create_input_layer(int size){
    input_layer* new_input_layer = malloc(sizeof(input_layer));
    new_input_layer->size = size;
    new_input_layer->data_vector_input = create_matrix(size,1);
    new_input_layer->bias = create_matrix(size,1);
    return new_input_layer;
}

void destroy_input_layer(input_layer* input_layer){
    if(input_layer == NULL){
        return ;
    }
    destroy_matrix(input_layer->data_vector_input);
    destroy_matrix(input_layer->bias);
    free(input_layer);
}

hidden_layer* create_hidden_layer(int number_hidden_neural, int number_hidden_last_layer){
    hidden_layer* hidden_layer_data              = malloc(sizeof(hidden_layer));
    hidden_layer_data->number_hidden_neural      = number_hidden_neural;
    hidden_layer_data->matrix_weight = create_matrix(number_hidden_neural,number_hidden_last_layer);
    hidden_layer_data->bias          = create_matrix(number_hidden_neural,1);
    hidden_layer_data->vector_data = create_matrix(number_hidden_neural,1);
    hidden_layer_data->function_type = 0;
    return hidden_layer_data;
}

void destroy_hidden_layer(hidden_layer* hidden_layer_data){
    printf(" destroy hidden layer pointer matrix : %p \n", hidden_layer_data);
    printf("hidden_layer_data->vector_data %p\n",hidden_layer_data->vector_data);
    printf("hidden_layer_data->bias %p\n",hidden_layer_data->bias);
    printf("hidden_layer_data->matrix_weight %p\n",hidden_layer_data->matrix_weight);
    if(hidden_layer_data == NULL){
        printf("ok\n");
        return ;
    }
    printf("suite \n");
    if(hidden_layer_data->matrix_weight!=NULL){
        destroy_matrix(hidden_layer_data->matrix_weight);
    }

    printf("suite 2 \n");
    destroy_matrix(hidden_layer_data->vector_data);
    destroy_matrix(hidden_layer_data->bias);
    printf(" après matrix\n");
    free(hidden_layer_data);
    printf(" après free\n");
}

output_layer* create_output_layer(int size){
    output_layer* output_layer_data = malloc(sizeof(output_layer));
    output_layer_data->size = size;
    output_layer_data->vector_data_output = create_matrix(size,1);
    return output_layer_data;
}

void destroy_output_layer(output_layer* output_layer_data){
    if(output_layer_data == NULL){
        return ;
    }
    destroy_matrix(output_layer_data->vector_data_output);
    free(output_layer_data);
}

matrix* matrix_product(matrix* matrix1, matrix* matrix2){
    matrix* matrix_result = create_matrix(matrix1->rows,matrix2->cols);
    for(int i=0;i<matrix1->rows;i++){
        for(int j=0;j<matrix2->cols;j++){
            float sum = 0;
            for(int k=0;k<matrix1->cols;k++){
                sum += matrix1->data[i][k]*matrix2->data[k][j];
            }
            matrix_result->data[i][j] = sum;
        }
    }
    return matrix_result;
}

matrix* matrix_sum(matrix* matrix1, matrix* matrix2){
    matrix* matrix_result = create_matrix(matrix1->rows,matrix1->cols);
    for(int i=0;i<matrix1->rows;i++){
        for(int j=0;j<matrix1->cols;j++){
            matrix_result->data[i][j] = matrix1->data[i][j]+matrix2->data[i][j];
        }
    }
    return matrix_result;
}


list_hidden_layer_head* create_list_hidden_layer(){
    // ici on créer une liste chainé de HL vide, donc on créer juste la tête
    // donc pour utiliser une liste de HL d'abord on la crer avec cette fonction
    // puis on utilise la fonction add_hidden_layer pour ajouter des HL

    list_hidden_layer_head* list_hidden_layer_tete = malloc(sizeof(list_hidden_layer_head));
    list_hidden_layer_tete->nb_HL = 0;
    list_hidden_layer_tete->head_of_list = malloc(sizeof(list_hidden_layer_queue));
    list_hidden_layer_tete->head_of_list->hidden_layer_object = NULL;
    list_hidden_layer_tete->head_of_list->next = NULL;

    return list_hidden_layer_tete;
}

void destroy_list_hidden_layer(list_hidden_layer_head* head_of_HL_list){
    if(head_of_HL_list == NULL){
        return ;
    }
    // ici on détruit la liste chainé, on détruit d'abord les HL puis on détruit la tête
    list_hidden_layer_queue* current_HL = head_of_HL_list->head_of_list;
    free(head_of_HL_list);
    printf("test3.5\n");
    while (current_HL != NULL) {
        printf("test3.6\n");
        printf("current_HL = %p\n",current_HL);
        list_hidden_layer_queue* next_HL = current_HL->next; // Avant de libérer current_HL
        printf(" next_HL = %p\n",next_HL);
        destroy_hidden_layer(current_HL->hidden_layer_object); // Libérer la mémoire allouée pour le HL courant
        free(current_HL); // Libérer la mémoire allouée pour le maillon courant
        if(next_HL == NULL){
            printf("nest est null\n");
        }
        current_HL = next_HL; // Mettre à jour current_HL avec next_HL pour la prochaine itération

    }
    if(current_HL!=NULL){
        free(current_HL);
    }

}


void add_hidden_layer_to_list(int number_of_neural, list_hidden_layer_head* list_hidden_layer_tete){
    // on commence par parcourir la liste chainée et on rajoute à la fin
    // une nouvelle couche que l'on créer ave la fonction create_hidden_layer
    if(list_hidden_layer_tete->head_of_list->hidden_layer_object == NULL){
        // cas ou la liste est vide
        hidden_layer* new_hidden_layer = create_hidden_layer(number_of_neural,2);
        list_hidden_layer_tete->head_of_list->hidden_layer_object = new_hidden_layer;
        list_hidden_layer_tete->nb_HL++;
    }
    else{
    list_hidden_layer_queue* list_hidden_layer_courant = list_hidden_layer_tete->head_of_list;

    
    while(list_hidden_layer_courant->next != NULL){
        list_hidden_layer_courant = list_hidden_layer_courant->next;
    }
    hidden_layer* new_hidden_layer = create_hidden_layer(number_of_neural,list_hidden_layer_courant->hidden_layer_object->number_hidden_neural);
    printf("test\n");
    list_hidden_layer_courant->next = malloc(sizeof(list_hidden_layer_queue));
    list_hidden_layer_courant->next->hidden_layer_object = new_hidden_layer;
    list_hidden_layer_tete->nb_HL++;
    list_hidden_layer_courant->next->next = NULL;
    }
}

void add_many_hidden_layer_to_list(int number_of_neural, list_hidden_layer_head* list_hidden_layer_tete, int number_of_hidden_layer){
    // on commence par parcourir la liste chainée et on rajoute à la fin
    // une nouvelle couche que l'on créer ave la fonction create_hidden_layer

    for(int i=0;i<number_of_hidden_layer;i++){
        add_hidden_layer_to_list(number_of_neural, list_hidden_layer_tete);
    }
}

void add_hidden_layer_NN(neural_network* neural_network_object,int number_of_layer, int number_of_neural){
    add_many_hidden_layer_to_list(number_of_neural, neural_network_object->list_hidden_layer_NN, number_of_layer);
}

void add_input_layer_NN(neural_network* neural_network_object, int number_of_neural){
    neural_network_object->input_layer_NN = create_input_layer(number_of_neural);
}

void add_output_layer_NN(neural_network* neural_network_object, int number_of_neural){
    neural_network_object->output_layer_NN = create_output_layer(number_of_neural);
}

neural_network* create_neural_network(){
    neural_network* neural_network_object = malloc(sizeof(neural_network));
    neural_network_object->input_layer_NN = NULL;
    neural_network_object->output_layer_NN = NULL;
    neural_network_object->list_hidden_layer_NN = create_list_hidden_layer();
    return neural_network_object;
}

void destroy_neural_network(neural_network* neural_network_object){
    if(neural_network_object == NULL){
        return;
    }
    printf("fin\n");

    destroy_input_layer(neural_network_object->input_layer_NN);
    printf("fin2\n");
    destroy_output_layer(neural_network_object->output_layer_NN);
    printf("fin3\n");
    destroy_list_hidden_layer(neural_network_object->list_hidden_layer_NN);
    printf("fin4\n");
    free(neural_network_object);
    printf("fin5\n");
}