#include <stdio.h>
#include <string.h> // Include string.h for strlen function
#include <stdlib.h> // Include stdlib.h for atoi function
#include <stdbool.h> // Include stdbool.h for bool type

/*
    Implement a C program, bits_to_int, that reads a string of binary digits (i.e., composed of
    zeros and ones) and prints the corresponding integer in decimal format.
*/

int bits_to_int(char *bits)
{
    int i, num = 0;

    // Loop through each bit from the most significant to least significant
    for (i = 0; i < (char)strlen(bits); i++)
    {
        // If the current bit is 1, add 2^i to the integer
        if (bits[i] == '1')
        {
            num += 1 << (strlen(bits) - i - 1);
        }
    }

    return num;
}

int main(void)
{
    char input[100];

    printf("Enter a string of binary digits: ");

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

        bool valid = true;
        for (int i = 0; i < (char)strlen(input); i++)
        {
            if (input[i] != '0' && input[i] != '1')
            {
                printf("Error: Input contains non-binary digits. Please enter only 0s and 1s.\n");
                valid = false;
                break;
            }
        }

        if (valid)
        {
            printf("The integer is: %d\n", bits_to_int(input));
            break; // Break out of the loop when valid input is provided
        }

        printf("Enter a string of binary digits: "); // Prompt for input again
    }

    return 0;
}