#ifndef CREAT_MINI_BATCH_H
#define CREAT_MINI_BATCH_H

#include "struct.h"

label_vector* creat_label_vector(int size_label_vector);

list_mini_batch* create_mini_batch(double** data_set, int* data_label, int size_mini_batch, int start_index);

batch* create_list_mini_batch(int nb_mini_batch, double** data_set, int* data_label);

void free_label_vector(label_vector* lv);

void free_matrix(matrix* mat);

void free_mini_batch(mini_batch* mb);

void free_list_mini_batch(list_mini_batch* lmb);

void free_batch(batch* b);

int main(void);


#endif // CREAT_MINI_BATCH_H
