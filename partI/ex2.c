#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    Implement a C program, print_bits, that reads an integer, i, from the keyboard and prints i in
    binary format, from the most to the least significant bit.
*/

void print_bits(int num)
{

    int bit, i;

    for (i = 15; i >= 0; i--) {
        bit = (num >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
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
    int i;
    char input[100];

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
            printf("Invalid input. Please enter a valid integer: ");
            continue;
        }

        i = atoi(input); // Convert the input string to an integer

        break;
    }
    puts("The binary representation of the integer is: ");
    print_bits(i);

    return 0;
}