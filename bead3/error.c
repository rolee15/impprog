#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "error.h"

void die(const char* msg)
 {
     perror(msg);
     exit(errno);
 }
