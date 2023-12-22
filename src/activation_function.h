#ifndef __ACTIVATION_FUNCTION_H__
#define __ACTIVATION_FUNCTION_H__


void sigmoide_function(matrix* vector_data, float lambda);
void relu_function(matrix* vector_data);
void softmax_function(matrix* vector_data);
void find_layer_values(matrix* last_layer_data_vector, hidden_layer* actual_layer,int function_activattion_type);










#endif