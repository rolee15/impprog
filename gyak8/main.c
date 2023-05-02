#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* copy(char* str)
{
    int size = strlen(str);
    char* other = (char*)malloc((size + 1) * sizeof(char));

    for (int i = 0; i < size; ++i)
    {
        other[i] = str[i];
    }

    other[size] = '\0';
    return other;
}

char* reverse(char* str)
{
    int size = strlen(str);
    char* other = (char*)malloc((size + 1) * sizeof(char));

    for (int i = 0; i < size; ++i)
    {
        other[i] = str[size - i - 1];
    }

    other[size] = '\0';
    return other;
}


int main()
{
    int BUFFER = 20;
    char str[BUFFER];

    fgets(str, BUFFER, stdin);
    char* p1 = copy(str);
    char* p2 = reverse(str);
    printf("%s\n", p1);
    printf("%s\n", p2);

    free(p1);      // gcc main.c -fsanitizer=leak futás közben kiírja
    free(p2);

    return 0;
}