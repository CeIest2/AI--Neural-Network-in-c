#ifndef __STRUCT_H__
#define __STRUCT_H__

typedef struct input input;
typedef struct hidden_layer hidden_layer;
typedef struct output_layer output_layer;

struct input{
    //vecteur de la taille de l'input, par exemple le nombre de pixel d'une image
    int size; //taille de l'input
    float* data; //vecteur de l'input
    float bias; //biais de l'input
};

struct hidden_layer{
    //matrice taille nombre de neurone de la couche cachée * taille de la couche précédante
    int number_hidden_layer;
    int number_hidden_last_layer; //nombre de neurone de la couche cachée
    float** matrix_of_weight; //matrice de la couche cachée
    float bias;
    float* data; //vecteur de la couche cachée
    int function_type; //type de fonction d'activation
};


struct output_layer{
    int size; //taille de l'output
    float* data; //vecteur de l'output

};



#endif