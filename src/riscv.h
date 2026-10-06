#include "memory.h"

typedef struct {
	uint8_t memory[MEM_SIZE];
	uint64_t regist[32];
	uint64_t pc;


}cpu;


//initializes cpu by setting memory, pc etc.
void initializeCpu(cpu *cpu);

//fetches next instruction
uint32_t fetch(cpu *cpu);
//executes fetched instruction
void execute(cpu *cpu, uint32_t inst);

void cpu_loop(cpu *cpu);
