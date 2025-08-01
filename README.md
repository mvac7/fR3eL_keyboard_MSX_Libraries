# Keyboard MSX SDCC Library (fR3eL Project)

<table>
<tr><td rowspan=2>Name</td><td>keyboard_MSXBIOS</td></tr>
<tr><td>keyboard_MSXDOS</td></tr>
<tr><td>Architecture</td><td>MSX</td></tr>
<tr><td>Environment</td><td>ROM, MSX BASIC or MSX-DOS</td></tr>
<tr><td>Format</td><td>SDCC Relocatable object file (.rel)</td></tr>
<tr><td>Compiler</td><td>SDCC v4.4</td></tr>
<tr><td>License</td><td><a href="LICENSE">MIT license</a></td></tr>
</table>

---

## Description

C function library with basic functions for reading the keyboard of MSX computers.

In this project you will find two libraries for different environments:
- **keyboard_MSXBIOS** Uses the MSX BIOS. It takes up very little memory. You can use it to develop applications in ROM format or programs that run from MSX BASIC environment.
- **keyboard_MSXDOS** Uses the MSX BIOS functions via inter-slot call (CALSLT). You can use it to develop applications for the MSX-DOS environment.
  
You can access the documentation here with [`How to use the library`](docs/HOWTO.md).

You can use these libraries to develop applications for ROM, MSXBASIC or MSX-DOS environments, using the Small Device C Compiler [(SDCC)](http://sdcc.sourceforge.net/) cross compiler.

These libraries are part of the [MSX fR3eL Project](https://github.com/mvac7/SDCC_MSX_fR3eL).

This project is open source under the [MIT license](LICENSE).
You can add part or all of this code in your application development or include it in other libraries/engines.

Enjoy it!

<br/>

---

## History of versions:

### keyboard_MSXBIOS
- v1.1 (30/11/2023) update to SDCC (4.1.12) Z80 calling conventions
- v1.0 (7/3/2016) first version

<br/>

### keyboard_MSXDOS
- v1.1 (8/12/2023) update to SDCC (4.1.12) Z80 calling conventions
- v1.0 (2/3/2016) first version

<br/>

---

## Requirements

- [Small Device C Compiler (SDCC) v4.4](http://sdcc.sourceforge.net/)
- [Hex2bin v2.5](http://hex2bin.sourceforge.net/)

<br/>

---

## Functions

| Function | Description |
| :---     | :---        |
| **KillBuffer**() | Clear keyboard buffer |
| **INKEY**() | Waits for a key press and returns its value |
| **GetKeyMatrix**(row) | Returns the value of the specified line from the keyboard matrix |

<br/>

---

## Code Examples

In the git project [`examples/`](../examples/), you can find the source code of applications for testing and learning purposes.

<br/>

### Example 1 Test INKEY (ROM)

Test of the INKEY function of the keyboard_MSXBIOS library.

[`examples/Example01_INKEY_ROM`](examples/Example01_INKEY_ROM)

![Example screenshot](docs/pics/cs_Example01_INKEY_ROM.png) 

<br/>

### Example 2 Test GetKeyMatrix (ROM)

Test of the GetKeyMatrix function of the keyboard_MSXBIOS library.

[`examples/Example02_GetKeyMatrix_ROM`](examples/Example02_GetKeyMatrix_ROM)

![Example screenshot](docs/pics/cs_Example02_GetKeyMatrix_ROM.png) 

<br/>

### Example 3 Test INKEY (MSX-DOS)

Test of the INKEY function of the keyboard_MSXDOS library.

[`examples/Example03_INKEY_MSXDOS`](examples/Example03_INKEY_MSXDOS)

![Example screenshot](docs/pics/cs_Example03_INKEY_MSXDOS.png) 

<br/>

### Example 4 Test GetKeyMatrix (MSX-DOS)

Test of the GetKeyMatrix function of the keyboard_MSXDOS library.

[`examples/Example04_GetKeyMatrix_MSXDOS`](examples/Example04_GetKeyMatrix_MSXDOS)

![Example screenshot](docs/pics/cs_Example04_GetKeyMatrix_MSXDOS.png) 

<br/>
