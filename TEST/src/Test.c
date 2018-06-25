/* =============================================================================
   SDCC Keyboard MSXROM Lib Test 1 (INKEY)
   Version: 1.1
   Date: 24 June 2018
   Author: mvac7/303bcn
   Architecture: MSX
   Format: C Object (SDCC .rel)
   Programming language: C
   WEB: 
   mail: mvac7303b@gmail.com

   Description:
     Test the INKEY function of MSXROM Keyboard library.
     
   History of versions:
     - v1.1 (24/06/2018)<
     - v1.0 (29/01/2016)
     
============================================================================= */

#include "../include/newTypes.h"
#include "../include/msxsystemvars.h"
#include "../include/msxBIOS.h"

#include "../include/keyboard.h"
#include "../include/textmode.h"




// Function Declarations -------------------------------------------------------
void test();

//void INPUT(char* string);

//char strlen(char* text);




// constants  ------------------------------------------------------------------
const char text01[] = "Test SDCC Keyboard MSXROM Lib";
const char text02[] = "v1.1 (24/06/2018)";


// global variable definition --------------------------------------------------



// Functions -------------------------------------------------------------------


//
void main(void)
{
  COLOR(LIGHT_GREEN,DARK_GREEN,DARK_GREEN);
  WIDTH(40);      
  SCREEN0();  
    
  test();
  
}



void test()
{
  char bytevalue;
  //char string[32];
  
  LOCATE(0,0);
  PRINT(text01);
  LOCATE(0,1);
  PRINT(text02);
  
  LOCATE(0,4);
  PRINT("Test INKEY");
  
  LOCATE(1,7);
  PRINT("Press a key:");
  
  
  while(1)
  {
    LOCATE(13,7);
    bytevalue = INKEY();    
    LOCATE(14,7);
    PrintFNumber(bytevalue,' ',3);  
  }
  
  
/*  PRINT("\n\n>Test INPUT\nType a text and press RETURN (32max):\n");
  INPUT(string); 

  PRINT("\nINPUT Result>");
  PRINT(string);
  PRINT("<");
  
  PRINT("\n\nPress a key to exit");
  INKEY();
*/
  
}




/*
void INPUT(char* string)
{
  //char length = 32;
  byte aKey=0;
  byte size=0;
  
  KillBuffer();
  
  while(1)
  {
    aKey = INKEY();
    if (aKey==13) break;
  
    if (aKey==8 && size>0)//BS
    {
      size--;
      bchput(127); //del
      string[size]=32; 
    }

    if(aKey>31 && aKey<123 && size<32) //length
    {
      //if (aKey>96) aKey-=32; //uppercase
      string[size]=aKey;
      bchput(aKey);
      size++;
    }  
  }
  string[size]=0; //END mark \0
}
*/



/*char strlen(char* text)
{
  byte i = 0;
  while(*(text++)) i++;
  return i;
}*/
