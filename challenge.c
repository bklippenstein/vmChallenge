# include "memory.h"
# include "stdio.h"
# include "stdlib.h"
# include "challenge.h"

short r[8];
//extern short stack[32768];
extern short memory[32768];
short* sp;
short pc;

int main (int argc, char *argv[])
{
    printf("Beginning execution of VM\n\n"); 
    
    //extern short stack[32768];
//    extern short* sp;
//    short a[3];
//    short opcode;
//    sp = &stack[0];
    FILE* pFile;
    pFile = fopen(argv[1], "rb");   
    readBinary(pFile);
    
    /*while(1)
    {
        readInstruction(pFile, &opcode, &a[0], &a[1], &a[2]);
        executeInstruction(&opcode, &a[0], &a[1], &a[2]);
    }*/
    
    return(0);
}

/*void readInstruction(FILE* pFile, short* opcode, short* a1, short* a2, short* a3)
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
    
    if( code > 32776 )
    {
        fprintf(stderr, "Invalid value read from binary. Program terminated.");
        fclose(pFile);
    }
   
    return code;
}

int executeInstruction(short* opcode, short* a1, short* a2, short* a3)
{
    short temp[3];
    extern short stack[32768];
    extern short* sp;
    extern short r[8];
    printf("Opcode: %hd\n", *opcode);
    switch( *opcode )
    {
        case 0: // Halt execution
            printf("Program execution finished, terminating program.\n");
            exit(1);
            break;
            
        case 1:  // set register
            if (*a1 < 32768) // 'a' isn't a register
            {
                fprintf(stderr, "argument 'a' with op code 1 is not a register");
                exit(-1);
            }
            if (*a2 < 32768) // 'b' is a literal
            {
                r[*a1 % 32768] = *a2; // set register r[*a1] to contain *a2
            }
            else if (*a2 > 32767) // 'b' is a register
            {
                r[*a1 % 32768] = r[*a2 % 32768]; // set register r[*a1] to contain r[*a2]
            }
            break;
            
        case 2: // push value to stack at sp, incriment sp.
            if(*a1 < 32768) // if the argument is a literal
            {
                *sp = *a1; // Push the value to the stack.
                sp++; // Incremet the stack pointer
            }
            else if(*a1 > 32767) // if the argument is a register.
            {
                *sp = r[*a1 % 32768]; // Push the value to the stack.
                sp++; // Incremet the stack pointer
            }
            break;
            
        case 3: // Pop value from stack
            if (sp == &stack[0]) // If there isn't anything on the stack
            {
                fprintf(stderr, "Error: stack is empty, can't pop.\n");
                fprintf(stderr, "Terminating program.\n");
                exit(-1);
            }
            else if(*a1 > 32767) // if the argument is a register.
            {
                sp--; // Decrincremet the stack pointer
                r[*a1 % 32768] = *sp; // Pop the value from the stack to register r[*a1]
            }
            break;
            
        case 4: // eq, set r[*a1] to 1 if *a2 is equal to *a3, 0 otherwise/
            if(*a2 > 32767) // a2 is a register, so we need to take the value stored in that register.
            {
                temp[0] = r[*a2 % 32767];
            }
            else if(*a2 < 32768) //a2 is a literal.
            {
                temp[0] = *a2;
            }
                
            if(*a3 > 32767) // a2 is a register, so we need to take the value stored in that register.
            {
                temp[1] = r[*a3 % 32767];
            }
            else if(*a3 < 32768) //a2 is a literal.
            {
                temp[1] = *a3;
            }
            
            *a1 = (temp[0] == temp[1]); //store the result of b==c in <a>
            break;
    }
    return(1);
}




*/
