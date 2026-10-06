#include "riscv.h"

int main(int argc, char *argv[]){
	cpu *cpu;
	initializeCpu(cpu);
	bool isLoaded = load_bin(cpu->memory, argv[1]);
	

	

	return 0;
}
