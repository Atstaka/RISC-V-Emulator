#include "riscv.h"
#include <stdlib.h>
int main(int argc, char *argv[]){
	//create cpu and provide memory 
	cpu *cpu = malloc(sizeof(*cpu));
	printf("cpu created \n");
	initializeCpu(cpu);
	printf("initalized cpu \n");
	bool isLoaded = load_bin(cpu->memory, argv[1]);
	cpu_loop(cpu);

	
	free(cpu);
	return 0;
}
