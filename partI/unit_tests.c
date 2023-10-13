#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int bits_to_int(const char *bits)
{
    int num = 0;

    for (int i = 0; bits[i] != '\0'; i++)
    {
        if (bits[i] == '0' || bits[i] == '1')
        {
            num = (num << 1) | (bits[i] - '0');
        }
        else
        {
            printf("Invalid bit string. It should only contain '0' and '1' characters.\n");
            return -1;
        }
    }

    return num;
}

static bool test_print_bits(int num, const char *expected_output, const char *test_description)
{
    if (num < 0)
    {
        printf("Test %s - Failed: Input must be a non-negative integer.\n", test_description);
        return false;
    }

    char output[sizeof(int) * 8 + 1]; // +1 for the null terminator
    sprintf(output, "%d", num);

    if (strcmp(output, expected_output) != 0)
    {
        printf("Test %s - Failed: Expected output '%s', got '%s'\n", test_description, expected_output, output);
        return false;
    }

    printf("Test %s - Passed\n", test_description);
    return true;
}

static bool test_bits_to_int(const char *bits, int expected_result, const char *test_description)
{
    for (int i = 0; bits[i] != '\0'; i++)
    {
        if (bits[i] != '0' && bits[i] != '1')
        {
            printf("Test %s - Failed: Input must contain only '0' and '1' characters.\n", test_description);
            return false;
        }
    }

    int result = bits_to_int(bits);

    if (result != expected_result)
    {
        printf("Test %s - Failed: Expected result %d, got %d\n", test_description, expected_result, result);
        return false;
    }

    printf("Test %s - Passed\n", test_description);
    return true;
}

int main(void)
{
    bool all_tests_passed = true;

    // Test printing the bits of a non-negative integer
    all_tests_passed &= test_print_bits(1010, "1010", "Printing 10 in bits");
    all_tests_passed &= test_print_bits(0, "0", "Printing 0 in bits");
    all_tests_passed &= test_print_bits(1, "1", "Printing 1 in bits");
    all_tests_passed &= test_print_bits(111, "1111", "Printing 15 in bits");
    all_tests_passed &= test_print_bits(-3, "-3", "Printing -3 in bits"); // must be non-negative

    // Test converting a binary string to an integer with valid inputs
    all_tests_passed &= test_bits_to_int("1010", 10, "Converting '1010' to int");
    all_tests_passed &= test_bits_to_int("1101", 13, "Converting '1101' to int");
    all_tests_passed &= test_bits_to_int("0", 0, "Converting '0' to int");
    all_tests_passed &= test_bits_to_int("1", 1, "Converting '1' to int");
    all_tests_passed &= test_bits_to_int("1111", 14, "Converting '1111' to int");

    // Test converting a binary string to an integer with invalid inputs
    all_tests_passed &= !test_bits_to_int("-1010", -1, "Converting '-1010' to int");     // Negative sign should be rejected
    all_tests_passed &= !test_bits_to_int("Invalid", -1, "Converting 'Invalid' to int"); // Contains invalid characters
    all_tests_passed &= !test_bits_to_int("11111", 32, "Converting '11111' to int");     // Contains invalid characters
    all_tests_passed &= !test_bits_to_int("1", 0, "Converting '1' to int");              // Should not return 0 for valid input
    all_tests_passed &= !test_bits_to_int("R", 1, "Converting 'R' to int");              // Should not return 1 for valid input

    if (all_tests_passed)
    {
        printf("All tests passed!\n");
    }
    else
    {
        printf("One or more tests failed.\n");
        return 1;
    }

    return 0;
}
