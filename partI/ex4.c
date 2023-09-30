#include <stdio.h>
#include <string.h> // Include string.h for strlen function
#include <stdlib.h> // Include stdlib.h for atoi function
#include <stdbool.h> // Include stdbool.h for bool type

/*
    Join print_bits and bits_to_int into a single program, bits. In this case, the needed
    inputs must be passed as command-line arguments.
*/

void print_bits(int num)
{
    int bit, i;

    // Print the 16 least significant bits
    for (i = 15; i >= 0; i--)
    {
        bit = (num >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}

int bits_to_int(const char *bits)
{
    int i, num = 0;

    // Loop through each character in the string
    for (i = 0; bits[i] != '\0'; i++)
    {
        // If the current character is not '0' or '1', return an error value (-1)
        if (bits[i] != '0' && bits[i] != '1')
        {
            return -1;
        }

        // If the current character is '1', add 2^(length - i - 1) to the integer
        if (bits[i] == '1')
        {
            num += 1 << (strlen(bits) - i - 1);
        }
    }

    return num;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <pb/bti> <integer/binary>\n", argv[0]);
        puts("Memo: pb for print_bits, bti for bits_to_int");
        return 1;
    }

    if (strcmp(argv[1], "pb") == 0)
    {
        // Check if the second argument is a valid positive integer
        int num = atoi(argv[2]);
        if (num <= 0 || argv[2][0] == '-') // Check if it's not positive or contains a negative sign
        {
            printf("Invalid positive integer for print_bits.\n");
            return 1;
        }
        print_bits(num);
    }
    else if (strcmp(argv[1], "bti") == 0)
    {
        // Check if the second argument is a valid binary string
        int result = bits_to_int(argv[2]);
        if (result == -1)
        {
            printf("Invalid binary string for bits_to_int.\n");
            return 1;
        }
        printf("%d\n", result);
    }
    else
    {
        printf("Invalid command. Use either 'pb' or 'bti'.\n");
    }

    return 0;
}
