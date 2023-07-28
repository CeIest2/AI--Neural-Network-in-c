#ifndef __STRUCT_H__
#define __STRUCT_H__

typedef struct input_layer input_layer;
typedef struct hidden_layer hidden_layer;
typedef struct output_layer output_layer;
typedef struct matrix matrix;
typedef struct vector vector;
typedef struct list_hidden_layer_head list_hidden_layer_head;
typedef struct list_hidden_layer_queue list_hidden_layer_queue;
typedef struct neural_network neural_network;


struct matrix {
    // c'est une matrice, ça ce voit là
    int rows;                  // nombre de ligne de la matrice
    int cols;                  // nombre de colonne de la matrice
    float** data;              // matrice de float
};

struct vector{
    // c'est un vecteur
    int size;                  // taille du vecteur
    float* data;               // list de float
};

struct input_layer{
    // vecteur de la taille de l'input, par exemple le nombre de pixel d'une image
    int size;                   // taille de l'input
    vector* data_vector_input;  // vecteur de l'input
    float bias;                 // biais de l'input
};

struct hidden_layer{
    
    int number_hidden_layer;      // nombre de neurone dans cette couche
    matrix* matrix_weight;        // matrice de la couche cachée
    float bias;                   // valeur du biais de la couche
    vector* vector_data;          // vecteur de la sortie de la couche de neurones 
    int function_type;            // type de fonction d'activation
};


struct output_layer{
    int size;                    // taille de l'output
    vector* vector_data_output;  // vecteur de l'output

};

struct list_hidden_layer_queue{
    hidden_layer* hidden_layer_object;  // hidden_layer, élément de la queue de la liste chaînée de HL
    list_hidden_layer* next;            // prochain élément de la chaine
};

struct list_hidden_layer_head{
    hidden_layer* head_of_list;         // tête de la liste chaîné d' HL
    int nb_HL;                          // Nombre de HL dans cette liste
};

struct neural_network{
    // une fois que le réseau est considérer fixe on applique une fonction
    // pour initialiser toutes les valeurs dse poids en donc créer toutes
    // les matrices de poids de chaque couche

    input_layer* input_layer_NN;
    hidden_layer* hidden_layer_NN;
    output_layer* output_layer_NN;
    int number_of_hidden_layer;

};

#endif