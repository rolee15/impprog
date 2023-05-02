#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int SIZE = 5;
    int BUFFER = 20;
    char* words[SIZE];

    for (int i = 0; i < SIZE; ++i)
    {
        words[i] = malloc(BUFFER * sizeof(char));
        scanf("%s", words[i]);
    }

    for (int i = SIZE - 1; i >= 0; --i)
    {
        printf("%s\n", words[i]);
        free(words[i]);
    }

    return 0;
}