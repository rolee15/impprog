// **********************************************************************
// *                                                                    *
// *    countlc - print lower case letters count in a FILE              *
// *                                                                    *
// *    Params                                                          *
// *      FILE      File that contains the text.                        *
// *                By default, it looks for a file named input.txt     *
// *                                                                    *
// *    Example usage:                                                  *
// *      countlc hello.txt                                             *
// *                                                                    *
// *    Output:                                                         *
// *      d: 1                                                          *
// *      e: 1                                                          *
// *      h: 1                                                          *
// *      l: 3                                                          *
// *      o: 2                                                          *
// *      r: 1                                                          *
// *      w: 1                                                          *
// *                                                                    *
// **********************************************************************

#include <stdio.h>
#include <stdlib.h>

static const size_t LETTERS_COUNT = 26;
static const size_t BUFF_SIZE = 256;

void increment(int *letters, char l)
{
    size_t idx = l - 'a';
    letters[idx]++;
}

void count_lc_letters(int *letters, char *str)
{
    size_t i = 0;

    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            increment(letters, str[i]);
        }
        i++;
    }
}

int main(int argc, char *argv[])
{
    char *filename = "input.txt";
    if (argc != 1)
    {
        filename = argv[1];
    }

    int letters[LETTERS_COUNT];
    for (size_t i = 0; i < LETTERS_COUNT; ++i)
    {
        letters[i] = 0;
    }

    FILE *f_in = fopen(filename, "r");
    if (f_in == NULL)
    {
        perror("fopen()");
        return EXIT_FAILURE;
    }

    char buf[BUFF_SIZE];
    while (fgets(buf, BUFF_SIZE, f_in) != NULL)
    {
        count_lc_letters(letters, buf);
    }

    for (size_t i = 0; i < LETTERS_COUNT; ++i)
    {
        if (letters[i] != 0)
        {
            printf("%c: %d\n", (char)('a' + i), letters[i]);
        }
    }

    fclose(f_in);

    return 0;
}