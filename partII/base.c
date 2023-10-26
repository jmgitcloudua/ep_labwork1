// base.c
#include <stdio.h>
#include "nn_base.h"

int main()
{
    int I, H, O; // Variables to store architecture values

    // Open a file to read the architecture values
    FILE *architectureFile = fopen("weights.txt", "r");
    if (architectureFile == NULL)
    {
        fprintf(stderr, "Error occurred while trying to open the architecture file\n");
        return 1;
    }

    // Read the architecture values from the file
    if (fscanf(architectureFile, "%d %d %d", &I, &H, &O) != 3)
    {
        fprintf(stderr, "Invalid architecture in the file\n");
        fclose(architectureFile);
        return 1;
    }

    // Close the architecture file
    fclose(architectureFile);

    // Create a neural network with the values read from the file
    NeuralNetwork_t *nn = create_neural_network(I, H, O);

    // Declare a pointer to Weight
    Weight_t *weights;

    // Load weights from a file
    if (load_weights(nn, &weights, "weights.txt") != 0)
    {
        return 1;
    }

    // Define an array for input values
    double input[2] = {1.0, 2.0};

    // Allocate space for output values
    double output[1];

    // Propagate the input through the network
    propagate_input(nn, weights, input, output);

    // Display the result
    printf("Output[Propagate Input]: %.4lf\n", output[0]);

    // Save the weights back to a file
    if (save_weights(nn, weights, "saved_weights.txt") != 0)
    {
        return 1;
    }
    printf("Weights saved to file successfully\n");

    // Clean up memory
    free_neural_network(nn);
    free_weights(weights);

    return 0;
}
