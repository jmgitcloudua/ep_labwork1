#include <stdio.h>
#include <stdlib.h>

// Define data structures for the neural network and connection weights

typedef struct {
    int I;        // Number of input units
    int H;        // Number of hidden units
    int O;        // Number of output units
} NeuralNetwork;

typedef struct {
    int from_unit; // Unit in the source layer
    int to_unit;   // Unit in the target layer
    float weight;  // Weight of the connection
} ConnectionWeight;

int ReadFromFile(NeuralNetwork* nn, ConnectionWeight** weights){

    FILE *file;
    file = fopen( "weights.txt" , "r");
    //int i, h, o;
    fscanf(file, "%d %d %d", &(nn->I), &(nn->H), &(nn->O)); 
    fclose(file);
    return 1;  // Successfully loaded weights
}
int main() {
    
    NeuralNetwork nn;
    ConnectionWeight* weights;

    ReadFromFile(&nn, &weights);
    printf("Number of inputs: %d.\n", nn.I);
    printf("Number of Hidden: %d.\n", nn.H);
    printf("Number of Outputs: %d.\n", nn.O);

    system("pause");
    return 0;
}