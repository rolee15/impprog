// Generate a text file with a hundred lines and 10 words each line, separated by spaces.
// Each word is between 5 an 20 characters long.
//
// By default, the lines will be written to a file called 'input.txt', but an output file
// can be given as the first parameter

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static char *rand_string(char *str, size_t size)
{
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (size)
    {
        --size;
        for (size_t n = 0; n < size; n++)
        {
            int key = rand() % (int)(sizeof charset - 1);
            str[n] = charset[key];
        }
        str[size] = '\0';
    }
    return str;
}

int main(int argc, char *argv[])
{
    srand(time(NULL));

    char *filename = "input.txt";
    if (argc != 1)
    {
        filename = argv[1];
    }

    FILE *f_out = fopen(filename, "w");
    if (f_out == NULL)
    {
        perror("fopen()");
        return EXIT_FAILURE;
    }

    const int lc = 100;
    const int wc = 10;
    for (size_t i = 0; i < lc; ++i)
    {
        for (size_t j = 0; j < wc; ++j)
        {
            size_t length = rand() % 16 + 5;
            char str[length];
            rand_string(str, length);
            fprintf(f_out, "%s", str);
            if (j < 9) fprintf(f_out, " ");
            if (j == 9) fprintf(f_out, "\n");
        }
    }

    fclose(f_out);

    return 0;
}