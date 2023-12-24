#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "struct.h"

void sigmoide_function(matrix* vector_data, float lambda){
    // cette fonction modifie le vecteur entré en parramètre sans 
    // en créer un nouveau
    // fonction sigmoide : 1/(1+exp(-x*lambda))
    for(int i=0;i<vector_data->rows;i++){
        vector_data->data[i][0]=1/(1+exp(-vector_data->data[i][0] * lambda));
    }
    return ;
}

void relu_function(matrix* vector_data){
    // cette fonction modifie le vecteur entré en parramètre sans 
    // en créer un nouveau
    // fonction relu : max(0,x) 
    for(int i=0;i<vector_data->rows;i++){
        if(vector_data->data[i][0]<0){
            vector_data->data[i]=0;
        }
    }
    return ;
}

void softmax_function(matrix* vector_data){
    // cette fonction modifie le vecteur entré en parramètre sans 
    // en créer un nouveau
    // fonction softmax : exp(x)/sum(exp(x))
    float sum=0;
    for(int i=0;i<vector_data->rows;i++){
        sum+=exp(vector_data->data[i][0]);
    }
    for(int i=0;i<vector_data->rows;i++){
        vector_data->data[i][0]=exp(vector_data->data[i][0])/sum;
    }
    return ;
}

void find_layer_values(matrix* last_layer_data_vector, hidden_layer* actual_layer,int function_activattion_type){
    // on mutliplie la matrice de poids avec le vecteur de la couche précédente
    // puis y rajouter le biais et enfin appliquer la fonction d'activation
    // on retourne alors 
    actual_layer->vector_data = matrix_product(actual_layer->matrix_weight,last_layer_data_vector);
    for(int i=0;i<actual_layer->vector_data->rows;i++){
        actual_layer->vector_data->data[i][0]+=actual_layer->bias->data[i][0];
    }
    if(function_activattion_type==1){
        sigmoide_function(actual_layer->vector_data,1);
    }
    else if(function_activattion_type==2){
        relu_function(actual_layer->vector_data);
    }
    else if(function_activattion_type==3){
        softmax_function(actual_layer->vector_data);
    }
    else{
        sigmoide_function(actual_layer->vector_data,1);
    }
    

}