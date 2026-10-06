#include "riscv.h"
#include <string.h>
#include <stdbool.h>

#include"arithutils.h"

void initializeCpu(cpu *cpu){
	memset(cpu,0, sizeof(*cpu));
	cpu->regist[2] = MEM_SIZE;
	cpu->pc = 0x00000000;
}

uint32_t fetch(cpu *cpu){
	uint32_t instr= (cpu->memory[cpu->pc]

            | ((cpu->memory[cpu->pc + 1]) << 8)
            | ((cpu->memory[cpu->pc + 2]) << 16)
            | ((cpu->memory[cpu->pc + 3]) << 24));
	printf ("instruction: 0x%8X /n", instr);
	return instr;
}

void execute(cpu *cpu, uint32_t instr){
	uint8_t opcode = instr & 0x7F;
	uint8_t rd = (instr >>7) & 0x1F;
	uint8_t rs1 = (instr >> 15) & 0x1F;
	uint8_t rs2 = (instr >> 20) & 0x1F;


	switch(opcode){
		case(0x13):{
				int32_t imm = ((int32_t)instr >>20);
				cpu->regist[rd] =wrapping_add(cpu->regist[rs1],imm);
				printf("this \n");
			   	break;
			   }
		case(0x33):{
				cpu->regist[rd] = wrapping_add(cpu->regist[rs1],cpu->regist[rs2]);
				break;
			   }

				

	}
}

void cpu_loop(cpu *cpu){
	bool loop = 1;
	while(loop){
		uint32_t instr =fetch(cpu);
		execute(cpu,instr);
		cpu->pc += 0x4;
	}

}





