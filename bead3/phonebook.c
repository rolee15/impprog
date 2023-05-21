#include <stdio.h>
#include <string.h>
#include "error.h"
#include "utils.h"
#include "phonebook.h"

phonebook_t pb_create(size_t max_size)
{
    phonebook_t pb;
    pb.entries = (entry_t *)malloc(sizeof(entry_t) * max_size);
    if (pb.entries == NULL)
        die("create_phonebook()");
    pb.size = 0;
    pb.max_size = max_size;

    return pb;
}

void pb_add(phonebook_t *pb, const char *name, const char *number)
{
    if (pb->size >= pb->max_size)
        return;
    entry_t entry = pbe_create(name, number);
    pb->entries[pb->size++] = entry;
}

char *pb_lookup(phonebook_t *pb, const char *name)
{
    for (int i = 0; i < pb->size; ++i)
        if (strcmp(pb->entries[i].name, name) == 0)
            return pb->entries[i].number;

    return NULL;
}

void pb_print(phonebook_t *pb)
{
    for (int i = 0; i < pb->size; ++i)
        pbe_print(&pb->entries[i]);
}

void pb_free(phonebook_t *pb)
{
    for (int i = 0; i < pb->size; ++i)
        pbe_free(&pb->entries[i]);
    free(pb->entries);
}
