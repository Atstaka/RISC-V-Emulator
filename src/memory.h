#ifndef MEMORY_H
#define MEMORY_H
#include <stddef.h>
#include <stdint.h>
#include<stdio.h>

#define MEM_SIZE (1024 * 1024 * 128)
#define DRAM_SIZE (0x80000000)

typedef struct{
	memory[MEM_SIZE];
	uint8_t dram

}Dram;
typedef struct{
	Dram dram;
}Bus;



bool load_bin(uint8_t *mem,const char *filen);

//Dram methods
//
uint64_t load_memory(Dram *dram, uint64_t addr, uint64_t size);
uint64_t save_memory(Dram *dram, uint64_t addr, uint64_t size, uint64_t value);
//Bus methods
//

uint64_t load_bus(Bus *bus,uint64_t addr, uint64_t size);
void load_bus(Bus *bus, uint64_t addr, uint64_t size, uint64_t value);






#endif
