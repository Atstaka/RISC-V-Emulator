#include "memory.h"
bool load_bin(uint8_t *mem, const char *filen){

	FILE *file = fopen(filen,"rb");
	if(file == NULL) {
		perror("File couldn't openned\n");
		return 1;
	}
	fseek(file,0,SEEK_END);
	long fileSize = ftell(file);
	fseek(file,0,SEEK_SET);

	if(fileSize> MEM_SIZE){
		perror("File too big\n");
		fclose(file);
		return 1;
	}
	fread(mem,1,fileSize,file);
	fclose(file);
	printf("load_bin executed \n");
	return 0;


}

//Dram methods
//
uint64_t load_memory(Dram *dram, uint64_t addr, uint64_t size){
		switch(size){
			case 8:	return load8(dram,addr);
				break;
			case 16: return load16(dram,addr);
				 break;
			case 32: return load32(dram,addr);
				 break;
			case 64: return load64(dram,addr);
				 break;
		}
}

void save_memory(Dram *dram, uint64_t addr, uint64_t size, uint64_t value){
	#TODO
}

//Bus methods
//

uint64_t load_bus(Bus *bus, uint64_t addr, uint64_t size){
	if(addr<)
	#TODO
}
void save_bus(Bus *bus, uint64_t addr, uint64_t size, uint64_t value){
	#TODO
}






//helper methods for loading to dram in sizes of 8/16/23 and 64
static inline uint64_t load8(Dram *dram,uint64_t addr){
	return (uint64_t)dram->memory[addr-DRAM_SIZE];
}
static uint64_t load16(Dram *dram,uint64_t addr){
	
	return load8(dram,addr) | (load8(dram,addr+1) << 8); 
}
static uint64_t load32(Dram *dram, uint64_t addr){
	return load16(dram,addr) | (load16(dram,addr+2)  << 16);
}

static uint64_t load64(Dram *dram,uint64_t addr){
	return load32(dram,addr) | (load32(dram,addr + 4) <<32);
}
//Helper methods to store to memory in different sizes fo 8,16,32 and 64 
static inline void save8(Dram *dram, uint64_t addr, uint64_t value){
	dram->memory[addr-DRAM_SIZE] = (uint8_t) value & 0xff;
}
static inline void save16(Dram *dram, uint64_t addr, uint64_t value){
	save8(dram,addr,value);
	save8(dram,addr+1,value>>8);
}
static inline void save32(Dram *dram, uint64_t addr, uint64_t value){
	save16(dram,addr,value);
	save16(dram,addr+2,value>>16);
}

static inline void save64(Dram *dram, uint64_t addr, uint64_t value){
	save32(dram,addr,value);
	save32(dram,addr+4,value>>32);

}


