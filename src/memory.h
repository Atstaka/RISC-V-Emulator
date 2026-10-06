
#define MEMORY_H
#include <stddef.h>
#include <stdint.h>
#include<stdio.h>

#define MEM_SIZE 1024 * 1024 * 128




bool load_bin(const uint8_t *mem,const char *filen);
