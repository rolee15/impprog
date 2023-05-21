#include <stdlib.h>
#include <string.h>

typedef struct Entry
{
    char *name;
    char *number;
} entry_t;

entry_t pbe_create(const char *name, const char *number);

void pbe_print(entry_t *entry);

void pbe_free(entry_t *entry);
