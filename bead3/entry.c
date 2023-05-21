#include <stdio.h>
#include "entry.h"
#include "utils.h"

entry_t pbe_create(const char *name, const char *number)
{
    entry_t entry;
    size_t len;

    len = strlen(name) + 1;
    str_create(&entry.name, name, len);
    len = strlen(number) + 1;
    str_create(&entry.number, number, len);

    return entry;
}

void pbe_print(entry_t *entry)
{
    printf("%s, %s\n", entry->name, entry->number);
}

void pbe_free(entry_t *entry)
{
    free(entry->name);
    free(entry->number);
}
