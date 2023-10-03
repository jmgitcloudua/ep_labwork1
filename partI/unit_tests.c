#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void print_bits(int num)
{
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--)
    {
        int bit = (num >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}

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

static bool test_print_bits(int num, const char *expected_output)
{
    if (num < 0)
    {
        printf("Test failed: Input must be a non-negative integer.\n");
        return false;
    }

    char output[sizeof(int) * 8 + 1]; // +1 for the null terminator
    sprintf(output, "%d", num);

    if (strcmp(output, expected_output) != 0)
    {
        printf("Test failed: Expected output '%s', got '%s'\n", expected_output, output);
        return false;
    }

    return true;
}

static bool test_bits_to_int(const char *bits, int expected_result)
{
    for (int i = 0; bits[i] != '\0'; i++)
    {
        if (bits[i] != '0' && bits[i] != '1')
        {
            printf("Test failed: Input must contain only '0' and '1' characters.\n");
            return false;
        }
    }

    int result = bits_to_int(bits);

    if (result != expected_result)
    {
        printf("Test failed: Expected result %d, got %d\n", expected_result, result);
        return false;
    }

    return true;
}

int main(void)
{
    bool all_tests_passed = true;

    // Test printing the bits of a non-negative integer
    all_tests_passed &= test_print_bits(10, "1010");
    all_tests_passed &= test_print_bits(0, "0");
    all_tests_passed &= test_print_bits(1, "1");
    all_tests_passed &= test_print_bits(2, "10");
    all_tests_passed &= test_print_bits(-3, "-3"); // must be non-negative

    // Test converting a binary string to an integer with valid inputs
    all_tests_passed &= test_bits_to_int("1010", 10);
    all_tests_passed &= test_bits_to_int("1101", 13);
    all_tests_passed &= test_bits_to_int("0", 0);
    all_tests_passed &= test_bits_to_int("1", 1);

    // Test converting a binary string to an integer with invalid inputs
    all_tests_passed &= !test_bits_to_int("-1010", -1); // Negative sign should be rejected
    all_tests_passed &= !test_bits_to_int("Invalid", -1); // Contains invalid characters
    all_tests_passed &= !test_bits_to_int("11111", 32); // Contains invalid characters
    all_tests_passed &= !test_bits_to_int("1", 0); // Should not return 0 for valid input
    all_tests_passed &= !test_bits_to_int("R", 1); // Should not return 1 for valid input

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

