#include <stdio.h>
#include "phonebook.h"

#define PHONEBOOK_SIZE 1024

int main(void)
{
    phonebook_t pb = pb_create(PHONEBOOK_SIZE);
    pb_add(&pb, "John Doe", "+15551234567");
    pb_add(&pb, "Jane Doe", "+15552345678");

    puts("Phonebook:");
    pb_print(&pb);

    char *number, *name;

    name = "John Doe";
    number = pb_lookup(&pb, name);
    if (number)
        printf("Number of %s found: %s\n", name, number);
    else
        printf("Number of %s not found.\n", name);

    name = "John Smith";
    number = pb_lookup(&pb, name);
    if (number)
        printf("Number of %s found: %s\n", name, number);
    else
        printf("Number of %s not found.\n", name);

    pb_free(&pb);

    return 0;
}
