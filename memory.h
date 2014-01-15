// memory.h
// defines the interface to read and write to the "RAM" for the Synacor Challenge virtual machine
// Bryce Klippenstein
// Jan. 14, 2014

# include "stdio.h"
# include "stdlib.h"

void readBinary(FILE* pFile);
// Read the entire binary into the "RAM" of the virtual machine.
