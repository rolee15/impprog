#include <stdlib.h>
#include "entry.h"

typedef struct Phonebook
{
    entry_t *entries;
    size_t size;
    size_t max_size;
} phonebook_t;

phonebook_t pb_create(size_t max_size);

void pb_add(phonebook_t *pb, const char *name, const char *number);

char *pb_lookup(phonebook_t *pb, const char *name);

void pb_print(phonebook_t *pb);

void pb_free(phonebook_t *pb);
