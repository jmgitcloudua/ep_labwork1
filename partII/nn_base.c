#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nn_base.h"

NeuralNetwork_t *create_neural_network(int I, int H, int O)
{
    NeuralNetwork_t *nn = (NeuralNetwork_t *)malloc(sizeof(NeuralNetwork_t));
    nn->I = I;
    nn->H = H;
    nn->O = O;
    return nn;
}

void free_neural_network(NeuralNetwork_t *nn)
{
    free(nn);
}

Weight_t *create_weights(int num_weights)
{
    Weight_t *weights = (Weight_t *)malloc(num_weights * sizeof(Weight_t));
    return weights;
}

void free_weights(Weight_t *weights)
{
    free(weights);
}

int load_weights(NeuralNetwork_t *nn, Weight_t **weights, const char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error occurred while trying to open the file\n");
        return 1;
    }

    int I, H, O;
    if (fscanf(fp, "%d %d %d", &I, &H, &O) != 3 || I != nn->I || H != nn->H || O != nn->O)
    {
        fprintf(stderr, "Invalid architecture in the file\n");
        fclose(fp);
        return 1;
    }

    int num_weights = I * H + H * O;

    // Allocate memory for weights
    *weights = (Weight_t *)malloc(num_weights * sizeof(Weight_t));

    if (*weights == NULL)
    {
        fprintf(stderr, "Memory allocation for weights failed\n");
        fclose(fp);
        return 1;
    }

    int li, ui, lo, uo;
    double w;
    int weight_index = 0;

    while (fscanf(fp, "%d:%d %d:%d %lf", &li, &ui, &lo, &uo, &w) == 5)
    {
        if (weight_index >= num_weights)
        {
            fprintf(stderr, "Too many weights in the file\n");
            fclose(fp);
            free(*weights);
            return 1;
        }

        (*weights)[weight_index].from_layer = li;
        (*weights)[weight_index].from_unit = ui;
        (*weights)[weight_index].to_layer = lo;
        (*weights)[weight_index].to_unit = uo;
        (*weights)[weight_index].weight = w;
        weight_index++;
        // printf("I = %d, H = %d, O = %d\n", I, H, O);
        // printf("%d:%d %d:%d %.4lf\n", li, ui, lo, uo, w);
    }

    fclose(fp);
    return 0;
}

int save_weights(NeuralNetwork_t *nn, Weight_t *weights, const char *filename)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        fprintf(stderr, "Error occurred while trying to open the file for writing\n");
        return 1;
    }

    // Write the architecture information
    fprintf(fp, "%d %d %d\n", nn->I, nn->H, nn->O);

    int num_weights = nn->I * nn->H + nn->H * nn->O;

    for (int i = 0; i < num_weights; i++)
    {

        fprintf(fp, "%d:%d %d:%d %.4lf\n", weights[i].from_layer, weights[i].from_unit, weights[i].to_layer, weights[i].to_unit, weights[i].weight);
    }

    fclose(fp);
    return 0;
}

double activate_unit(double input, double weight)
{
    // We can implement any activation function here.
    // For now, we are using a simple linear activation function.
    return input * weight;
}

void propagate_input(NeuralNetwork_t *nn, Weight_t *weights, double *input, double *output)
{
    // int num_weights = nn->I * nn->H + nn->H * nn->O;

    // Initialize the output layer with zeros
    for (int i = 0; i < nn->O; i++)
    {
        output[i] = 0.0;
    }

    // Propagate input through the hidden layer
    for (int i = 0; i < nn->H; i++)
    {
        output[i] = 0.0;
        for (int j = 0; j < nn->I; j++)
        {
            int weight_idx = i * nn->I + j;
            output[i] += activate_unit(input[j], weights[weight_idx].weight);
        }
    }

    // Propagate through the output layer
    for (int i = 0; i < nn->O; i++)
    {
        for (int j = 0; j < nn->H; j++)
        {
            int weight_idx = nn->H * nn->I + i * nn->H + j;
            output[i] += activate_unit(output[j], weights[weight_idx].weight);
        }
    }
}