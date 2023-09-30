#include <stdio.h>
#include <stdbool.h>
#include <ctype.h> // Include ctype.h for isdigit function
#include <string.h> // Include string.h for strlen function
#include <stdlib.h> // Include stdlib.h for atoi function

/*
    Implement a C program, print_bit, that reads an integer, i, from the keyboard and a bit position, p, and prints the corresponding 
    value of that bit in the binary representation of i. Note:
    consider that p = 0 corresponds to the position of the least significant bit.
*/
int print_bit(int i, int p)
{
    return (i >> p) & 1;
}

// Function to check if a string contains only digits
bool isInteger(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            return false;
        }
    }
    return true;
}

int main(void)
{
    int i, p;
    char input[100]; // Buffer for user input

    printf("Enter an integer: ");

    while (1)
    {
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("Error reading input.\n");
            return 1;
        }

        // Remove trailing newline if present
        if (input[strlen(input) - 1] == '\n')
        {
            input[strlen(input) - 1] = '\0';
        }

        if (!isInteger(input))
        {
            printf("Invalid input. Please enter an integer: ");
            continue;
        }

        i = atoi(input); // Convert the input string to an integer

        if (i < 0)
        {
            printf("The number cannot be negative. Enter a non-negative number: ");
        }
        else
        {
            break;
        }
    }

    printf("Enter a bit position: ");

    while (1)
    {
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("Error reading input.\n");
            return 1;
        }

        // Remove trailing newline if present
        if (input[strlen(input) - 1] == '\n')
        {
            input[strlen(input) - 1] = '\0';
        }

        if (!isInteger(input))
        {
            printf("Invalid input. Please enter a valid bit position: ");
            continue;
        }

        p = atoi(input); // Convert the input string to an integer

        if (p < 0)
        {
            printf("Bit position cannot be negative. Enter a non-negative bit position: ");
        }
        else
        {
            break;
        }
    }

    int bitValue = print_bit(i, p);
    printf("The bit at position %d of %d is %d\n", p, i, bitValue);

    return 0;
}







