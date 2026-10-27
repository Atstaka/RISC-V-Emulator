#include "riscv.h"
#include <stdlib.h>
int main(int argc, char *argv[]){
	//create cpu and provide memory 
	cpu *cpu = malloc(sizeof(*cpu));
	printf("cpu created \n");
	initializeCpu(cpu);
	printf("initalized cpu \n");
	bool isLoaded = load_bin(cpu->bus.dram.memory, argv[1]);
	cpu_loop(cpu);
	printf("x1: %lb \n, x2 = %lb \n, x3= %lb \n, x4 %lb \n ",cpu->regist[1],cpu->regist[2], cpu->regist[3],
			cpu->regist[4]);

	
	free(cpu);
	return 0;
}
