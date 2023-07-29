#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include <struct.h>


vector* create_vector(int size){
    vector* vector_data = malloc(sizeof(vector));
    vector_data->size   = size;
    vector_data->data   = malloc(sizeof(float)*size);
    return vector_data;
}

void destroy_vector(vector* vector_data){
    free(vector_data->data);
    free(vector_data);
}

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
    for(int i=0;i<matrix_data->rows;i++){
        free(matrix_data->data[i]);
    }
    free(matrix_data->data);
    free(matrix_data);
}

input* create_input(int size){
    input* input_object             = malloc(sizeof(input));
    input_object->size              = size;
    input_object->data_vector_input = create_vector(size);
    input_object->bias              = 0;
    return input_object;
}

void destroy_input(input* input_data){
    destroy_vector(input_data->data_vector_input);
    free(input_data);
}

hidden_layer* create_hidden_layer(int number_hidden_layer, int number_hidden_last_layer){
    hidden_layer* hidden_layer_data             = malloc(sizeof(hidden_layer));
    hidden_layer_data->number_hidden_layer      = number_hidden_layer;
    hidden_layer_data->number_hidden_last_layer = number_hidden_last_layer;
    hidden_layer_data->matrix_weight = create_matrix(number_hidden_layer,number_hidden_last_layer);
    hidden_layer_data->bias          = 0;
    hidden_layer_data->vector_data = create_vector(number_hidden_layer);
    hidden_layer_data->function_type = 0;
    return hidden_layer_data;
}

void destroy_hidden_layer(hidden_layer* hidden_layer_data){
    destroy_matrix(hidden_layer_data->matrix_weight);
    destroy_vector(hidden_layer_data->vector_data);
    free(hidden_layer_data);
}

output_layer* create_output_layer(int size){
    output_layer* output_layer_data = malloc(sizeof(output_layer));
    output_layer_data->size = size;
    output_layer_data->vector_data_output = create_vector(size);
    return output_layer_data;
}

void destroy_output_layer(output_layer* output_layer_data){
    destroy_vector(output_layer_data->vector_data_output);
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
    list_hidden_layer_tete->next = NULL;

    return list_hidden_layer_tete;
}

void destroy_list_hidden_layer(list_hidden_layer_head* head_of_HL_list){
    // ici on détruit la liste chainé, on détruit d'abord les HL puis on détruit la tête

    list_hidden_layer* list_hidden_layer_courant = head_of_HL_list->next;
    list_hidden_layer* list_hidden_layer_next = NULL;
    while(list_hidden_layer_courant != NULL){
        list_hidden_layer_next = list_hidden_layer_courant->next;
        destroy_hidden_layer(list_hidden_layer_courant->hidden_layer_data);
        free(list_hidden_layer_courant);
        list_hidden_layer_courant = list_hidden_layer_next;
    }
    free(head_of_LD_list);
}


void add_hidden_layer_to_list(int number_of_neural, list_hidden_layer_head* list_hidden_layer_tete){
    // on commence par parcourir la liste chainée et on rajoute à la fin
    // une nouvelle couche que l'on créer ave la fonction create_hidden_layer

    list_hidden_layer* list_hidden_layer_courant = list_hidden_layer_tete;
    while(list_hidden_layer_courant->next != NULL){
        list_hidden_layer_courant = list_hidden_layer_courant->next;
    }
    list_hidden_layer_courant->next = create_hidden_layer(number_of_neural,list_hidden_layer_courant->number_of_neural);
}

neural_network* create_neural_network(){
    neural_network* neural_network_object = malloc(sizeof(neural_network));
    neural_network_object->input_data = NULL;
    neural_network_object->output_layer_data = NULL;
    neural_network_object->list_hidden_layer_tete = create_list_hidden_layer();
    return neural_network_object;
}

void destroy_neural_network(neural_network* neural_network_object){
    destroy_input(neural_network_object->input_data);
    destroy_output_layer(neural_network_object->output_layer_data);
    destroy_list_hidden_layer(neural_network_object->list_hidden_layer_tete);
    free(neural_network_object);
}