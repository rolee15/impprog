#include <stdio.h>

int cross_product(int* v1, int* v2, size_t size)
{
    int s = 0;

    for (int i = 0; i < size; ++i)
        s += v1[i] * v2[i];

    return s;
}

int num_lines(char str[])
{
    if (str[0] == '\0')
        return 0;

    int count = 1;

    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] == '\n')
            ++count;
    }

    return count;
}

int num_vowels(char str[])
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; ++i)
    {
        
    }
}

int num_consonants(char str[])
{

}


int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 1, 2, 20, 40};

    printf("Skalár: %d\n", cross_product(arr1, arr2, sizeof(arr1) / sizeof(int)));

    char str[] = "egy\n\
    kettő\
    három";

    printf("Sorok száma: %d\n", num_lines(str));

    return 0;

}