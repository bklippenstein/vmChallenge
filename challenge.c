# include "stdio.h"
# include "challenge.h"


int main (int argc, char *argv[])
{
    short opcode;
    short a[3];
    short r[8];
    short stack[32768];
    short memory[32768];
    short* sp;
    short pc;
    FILE* pFile;
    
    pFile = fopen(argv[1], "rb");
    
    readInstruction(pFile, &opcode, &a[0], &a[1], &a[2]);
    
    printf("%hd %hd %hd %hd \n", opcode, a[0], a[1], a[2]);

    return(0);
}

void readInstruction(FILE* pFile, short* opcode, short* a1, short* a2, short* a3)
{
    *opcode = readNextCode(pFile);
    if ( *opcode == 0 ||
         *opcode == 18 ||
         *opcode == 21 ) // no arguments to opcode, so exit.
    {
        return;
    }
    
    else if ( *opcode == 2 ||
              *opcode == 3 ||
              *opcode == 6 ||
              *opcode == 17 ||
              *opcode == 19 ||
              *opcode == 20 ) // 1 argument for the opcode, read one and exit
    {
        *a1 = readNextCode(pFile);
        return;
    }
    
    else if ( *opcode == 1 ||
              *opcode == 7 ||
              *opcode == 8 ||
              *opcode == 14 ||
              *opcode == 15 ||
              *opcode == 26 ) // 2 argument for the opcode, read one and exit
    {
        *a1 = readNextCode(pFile);
        *a2 = readNextCode(pFile);        
        return;
    }
    
    else // if there isn't 0, 1, or 2 arguments, then there must be 3.
    {
        *a1 = readNextCode(pFile);
        *a2 = readNextCode(pFile);
        *a3 = readNextCode(pFile);                
        return;
    }
    
    return; // We should never get here though.
}

short readNextCode(FILE* pFile)
{
    short *pCode, code;
    
    pCode = &code;
    
    fread(pCode, 2, 1, pFile);
   
    return code;
}
