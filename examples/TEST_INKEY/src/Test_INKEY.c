/* =============================================================================
   SDCC Keyboard MSXROM Lib Test INKEY (fR3eL Project)
   Version: 1.2 (30/11/2023)
   Author: mvac7
   Architecture: MSX
   Format: C Object (SDCC .rel)
   Programming language: C
   Compiler: SDCC 4.1.12 or newer 
   mail: mvac7303b@gmail.com

   Description:
     Test the INKEY function of MSXROM Keyboard library.
     
   History of versions:
     - v1.2 (30/11/2023)< update to SDCC (4.3). For Keyboard MSXROM v1.1 library
     - v1.1 (24/ 6/2018)
     - v1.0 (29/ 1/2016)
     
============================================================================= */

#include "../include/newTypes.h"
#include "../include/msxSystemVariables.h"
#include "../include/msxBIOS.h"

#include "../include/keyboard_MSX.h"
#include "../include/textmode_MSX.h"




// Function Declarations -------------------------------------------------------
void test(void);




// constants  ------------------------------------------------------------------
const char text01[] = "Test Keyboard MSXROM Lib";
//const char text02[] = "v1.2 (30/11/2023)";


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



void test(void)
{
  char bytevalue;
  
  LOCATE(0,0);
  PRINT(text01);
//  LOCATE(0,1);
//  PRINT(text02);
  
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
	PRINT("         ");
	LOCATE(18,7);
	if(bytevalue==127) PRINT("[Del]");
	else if(bytevalue>31)
	{
       PRINT("[");
	   bchput(bytevalue);
	   PRINT("]");		
	}else{
		switch(bytevalue)
		{
			case 8:
				PRINT("[BS]");
				break;
				
			case 9:
				PRINT("[TAB]");
				break;
				
			case 11:
				PRINT("[Home]");
				break;
				
			case 13:
				PRINT("[Enter]");
				break;
				
			case 18:
				PRINT("[Ins]");
				break;
			
			case 24:
				PRINT("[Select]");
				break;
			
			case 27:
				PRINT("[Esc]");
				break;
				
			case 28:
				PRINT("[Right]");
				break;
				
			case 29:
				PRINT("[Left]");
				break;
				
			case 30:
				PRINT("[Up]");
				break;
				
			case 31:
				PRINT("[Down]");
				break;
				
			default:
		        		
		}
		
	}
	
    KillBuffer();
	
  }
}
