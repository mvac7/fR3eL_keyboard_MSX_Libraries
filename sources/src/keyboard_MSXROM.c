/* =============================================================================
   SDCC Keyboard MSX ROM Functions Library
   Version: 1.0 (7 March 2016)
   Author: mvac7
   Architecture: MSX
   Programming language: C
   Format: C object (SDCC .rel) 
   mail: mvac7303b@gmail.com

   Description:
     Functions for reading the keyboard of MSX computers.
============================================================================= */
#include "../include/keyboard.h"
#include "../include/msxBIOS.h"



/* =============================================================================
   KillBuffer
 
   Function : Clear keyboard buffer
   Input    : -
   Output   : -
============================================================================= */
void KillBuffer() __naked
{
__asm   
  
  call KILBUF
  ret
   
__endasm;
}



/* =============================================================================
   INKEY
  
   Function : One character input (waiting) and return its code
   Input    : -
   Output   : [char] key code
============================================================================= */
char INKEY() __naked
{
__asm   
  
   call CHGET   
   ld   L,A   
   ret
   
__endasm;
}



/* =============================================================================
   GetKeyMatrix

   Function : Returns the value of the specified line from the keyboard matrix.
              Each line provides the status of 8 keys.
              To know which keys correspond, you will need documentation that 
              includes a keyboard table.
   Input    : [char] line 
   Output   : [char] state of the keys. 1 = not pressed; 0 = pressed
============================================================================= */
char GetKeyMatrix(char line) __naked
{
line;
__asm
  push IX
  ld   IX,#0
  add  IX,SP
     
  ld   A,4(IX)
  
  call SNSMAT
  
  ld   L,A
  
  pop  IX
  ret
__endasm;
}