#include <stdio.h>
#include <string.h>  // Include string.h for strlen function
#include <stdlib.h>  // Include stdlib.h for atoi function
#include <stdbool.h> // Include stdbool.h for bool type

/*
    Combine print_bits and bits_to_int into a single program named bits.
*/

void bits(const char *cmd, const char *arg)
{
    if (strcmp(cmd, "pb") == 0)
    {
        // Check if the argument is a valid positive integer
        int num = atoi(arg);
        if (num <= 0 || arg[0] == '-') // Check if it's not positive or contains a negative sign
        {
            printf("Invalid positive integer for print_bits.\n");
        }
        else
        {
            // Print the bits
            int bit, i;
            for (i = 15; i >= 0; i--)
            {
                bit = (num >> i) & 1;
                printf("%d", bit);
            }
            printf("\n");
        }
    }
    else if (strcmp(cmd, "bti") == 0)
    {
        // Check if the argument is a valid binary string
        const char *bits = arg;
        int i, result = 0;

        // Loop through each character in the string
        for (i = 0; bits[i] != '\0'; i++)
        {
            // If the current character is not '0' or '1', return an error value (-1)
            if (bits[i] != '0' && bits[i] != '1')
            {
                printf("Invalid binary string for bits_to_int.\n");
                return;
            }

            // If the current character is '1', add 2^(length - i - 1) to the integer
            if (bits[i] == '1')
            {
                result += 1 << (strlen(bits) - i - 1);
            }
        }

        printf("%d\n", result);
    }
    else
    {
        printf("Invalid command. Use either 'pb' or 'bti'.\n");
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <pb/bti> <integer/binary>\n", argv[0]);
        puts("Memo: pb for print_bits, bti for bits_to_int");
        return 1;
    }

    bits(argv[1], argv[2]);

    return 0;
}
