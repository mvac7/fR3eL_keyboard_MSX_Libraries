# How to use the Keyboard MSX ROM Library (fR3eL Project)

---

## Index

- [1 Description](#1-Description)
- [2 Requirements](#2-Requirements)
- [3 Definitions](#3-Definitions)
    - [3.1 Bit values](#31-Bit-values)
- [4 Functions](#4-Functions)
	- [4.1 KillBuffer](#41-KillBuffer)
	- [4.2 INKEY](#42-INKEY)
	- [4.3 GetKeyMatrix](#43-GetKeyMatrix)
- [5 A bit of code](#5-A-bit-of-code)
- [6 Appendices](#6-Appendices)
    - [6.1 Keyboard Matrix](#61-Keyboard-Matrix)
        - [6.1.1 International](#611-International)
        - [6.1.2 Numeric pad](#612-Numeric-pad)
- [7 References](#7-References)

<br/>

---

## 1 Description

C function library with basic functions for reading the keyboard of MSX computers.

In this project you will find two libraries for different environments:
- **keyboard_MSXBIOS** Uses the MSX BIOS. It takes up very little memory. You can use it to develop applications in ROM format or programs that run from MSX BASIC environment.
- **keyboard_MSXDOS** Uses the MSX BIOS functions via inter-slot call (CALSLT). You can use it to develop applications for the MSX-DOS environment.
  
You can use these libraries to develop applications for ROM, MSXBASIC or MSX-DOS environments, using the Small Device C Compiler [(SDCC)](http://sdcc.sourceforge.net/) cross compiler.

These libraries are part of the [MSX fR3eL Project](https://github.com/mvac7/SDCC_MSX_fR3eL).

This project is open source under the [MIT license](LICENSE).
You can add part or all of this code in your application development or include it in other libraries/engines.

<br/>

---

## 2 Requirements

- [Small Device C Compiler (SDCC) v4.4](http://sdcc.sourceforge.net/)
- [Hex2bin v2.5](http://hex2bin.sourceforge.net/)

<br/>

---

## 3 Definitions

The library provides a number of definitions to help you improve the readability of your source code.

### 3.1 Bit values

You can use it to check the key pressed with the [GetKeyMatrix](#43-GetKeyMatrix) function.

Label | value
:---  | ---:  
Bit0  | 1
Bit1  | 2
Bit2  | 4
Bit3  | 8
Bit4  | 16
Bit5  | 32
Bit6  | 64
Bit7  | 128

<br/>

#### Example:

```c
  keyPressed = GetKeyMatrix(7);
  if (!(keyPressed&Bit4)) Stop();   // [STOP]
```

<br/>

---

## 4 Functions


### 4.1 KillBuffer

<table>
<tr><th colspan=3 align="left">KillBuffer</th></tr>
<tr><td colspan=3>Clear keyboard buffer.</td></tr>
<tr><th>Function</th><td colspan=2>KillBuffer()</td></tr>
<tr><th>Input</th><td colspan=2>--</td></tr>
<tr><th>Output</th><td colspan=2>--</td></tr>
</table>

<br/>

#### Example:

```c
	KillBuffer();
	INKEY();
```

<br/>

### 4.2 INKEY

<table>
<tr><th colspan=3 align="left">INKEY</th></tr>
<tr><td colspan=3>Waits for a key press and returns its value.</td></tr>
<tr><th>Function</th><td colspan=2>INKEY()</td></tr>
<tr><th>Input</th><td colspan=2>--</td></tr>
<tr><th>Output</th><td>[char]</td><td>Key code</td></tr>
</table>

<br/>

#### Example:

```c
	char byteValue;
	byteValue = INKEY();
	if (byteValue==13) pressReturnKey();
```

<br/>

### 4.3 GetKeyMatrix

<table>
<tr><th colspan=3 align="left">GetKeyMatrix</th></tr>
<tr><td colspan=3>Returns the value of the specified row from the keyboard matrix.<br/>
Each line provides the status of 8 keys (row).<br/>
To know which keys correspond, you will need documentation that<br/> 
includes a keyboard table.</td></tr>
<tr><th>Function</th><td colspan=2>GetKeyMatrix(row)</td></tr>
<tr><th>Input</th><td>[char]</td><td>Row</td></tr>
<tr><th>Output</th><td>[char]</td><td>Keys row state (1=not pressed; 0=pressed)</td></tr>
</table>

<br/>

#### Example:

```c
	char keyPressed;
	keyPressed = GetKeyMatrix(7);
	if (!(keyPressed & Bit2)) Exit(); //ESC Key
```

<br/>

---

## 5 A bit of code
 
This code contains the basis for controlling any key with pressure control.

You can add it to your program and adapt it with the keyboard rows and keys that your program uses.

Uncomment the lines of the keys you need and add the code to be executed, after setting the pressure control variable to true.

<br/>

#### Example:

```c
  if (!(keyPressed&Bit5)) {Row6pressed=true;KonamisPause();} // [F1]
  if (!(keyPressed&Bit6)) 
  {
     Row6pressed=true;
     score++;
     ShowValue(score);
  } //[F2]
```

<br/>

#### The code:

```c
#include "../include/keyboard.h"


// boolean
#ifndef _BOOLEAN
#define _BOOLEAN
  typedef enum {false = 0, true = 1} boolean;
#endif


#define  HALT __asm halt __endasm

 

// pressure control variables
// define in global (or local) variables: 
boolean Row0pressed;
boolean Row1pressed;
boolean Row2pressed;
boolean Row3pressed;  
boolean Row4pressed;
boolean Row5pressed;
boolean Row6pressed;
boolean Row7pressed;
boolean Row8pressed;


void main(void) 
{
  char keyPressed;
  
  //initialize pressure control variables
  Row0pressed=false;
  Row1pressed=false;
  Row2pressed=false;
  Row3pressed=false;  
  Row4pressed=false;
  Row5pressed=false;
  Row6pressed=false;
  Row7pressed=false;
  Row8pressed=false;
  
  while(1)
  {
    HALT;

    // Keyboard row 0
    keyPressed = GetKeyMatrix(0);
    if (keyPressed!=0xFF)
    {
      if(Row0pressed==false)
      {
        //if (!(keyPressed&Bit0)) {Row0pressed=true;} //[0]
        //if (!(keyPressed&Bit1)) {Row0pressed=true;} //[1] 
        //if (!(keyPressed&Bit2)) {Row0pressed=true;} //[2]
        //if (!(keyPressed&Bit3)) {Row0pressed=true;} //[3] 
        //if (!(keyPressed&Bit4)) {Row0pressed=true;} //[4]
        //if (!(keyPressed&Bit5)) {Row0pressed=true;} //[5]
        //if (!(keyPressed&Bit6)) {Row0pressed=true;} //[6]
        //if (!(keyPressed&Bit7)) {Row0pressed=true;} //[7]
      }      
    }else Row0pressed=false;
  
    // Keyboard row 1 
    keyPressed = GetKeyMatrix(1);
    if (keyPressed!=0xFF)
    {
      if(Row1pressed==false)
      {
        //if (!(keyPressed&Bit0)) {Row1pressed=true;} //[8]
        //if (!(keyPressed&Bit1)) {Row1pressed=true;} //[9] 
        //if (!(keyPressed&Bit2)) {Row1pressed=true;} //[-]
        //if (!(keyPressed&Bit3)) {Row1pressed=true;} //[=] 
        //if (!(keyPressed&Bit4)) {Row1pressed=true;} //[\]
        //if (!(keyPressed&Bit5)) {Row1pressed=true;} //[[]
        //if (!(keyPressed&Bit6)) {Row1pressed=true;} //[]]
        //if (!(keyPressed&Bit7)) {Row1pressed=true;} //[;]
      }      
    }else Row1pressed=false;
    
    
    // Keyboard row 2
    keyPressed = GetKeyMatrix(2);
    if (keyPressed!=0xFF)
    {
      if(Row2pressed==false)
      {
        //if (!(keyPressed&Bit0)) {Row2pressed=true;} //[']
        //if (!(keyPressed&Bit1)) {Row2pressed=true;} //[&] 
        //if (!(keyPressed&Bit2)) {Row2pressed=true;} //[,]
        //if (!(keyPressed&Bit3)) {Row2pressed=true;} //[.] 
        //if (!(keyPressed&Bit4)) {Row2pressed=true;} //[/]
        //if (!(keyPressed&Bit5)) {Row2pressed=true;} //[Dead key]
        //if (!(keyPressed&Bit6)) {Row2pressed=true;} //[A]
        //if (!(keyPressed&Bit7)) {Row2pressed=true;} //[B]
      }      
    }else Row2pressed=false;
    
    
    // Keyboard row 3
    keyPressed = GetKeyMatrix(3);
    if (keyPressed!=0xFF)
    {
      if(Row3pressed==false)
      {
        //if (!(keyPressed&Bit0)) {Row3pressed=true;} //[C]
        //if (!(keyPressed&Bit1)) {Row3pressed=true;} //[D]
        //if (!(keyPressed&Bit2)) {Row3pressed=true;} //[E]
        //if (!(keyPressed&Bit3)) {Row3pressed=true;} //[F]
        //if (!(keyPressed&Bit4)) {Row3pressed=true;} //[G]
        //if (!(keyPressed&Bit5)) {Row3pressed=true;} //[H]
        //if (!(keyPressed&Bit6)) {Row3pressed=true;} //[I]
        //if (!(keyPressed&Bit7)) {Row3pressed=true;} //[J]
      }      
    }else Row3pressed=false;
    
    
    // Keyboard row 4
    keyPressed = GetKeyMatrix(4);
    if (keyPressed!=0xFF)
    {
      if(Row4pressed==false)
      {
        //if (!(keyPressed&Bit0)) {Row4pressed=true;} //[K]
        //if (!(keyPressed&Bit1)) {Row4pressed=true;} //[L]
        //if (!(keyPressed&Bit2)) {Row4pressed=true;} //[M]
        //if (!(keyPressed&Bit3)) {Row4pressed=true;} //[N]
        //if (!(keyPressed&Bit4)) {Row4pressed=true;} //[O]
        //if (!(keyPressed&Bit5)) {Row4pressed=true;} //[P]
        //if (!(keyPressed&Bit6)) {Row4pressed=true;} //[Q]
        //if (!(keyPressed&Bit7)) {Row4pressed=true;} //[R]
      }      
    }else Row4pressed=false;    
   
   
    
    // Keyboard row 5
    keyPressed = GetKeyMatrix(5);
    if (keyPressed!=0xFF)
    {
      if(Row5pressed==false)
      {
        //if (!(keyPressed&Bit0)) {Row5pressed=true;} //[S]
        //if (!(keyPressed&Bit1)) {Row5pressed=true;} //[T]
        //if (!(keyPressed&Bit2)) {Row5pressed=true;} //[U]
        //if (!(keyPressed&Bit3)) {Row5pressed=true;} //[V]
        //if (!(keyPressed&Bit4)) {Row5pressed=true;} //[W]
        //if (!(keyPressed&Bit5)) {Row5pressed=true;} //[X]
        //if (!(keyPressed&Bit6)) {Row5pressed=true;} //[Y]
        //if (!(keyPressed&Bit7)) {Row5pressed=true;} //[Z]
      }      
    }else Row5pressed=false;
    
    
    // Keyboard row 6
    keyPressed = GetKeyMatrix(6);
    if (keyPressed!=0xFF)
    {
      if(Row6pressed==false)
      {
        //if (!(keyPressed&Bit0)) {Row6pressed=true;} //[SHIFT]
        //if (!(keyPressed&Bit1)) {Row6pressed=true;} //[CTRL]
        //if (!(keyPressed&Bit2)) {Row6pressed=true;} //[GRAPH]
        //if (!(keyPressed&Bit3)) {Row6pressed=true;} //[CAPS]
        //if (!(keyPressed&Bit4)) {Row6pressed=true;} //[CODE]
        //if (!(keyPressed&Bit5)) {Row6pressed=true;} //[F1]
        //if (!(keyPressed&Bit6)) {Row6pressed=true;} //[F2]
        //if (!(keyPressed&Bit7)) {Row6pressed=true;} //[F3]
      }      
    }else Row6pressed=false;
    
    
    // Keyboard row 7
    keyPressed = GetKeyMatrix(7);
    if (keyPressed!=0xFF)
    {
      if(Row7pressed==false)
      {
        //if (!(keyPressed&Bit0)) {Row7pressed=true;} //[F4]
        //if (!(keyPressed&Bit1)) {Row7pressed=true;} //[F5]
        //if (!(keyPressed&Bit2)) {Row7pressed=true;} //[ESC]
        //if (!(keyPressed&Bit3)) {Row7pressed=true;} //[TAB]
        //if (!(keyPressed&Bit4)) {Row7pressed=true;} //[STOP]
        //if (!(keyPressed&Bit5)) {Row7pressed=true;} //[BS]
        //if (!(keyPressed&Bit6)) {Row7pressed=true;} //[SELECT]
        //if (!(keyPressed&Bit7)) {Row7pressed=true;} //[RETURN]
      }      
    }else Row7pressed=false;
    
    
    // Keyboard row 8
    keyPressed = GetKeyMatrix(8);
    if (keyPressed!=0xFF)
    {
      if(Row8pressed==false)
      {
        //if (!(keyPressed&Bit0)) {Row8pressed=true;} //[SPACE]
        //if (!(keyPressed&Bit1)) {Row8pressed=true;} //[HOME]
        //if (!(keyPressed&Bit2)) {Row8pressed=true;} //[INS]
        //if (!(keyPressed&Bit3)) {Row8pressed=true;} //[DEL]
        //if (!(keyPressed&Bit4)) {Row8pressed=true;} //[LEFT]
        //if (!(keyPressed&Bit5)) {Row8pressed=true;} //[UP]
        //if (!(keyPressed&Bit6)) {Row8pressed=true;} //[DOWN]
        //if (!(keyPressed&Bit7)) {Row8pressed=true;} //[RIGHT]
      }      
    }else Row8pressed=false;


  } //END while


}
```

<br/>

---

## 6 Appendices

### 6.1 Keyboard Matrix
  
#### 6.1.1 International

```  
Row  7      6      5      4      3      2      1      0    <-- bit
-----------------------------------------------------------
  0  7      6      5      4      3      2      1      0  
  1  ;      ]      [      \      =      -      9      8  
  2  B      A      acent  /      .      ,      `      '  
  3  J      I      H      G      F      E      D      C
  4  R      Q      P      O      N      M      L      K
  5  Z      Y      X      W      V      U      T      S
  6  F3     F2     F1     CODE   CAPS   GRAPH  CTRL   SHIFT
  7  RETURN SELECT BS     STOP   TAB    ESC    F5     F4
  8  Right  Down   Up     Left   DEL    INS    HOME   SPACE
```

<br/> 

#### 6.1.2 Numeric pad

```
Row  7      6      5      4      3      2      1      0    <-- bit
----------------------------------------------------------- 
  9  4      3      2      1      0      /      +      *
 10  .      ,      -      9      8      7      6      5
```

<br/>

---

## 7 References

- MSX Assembly Page - [Keyboard matrices](http://map.grauw.nl/articles/keymatrix.php)
- [MSX2 Technical Handbook](https://konamiman.github.io/MSX2-Technical-Handbook/) - [Chapter 5 Access to peripherals through bios](https://konamiman.github.io/MSX2-Technical-Handbook/md/Chapter5a.html) - [3. Keyboard Interface](https://konamiman.github.io/MSX2-Technical-Handbook/md/Chapter5a.html#3-keyboard-interface)
- MSX Resource Center - [Wiki](https://www.msx.org/wiki/) - [Keyboard Matrices ](https://www.msx.org/wiki/Keyboard_Matrices)

<br/>

---

![Creative Commons License](https://i.creativecommons.org/l/by-nc/4.0/88x31.png) 
<br/>This document is licensed under a [Creative Commons Attribution-NonCommercial 4.0 International License](http://creativecommons.org/licenses/by-nc/4.0/).
