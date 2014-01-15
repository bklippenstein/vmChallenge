# include "memory.h"


short unsigned stack[32768];
short unsigned memory[32768];

void readBinary(FILE* pFile)
{
    //extern short stack[32768];
    extern unsigned short memory[32768];
    long binarySize = 0x7562;
    int i = 0;

    fread(&memory, 2, binarySize, pFile);
    
    for(i=0; i<binarySize; i++)
    {
        printf("%x: ", i); // print address of memory
        printf("%04x\n", memory[i]); // print memory contents
    }
    return;
}
