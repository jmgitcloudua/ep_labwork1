#include <stdio.h>
#include <assert.h>
#include "nn_base.c"

int tests_passed = 0;
int tests_failed = 0;

void test_create_and_free_neural_network()
{
    NeuralNetwork_t *nn = create_neural_network(2, 3, 1);
    assert(nn != NULL);
    assert(nn->I == 2);
    assert(nn->H == 3);
    assert(nn->O == 1);
    free_neural_network(nn);
    tests_passed++;
}

void test_create_and_free_weights()
{
    Weight_t *weights = create_weights(10);
    assert(weights != NULL);
    free_weights(weights);
    tests_passed++;
}

void test_load_and_save_weights()
{
    // Create a neural network
    NeuralNetwork_t *nn = create_neural_network(2, 2, 1);

    // Create some example weights
    Weight_t example_weights[6] = {
        {0, 0, 1, 0, 0.5},
        {0, 1, 1, 0, 0.6},
        {0, 0, 1, 1, 0.7},
        {0, 1, 1, 1, 0.8},
        {1, 0, 2, 0, 0.9},
        {1, 1, 2, 0, 1.0}};

    // Save weights to a file
    assert(save_weights(nn, example_weights, "test_weights_saved.txt") == 0);

    // Load weights from the file
    Weight_t *loaded_weights = NULL;
    assert(load_weights(nn, &loaded_weights, "test_weights.txt") == 0);

    // Verify that the loaded weights match the example weights
    for (int i = 0; i < 6; i++)
    {
        assert(loaded_weights[i].from_layer == example_weights[i].from_layer);
        assert(loaded_weights[i].from_unit == example_weights[i].from_unit);
        assert(loaded_weights[i].to_layer == example_weights[i].to_layer);
        assert(loaded_weights[i].to_unit == example_weights[i].to_unit);
        assert(loaded_weights[i].weight == example_weights[i].weight);
    }

    free_weights(loaded_weights);
    free_neural_network(nn);
    tests_passed++;
}

void test_propagate_input()
{
    // Create a neural network
    NeuralNetwork_t *nn = create_neural_network(2, 2, 1);

    // // Create example weights
    Weight_t example_weights[6] = {
        {0, 0, 1, 0, 0.5},
        {0, 1, 1, 0, 0.6},
        {0, 0, 1, 1, 0.7},
        {0, 1, 1, 1, 0.8},
        {1, 0, 2, 0, 0.9},
        {1, 1, 2, 0, 1.0}};
    // Save weights to a file
    assert(save_weights(nn, example_weights, "test_weights_saved.txt") == 0);

    // Load the example weights
    Weight_t *loaded_weights = NULL;
    assert(load_weights(nn, &loaded_weights, "test_weights.txt") == 0);

    // Test the propagation of input
    double input[2] = {0.2, 0.3};
    double output[1] = {0.0}; // Initialize the output
    propagate_input(nn, loaded_weights, input, output);
    assert(output[0] > 0.0); // The output should not be zero

    free_weights(loaded_weights);
    free_neural_network(nn);
    tests_passed++;
}

int main()
{
    test_create_and_free_neural_network();
    test_create_and_free_weights();
    test_load_and_save_weights();
    test_propagate_input();

    printf("Tests Passed: %d\n", tests_passed);
    printf("Tests Failed: %d\n", 4 - tests_passed);

    if (tests_failed > 0)
    {
        printf("Some tests failed.\n");
    }
    else
    {
        printf("All tests passed.\n");
    }

    return 0;
}
