#include <stdio.h>
#include "struct.h"
#include "function.h"
#include "display_struct.h"



int main(){
    printf("Hello World\n");

    neural_network* test_NN = create_neural_network();


    add_input_layer_NN(test_NN, 2);
    add_hidden_layer_NN(test_NN, 2, 2);
    add_output_layer_NN(test_NN, 2);
    print_NN(test_NN);

    add_hidden_layer_NN(test_NN, 3, 5);
    print_NN(test_NN);
    initialize_neural_network(test_NN);
    print_matrix(test_NN->list_hidden_layer_NN->head_of_list->hidden_layer_object->matrix_weight);
    destroy_neural_network(test_NN);

    return 0 ;
}   

