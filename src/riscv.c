#include "riscv.h"
#include <string.h>
#include <stdbool.h>



//
//initializing the cpu at pc =0
//
void initializeCpu(cpu *cp){
	memset(cp,0, sizeof(*cp));
	printf("memset successful \n");
	cp->regist[2] = MEM_SIZE+ DRAM_BASE;
	cp->pc = DRAM_BASE;
}

//Fetches instructions
uint32_t fetch(cpu *cpu){
	uint32_t instr= load_bus(&cpu->bus,cpu->pc,32);
	printf ("instruction: %b\n", instr);
	printf("inst but hex 0x%08X\n", instr);
	return instr;
}
//
//decodes given instruction and executes it
//
void execute(cpu *cpu, uint32_t instr){
	uint8_t opcode = instr & 0x7F;
	printf("opcode: %b\n",opcode);
	uint8_t rd = (instr >>7) & 0x1F;
	uint8_t rs1 = (instr >> 15) & 0x1F;
	uint8_t rs2 = (instr >> 20) & 0x1F;
	printf("opcode : %02x,rd: %02x, rs1: %02x,rs2: %02x \n",opcode,rd,rs1,rs2);

	switch(opcode){
		//addi
		case(0x13):{
				printf("addi\n");
				int64_t imm =(int64_t) ((int32_t)instr >>20);
				cpu->regist[rd] =(cpu->regist[rs1] + (int64_t) imm);
				printf("this \n");
			   	break;
			   }
		case(0x33):{
				cpu->regist[rd] = (cpu->regist[rs1] +cpu->regist[rs2]);
				break;
			   }

				

	}
	cpu->regist[0] = 0;
}

//
//general cycle loop
//
void cpu_loop(cpu *cpu){
	printf("hey \n");
	while(true){
		uint32_t instr =fetch(cpu);
		// stops on file end
		if (instr == 0 || cpu->pc ==0) break;
		printf("fetched \n");
		execute(cpu,instr);
		cpu->pc += 0x4;
		printf("executed \n");
		printf("pc + 4 \n");

	}

}





