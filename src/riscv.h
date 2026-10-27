#ifndef RISCV_H
#define RISCV_H
#include "memory.h"

typedef struct {
	uint64_t regist[32];
	uint64_t pc;
	Bus bus;


}cpu;


//initializes cpu by setting memory, pc etc.
void initializeCpu(cpu *cpu);

//fetches next instruction
uint32_t fetch(cpu *cpu);
//executes fetched instruction
void execute(cpu *cpu, uint32_t inst);

void cpu_loop(cpu *cpu);

#endif
