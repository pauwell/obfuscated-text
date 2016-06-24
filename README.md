# obfuscated_string_art
Converts a string of characters into an ascii-art.

	    ~ String to art ~
	    - Paul Bernitz -
		  2016
__________________________________________________________________

Font-storage:

const unsigned char letter_a[5] = { 0xF9F99 };

	"A"	Binary	Hex
	****	1111    0xF
	*  *  	1001  	0x9
	**** 	1111  	0xF
	*  *  	1001  	0x9
	*  *  	1001  	0x9
	
__________________________________________________________________

Compiled with:
gcc version 4.4.1 mingw32

gcc -o C:/CCode/out C:/CCode/main.c
start C:/CCode/out.exe "Hello World" "C:/CCode/output.txt"

		
