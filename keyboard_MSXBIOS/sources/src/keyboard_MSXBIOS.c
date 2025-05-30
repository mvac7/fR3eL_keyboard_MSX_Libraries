/* =============================================================================
# Keyboard MSX BIOS Library (fR3eL Project)

Version: 1.1 (30/11/2023)
Author: mvac7/303bcn
Architecture: MSX
Format: C object (SDCC .rel)
Programming language: C and Z80 assembler
Compiler: SDCC 4.4 or newer

## Description:
 Functions for reading the keyboard of MSX computers.
 
## History of versions:
- v1.1 (30/11/2023) update to SDCC (4.1.12) Z80 calling conventions
- v1.0 ( 7/ 3/2016)
============================================================================= */
#include "../include/keyboard_MSX.h"

#include "../include/msxBIOS.h"



/* =============================================================================
KillBuffer
Description: 
		Clear keyboard buffer
Input:	-
Output:	-
============================================================================= */
void KillBuffer(void) __naked
{
__asm
	jp BIOS_KILBUF
__endasm;
}



/* =============================================================================
INKEY
Description: 
		Waits for a key press and returns its value
Input:	-
Output:	[char] key code
============================================================================= */
char INKEY(void) __naked
{
__asm  
	jp BIOS_CHGET
__endasm;
}



/* =============================================================================
GetKeyMatrix
Description:
		Returns the value of the specified line from the keyboard matrix.
		Each line provides the status of 8 keys.
		To know which keys correspond, you will need documentation that 
		includes a keyboard table.
Input:	[char] row 
Output:	[char] state of the keys. 1 = not pressed; 0 = pressed
============================================================================= */
char GetKeyMatrix(char row) __naked
{
row;	// A
__asm  
	jp BIOS_SNSMAT
__endasm;
}
