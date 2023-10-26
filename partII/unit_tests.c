// #include <stdio.h>
// #include <assert.h>
// #include "nn_base.c"

// // Function to run a single test and return 1 for passed, 0 for failed
// int run_test(int test_number, const char *test_description)
// {
//     NeuralNetwork_t *nn = create_neural_network(2, 3, 1);
//     Weight_t *weights = create_weights(nn->I * nn->H + nn->H * nn->O);

//     int test_passed = 1;

//     switch (test_number)
//     {
//     case 1: // Save weights to a file successfully
//         for (int i = 0; i < nn->I * nn->H + nn->H * nn->O; i++)
//         {
//             weights[i].from_layer = 1;
//             weights[i].from_unit = 2;
//             weights[i].to_layer = 2;
//             weights[i].to_unit = 1;
//             weights[i].weight = 1.0;
//         }

//         assert(save_weights(nn, weights, "test_weights_saved.txt") == 0);
//         break;
//     case 2: // Load weights from the saved file successfully
//         Weight_t *loaded_weights;
//         assert(load_weights(nn, &loaded_weights, "test_weights_saved.txt") == 0);
//         free_weights(loaded_weights);
//         break;
//     case 3: // Verify that the loaded weights match the initially saved weights
//         Weight_t *loaded_weights_verify;
//         assert(load_weights(nn, &loaded_weights_verify, "test_weights_saved.txt") == 0);
//         int num_weights = nn->I * nn->H + nn->H * nn->O;
//         for (int i = 0; i < num_weights; i++)
//         {
//             assert(weights[i].weight == loaded_weights_verify[i].weight);
//         }
//         free_weights(loaded_weights_verify);
//         break;
//     case 4: // Propagate input through the network and compute the output correctly
//         // TODO: Add test
//         // break;
//     }

//     if (test_passed)
//     {
//         printf("Test %d: %s - Passed\n", test_number, test_description);
//     }
//     else
//     {
//         printf("Test %d: %s - Failed\n", test_number, test_description);
//     }

//     free_neural_network(nn);
//     free_weights(weights);

//     return test_passed;
// }

// int main()
// {
//     // Run tests
//     int num_passed = 0;
//     int num_failed = 0;

//     num_passed += run_test(1, "Save weights to a file successfully");
//     num_passed += run_test(2, "Load weights from the saved file successfully");
//     num_passed += run_test(3, "Verify that the loaded weights match the initially saved weights");

//     // TODO: Add test for propagating input through the network and computing the output

//     num_failed = 3 - num_passed;

//     printf("Tests passed: %d\n", num_passed);
//     printf("Tests failed: %d\n", num_failed);

//     return num_failed;
// }
// #include <stdio.h>
// #include <assert.h>
// #include "nn_base.c"

// void test_create_and_free_neural_network() {
//     NeuralNetwork_t *nn = create_neural_network(2, 3, 1);
//     assert(nn != NULL);
//     assert(nn->I == 2);
//     assert(nn->H == 3);
//     assert(nn->O == 1);
//     free_neural_network(nn);
// }

// void test_create_and_free_weights() {
//     Weight_t *weights = create_weights(10);
//     assert(weights != NULL);
//     free_weights(weights);
// }

// void test_load_and_save_weights() {
//     // Create a neural network
//     NeuralNetwork_t *nn = create_neural_network(2, 2, 1);

//     // Create some example weights
//     Weight_t example_weights[6] = {
//         {0, 0, 1, 0, 0.5},
//         {0, 1, 1, 0, 0.6},
//         {0, 0, 1, 1, 0.7},
//         {0, 1, 1, 1, 0.8},
//         {1, 0, 2, 0, 0.9},
//         {1, 1, 2, 0, 1.0}
//     };

//     // Save weights to a file
//     assert(save_weights(nn, example_weights, "test_weights_saved.txt") == 0);

//     // Load weights from the file
//     Weight_t *loaded_weights = NULL;
//     assert(load_weights(nn, &loaded_weights, "test_weights.txt") == 0);

//     // Verify that the loaded weights match the example weights
//     for (int i = 0; i < 6; i++) {
//         assert(loaded_weights[i].from_layer == example_weights[i].from_layer);
//         assert(loaded_weights[i].from_unit == example_weights[i].from_unit);
//         assert(loaded_weights[i].to_layer == example_weights[i].to_layer);
//         assert(loaded_weights[i].to_unit == example_weights[i].to_unit);
//         assert(loaded_weights[i].weight == example_weights[i].weight);
//     }

//     free_weights(loaded_weights);
//     free_neural_network(nn);
// }

// void test_propagate_input() {
//     // Create a neural network
//     NeuralNetwork_t *nn = create_neural_network(2, 2, 1);

//     // Create example weights
//     Weight_t example_weights[6] = {
//         {0, 0, 1, 0, 0.5},
//         {0, 1, 1, 0, 0.6},
//         {0, 0, 1, 1, 0.7},
//         {0, 1, 1, 1, 0.8},
//         {1, 0, 2, 0, 0.9},
//         {1, 1, 2, 0, 1.0}
//     };

//     // Load the example weights
//     Weight_t *loaded_weights = NULL;
//     assert(load_weights(nn, &loaded_weights, "test_weights.txt") == 0);

//     // Test the propagation of input
//     double input[2] = {0.2, 0.3};
//     double output[1] = {0.0};  // Initialize the output
//     propagate_input(nn, loaded_weights, input, output);
//     assert(output[0] > 0.0);  // The output should not be zero

//     free_weights(loaded_weights);
//     free_neural_network(nn);
// }

// int main() {
//     test_create_and_free_neural_network();
//     test_create_and_free_weights();
//     test_load_and_save_weights();
//     test_propagate_input();

//     printf("All tests passed.\n");
//     return 0;
// }

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
