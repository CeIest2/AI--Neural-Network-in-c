#ifndef __WEIGHT_FUNCTION_H__
#define __WEIGHT_FUNCTION_H__

float xavier_weight_init(int n_in, int n_out);
void init_matrix_weight(matrix* matrix_to_init, int nb_int, int nb_out);
void init_weight_and_bias(neural_network* NN_to_initialized);

#endif