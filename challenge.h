// challenge.h
// header file for the Synacor Challenge virtual machine
// Bryce Klippenstein
// Apr. 19, 2013


void readInstruction(FILE* pFile, short* opcode, short* a1, short* a2, short* a3);
// Reads the entire next instruction, with arguments.
// Always pass three arguments, even if you don't expect all, or any of them back.
// When returning instructions that don't use all three arguments, the unused arguments 
// will be left in their previous state, so be careful not to use them.

short readNextCode(FILE* pFile);
// Function to return only the next 16  bits of the binary file.
// It is not yet known if we will ever need to seek to a particular line of the file.

int executeInstruction(short* opcode, short* a1, short* a2, short* a3);
// Fuction to execute the instruction passed.
// returns 1 for sucess, -1 for failure.
