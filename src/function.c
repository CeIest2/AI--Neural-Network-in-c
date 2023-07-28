#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include <struct.h>

void sigmoide_function(vector* vector_data, float lambda){
    // cette fonction modifie le vecteur entré en parramètre sans 
    // en créer un nouveau
    for(i=0;i<vector_data->size;i++){
        vector_data->data[i]=1/(1+exp(-vector_data->data[i] * lambda));
    }
    return vector_data;
}

void relu_function(vector* vector_data){
    // cette fonction modifie le vecteur entré en parramètre sans 
    // en créer un nouveau
    for(i=0;i<vector_data->size;i++){
        if(vector_data->data[i]<0){
            vector_data->data[i]=0;
        }
    }
    return vector_data;
}

void softmax_function(vector* vector_data){
    // cette fonction modifie le vecteur entré en parramètre sans 
    // en créer un nouveau
    float sum=0;
    for(i=0;i<vector_data->size;i++){
        sum+=exp(vector_data->data[i]);
    }
    for(i=0;i<vector_data->size;i++){
        vector_data->data[i]=exp(vector_data->data[i])/sum;
    }
    return vector_data;
}

void find_layer_values(vector* last_layer_data_vector, hidden_layer* actual_layer,int function_activattion_type){
    // on mutliplie la matrice de poids avec le vecteur de la couche précédente
    // puis y rajouter le biais et enfin appliquer la fonction d'activation
    // on retourne alors 
    actual_layer->vector_data = matrix_product(actual_layer->matrix_weight,last_layer_data_vector);
    for(i=0;i<actual_layer->vector_data->size;i++){
        actual_layer->vector_data->data[i]+=actual_layer->bias;
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