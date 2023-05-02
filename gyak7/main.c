#include <stdio.h>

int main()
{
    FILE* f_in = fopen("main.c", "r");
    FILE* f_out = fopen("main2.c", "w");

    int BUFFER = 100;
    char str[BUFFER];

    while (fgets(str, BUFFER, f_in) != NULL)
        fprintf(f_out, "%s", str);

    fclose(f_in);
    fclose(f_out);

    return 0;
}