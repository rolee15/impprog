#include <stdlib.h>
#include <string.h>
#include "error.h"

void str_create(char **str, const char *val, size_t n)
{
    *str = (char *)malloc(n);
    if (!(*str))
        die("create_string())");
    strncpy(*str, val, n);
}
