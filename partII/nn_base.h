#ifndef NN_BASE_H
#define NN_BASE_H

typedef struct NeuralNetwork
{
    int I; // Number of input units
    int H; // Number of hidden units
    int O; // Number of output units
} NeuralNetwork_t;

typedef struct Weight
{
    int from_layer; // Index of the source layer
    int from_unit;  // Index of the source unit
    int to_layer;   // Index of the destination layer
    int to_unit;    // Index of the destination unit
    double weight;  // Weight of the connection
} Weight_t;

NeuralNetwork_t *create_neural_network(int I, int H, int O);
void free_neural_network(NeuralNetwork_t *nn);

Weight_t *create_weights(int num_weights);
void free_weights(Weight_t *weights);

int load_weights(NeuralNetwork_t *nn, Weight_t **weights, const char *filename);
int save_weights(NeuralNetwork_t *nn, Weight_t *weights, const char *filename);
void propagate_input(NeuralNetwork_t *nn, Weight_t *weights, double *input, double *output);

#endif
