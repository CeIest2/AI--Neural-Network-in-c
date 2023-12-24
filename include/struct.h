#ifndef __STRUCT_H__
#define __STRUCT_H__

typedef struct input input;
typedef struct mini_batch mini_batch;
typedef struct vector_label label_vector;
typedef struct input_layer input_layer;
typedef struct hidden_layer hidden_layer;
typedef struct output_layer output_layer;
typedef struct matrix matrix;
typedef struct list_hidden_layer_head list_hidden_layer_head;
typedef struct list_hidden_layer_queue list_hidden_layer_queue;
typedef struct neural_network neural_network;



matrix* create_matrix(int rows, int cols);
input* create_input(int size);
input_layer* create_input_layer(int size);
hidden_layer* create_hidden_layer(int number_hidden_layer, int number_hidden_last_layer);
output_layer* create_output_layer(int size);
list_hidden_layer_head* create_list_hidden_layer();
neural_network* create_neural_network();


void destroy_matrix(matrix* matrix_data);
void destroy_input(input* input_data);
void destroy_input_layer(input_layer* input_layer);
void destroy_hidden_layer(hidden_layer* hidden_layer_data);
void destroy_output_layer(output_layer* output_layer_data);
void destroy_list_hidden_layer(list_hidden_layer_head* head_of_HL_list);
void destroy_neural_network(neural_network* neural_network_data);

matrix* matrix_product(matrix* matrix1, matrix* matrix2);
matrix* matrix_sum(matrix* matrix1, matrix* matrix2);

void add_hidden_layer_to_list(int number_of_neural, list_hidden_layer_head* list_hidden_layer_tete);

void add_input_layer_NN(neural_network* neural_network_object, int number_of_neural);
void add_output_layer_NN(neural_network* neural_network_object, int number_of_neural);
void add_hidden_layer_NN(neural_network* neural_network_object,int number_of_layer, int number_of_neural);
void initialize_neural_network(neural_network* neural_network_object);

struct input{
    int size;                   // taille de l'input
    char* label;                // label de l'input
    matrix* data_vector_input;  // vecteur de l'input
};

struct mini_batch{
    int size_input;             // taille de l'input
    int size_batch;             // taille du batch
    matrix* data_matrix_input;  // matrice du batch, chaque ligne est un input
    char** label;               // label de l'input
};

struct label_vector {
    int size;             // taille du vecteur de labels
    char** labels;        // tableau de chaînes de caractères représentant les labels
};


struct matrix {
    // c'est une matrice, ça ce voit là
    int rows;                  // nombre de ligne de la matrice
    int cols;                  // nombre de colonne de la matrice
    float** data;              // matrice de float
};



struct input_layer{
    // vecteur de la taille de l'input, par exemple le nombre de pixel d'une image
    int size;                   // taille de l'input
    matrix* data_vector_input;  // vecteur de l'input
    matrix* bias;                 // biais de l'input
};

struct hidden_layer{
    
    int number_hidden_neural;     // nombre de neurone dans cette couche
    matrix* matrix_weight;        // matrice de la couche cachée
    matrix* bias;                  // valeur du biais de la couche
    matrix* vector_data;          // vecteur de la sortie de la couche de neurones 
    int function_type;            // type de fonction d'activation
};


struct output_layer{
    int size;                    // taille de l'output
    matrix* vector_data_output;  // vecteur de l'output
    matrix* bias;
    matrix* matrix_weight;       // matrice de la couche de sortie

};

struct list_hidden_layer_queue{
    hidden_layer* hidden_layer_object;        // hidden_layer, élément de la queue de la liste chaînée de HL
    list_hidden_layer_queue* next;            // prochain élément de la chaine
    list_hidden_layer_queue* previous;        // élément précédent de la chaine
};

struct list_hidden_layer_head{
    list_hidden_layer_queue* head_of_list;         // tête de la liste chaîné d' HL
    int nb_HL;                          // Nombre de HL dans cette liste
};

struct neural_network{
    // une fois que le réseau est considérer fixe on applique une fonction
    // pour initialiser toutes les valeurs dse poids en donc créer toutes
    // les matrices de poids de chaque couche

    input_layer* input_layer_NN;
    list_hidden_layer_head* list_hidden_layer_NN;
    output_layer* output_layer_NN;
    int number_of_hidden_layer;
    int state; // 0 = non initialisé, 1 = initialisé

};

#endif