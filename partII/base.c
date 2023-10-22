#include <stdio.h>
#include "nn_base.h"

// Function to run a single test and return 1 for passed, 0 for failed
int run_test(int test_number, const char *test_description)
{
    NeuralNetwork_t *nn = create_neural_network(2, 3, 1);
    Weight_t *weights = create_weights(nn->I * nn->H + nn->H * nn->O);

    int test_passed = 1;

    switch (test_number)
    {
    case 1: // Save weights to a file
        for (int i = 0; i < nn->I * nn->H + nn->H * nn->O; i++)
        {
            weights[i].from_layer = 0;
            weights[i].from_unit = 0;
            weights[i].to_layer = 0;
            weights[i].to_unit = 0;
            weights[i].weight = 1.0;
        }

        if (save_weights(nn, weights, "test_weights_saved.txt") != 0)
        {
            test_passed = 0;
        }
        break;
    case 2: // Load weights from the saved file
        Weight_t *loaded_weights;
        if (load_weights(nn, &loaded_weights, "test_weights.txt") != 0)
        {
            test_passed = 0;
        }
        free_weights(loaded_weights);
        break;
    case 3: // Verify that the loaded weights match the initially saved weights
        Weight_t *loaded_weights_verify;
        if (load_weights(nn, &loaded_weights_verify, "test_weights.txt") != 0)
        {
            int num_weights = nn->I * nn->H + nn->H * nn->O;
            for (int i = 0; i < num_weights; i++)
            {
                if (weights[i].weight != loaded_weights_verify[i].weight)
                {
                    test_passed = 0;
                    break;
                }
            }
            free_weights(loaded_weights_verify);
        }
        else
        {
            test_passed = 0;
        }
        break;
    }

    if (test_passed)
    {
        printf("Test %d: %s - Passed\n", test_number, test_description);
    }
    else
    {
        printf("Test %d: %s - Failed\n", test_number, test_description);
    }

    return test_passed;

    free_neural_network(nn);
    free_weights(weights);
}

int main()
{
    // Create a neural network with 2 input units, 3 hidden units, and 1 output unit
    NeuralNetwork_t *nn = create_neural_network(2, 3, 1);

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
    printf("Output: %.4lf\n", output[0]);

    // Save the weights back to a file
    if (save_weights(nn, weights, "saved_weights.txt") != 0)
    {
        return 1;
    }

    // Run tests
    int num_passed = 0;
    int num_failed = 0;

    // Run the tests
    num_passed += run_test(1, "Save weights to a file");
    num_passed += run_test(2, "Load weights from the saved file");
    num_passed += run_test(3, "Verify that the loaded weights match the initially saved weights");

    num_failed = 3 - num_passed;

    printf("Tests passed: %d\n", num_passed);
    printf("Tests failed: %d\n", num_failed);

    return num_failed;

    // Clean up memory
    free_neural_network(nn);
    free_weights(weights);

    return 0;
}
