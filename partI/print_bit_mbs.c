#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/*--------------------------------------------------

Implement a C program, print_bit, that reads an integer, i, from the keyboard and a bit position, p, and prints the corresponding
value of that bit in the binary representation of i. Note:
consider that p = 0 corresponds to the position of the least significant bit.

Miguel Bento Simoes - 118200
Jodionísio Muachifi - 97147
Gustavo Reggio - 118485
EP
--------------------------------------------------
*/
/*bool isInteger(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            return false;
        }
    }
    return true;
}*/

bool isDigit(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit((unsigned char)str[i])) {
            return false;
        }
    }
    return true;
}

bool getIntegerInput(const char *prompt, int *value)
{
    char input[100];
    printf("%s", prompt);

    while (1)
    {
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("Error reading input.\n");
            return false;
        }

        if (input[strlen(input) - 1] == '\n')
        {
            input[strlen(input) - 1] = '\0';
        }

        if (input[0] == '-')
        {
            printf("Input cannot be negative. Enter a non-negative value: ");
            continue;
        }

        if (!isDigit(input))
        {
            printf("Invalid input. Please enter a valid integer: ");
            continue;
        }

        *value = atoi(input);
        return true;
    }
}

int print_bit(int i, int p)
{
    return (i >> p) & 1;
}

int main(void)
{
    int i, p;

    if (!getIntegerInput("Enter an integer: ", &i))
    {
        return 1;
    }

    if (!getIntegerInput("Enter a bit position: ", &p))
    {
        return 1;
    }

    int bitValue = print_bit(i, p);
    printf("The bit at position %d of %d is %d\n", p, i, bitValue);

    return 0;
}

