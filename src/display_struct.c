#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "struct.h"
#include "display_struct.h"

void print_matrix(matrix* matrix_data){
    if(matrix_data == NULL){
        printf("Matrix is NULL\n");
        return ;
    }
    printf("Matrix: %d x %d\n", matrix_data->rows, matrix_data->cols);
    for(int i=0;i<matrix_data->rows;i++){
        for(int j=0;j<matrix_data->cols;j++){
            printf("%f ", matrix_data->data[i][j]);
        }
        printf("\n");
    }
}


void print_NN(neural_network* NN_to_print){
    printf("========Neural Network========\n\n");
    if(NN_to_print == NULL){
        printf("Neural Network is NULL\n");
        return ;
    }
    if(NN_to_print->state == 0){
        printf("Neural Network is not initialized\n\n");
    }
    else{
        printf("Neural Network is initialized\n\n");
    }
    if(NN_to_print->input_layer_NN != NULL){
        printf("Input layer with %d neurons\n\n\n", NN_to_print->input_layer_NN->size);
    }
    else{
        printf("Input layer is NULL\n");
    }
    if(NN_to_print->list_hidden_layer_NN->nb_HL != 0){
        printf("Number of hidden layer : %d\n\n", NN_to_print->list_hidden_layer_NN->nb_HL);
        list_hidden_layer_queue* temp = NN_to_print->list_hidden_layer_NN->head_of_list;
        int i = 1;
        while(temp != NULL){
            printf("Hidden layer number %d with %d neurons\n",i, temp->hidden_layer_object->number_hidden_neural);
            temp = temp->next;
            i++;
        }
        printf("\n\n");
    }
    
    else{
        printf("Hidden layers is NULL\n");
    }
    if(NN_to_print->output_layer_NN != NULL){
        printf("Output layer with %d neurons\n", NN_to_print->output_layer_NN->size);
    }
    else{
        printf("Output layer is NULL\n");
    }
    printf("=====================================\n");
}