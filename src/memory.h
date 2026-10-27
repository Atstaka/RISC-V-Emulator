#ifndef MEMORY_H
#define MEMORY_H
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include<stdio.h>

#define MEM_SIZE (1024 * 1024 * 128)
#define DRAM_BASE 0x80000000
typedef struct{

	uint8_t memory[MEM_SIZE];

}Dram;
typedef struct{
	Dram dram;
}Bus;



bool load_bin(uint8_t *mem,const char *filen);

//Dram methods
//
uint64_t load_memory(Dram *dram, uint64_t addr, uint64_t size);
void save_memory(Dram *dram, uint64_t addr, uint64_t size, uint64_t value);
//Bus methods
//

uint64_t load_bus(Bus *bus,uint64_t addr, uint64_t size);
void save_bus(Bus *bus, uint64_t addr, uint64_t size, uint64_t value);






#endif
