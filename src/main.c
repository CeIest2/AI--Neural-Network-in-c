#include <stdio.h>
#include "struct.h"
#include "function.h"



int main(){
    printf("Hello World\n");

    neural_network* test_NN = create_neural_network();
    add_hidden_layer_NN(test_NN,2,2);
    add_input_layer_NN(test_NN,2);
    add_output_layer_NN(test_NN,2);

    printf("test \n");
    destroy_neural_network(test_NN);


    return 0 ;
}   

