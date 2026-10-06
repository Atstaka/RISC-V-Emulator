#include "memory.h"
bool load_bin(const uint8_t *mem, const char *filen){

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
	return 0;


}

