/* 
		  ¶¶  ¶¶¶¶ ¶¶¶   ¶   ¶  ¶  ¶¶¶      ¶¶¶¶ ¶¶¶¶      ¶¶¶¶ ¶¶¶  ¶¶¶¶
		 ¶      ¶  ¶  ¶  ¶   ¶¶ ¶ ¶           ¶  ¶  ¶      ¶  ¶ ¶  ¶   ¶ 
		  ¶¶    ¶  ¶¶¶   ¶   ¶¶¶¶ ¶ ¶¶        ¶  ¶  ¶      ¶¶¶¶ ¶¶¶    ¶ 
		    ¶   ¶  ¶ ¶   ¶   ¶ ¶¶ ¶  ¶        ¶  ¶  ¶      ¶  ¶ ¶ ¶    ¶ 
		  ¶¶    ¶  ¶  ¶  ¶   ¶  ¶ ¶¶¶¶        ¶  ¶¶¶¶      ¶  ¶ ¶  ¶   ¶ 
	 
								~ String to art ~

								 - Paul Bernitz -
									   2016
									   
		____________________________________________________________________


	Principle behind the font-storing:
	One letter has 5 bytes. Each byte represents one row. 
	The four  most significant bits are used.

	"A"		Binary	Hex
	****	1111	0xF
	*  *   	1001  	0x9
	**** 	1111  	0xF
	*  *   	1001  	0x9
	*  *   	1001  	0x9

	So: 
		const unsigned char letter_a[5] = { 0xF9F99 };

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Letters (all flipped horizontal).
const unsigned int LETTERS[] = 
{
	0xF9F99/* A */, 0x79797/* B */, 0xF111F/* C */, 0x79997/* D */, 
	0xF1F1F/* E */, 0xF1F11/* F */, 0xE1D9F/* G */, 0x99F99/* H */,
	0x22222/* I */, 0x3119E/* J */, 0x95159/* K */, 0x1111F/* L */,
	0x9FF99/* M */, 0x9BFD9/* N */, 0xF999F/* O */, 0x79711/* P */,
	0xF99F8/* Q */, 0x79759/* R */, 0x61686/* S */, 0xF4444/* T */,
	0x9999F/* U */, 0x99996/* V */, 0x99FF9/* W */, 0x99699/* X */,
	0x99644/* Y */, 0xF861F/* Z *//* Todo: Add special characters.*/
};

/*
	Reads two arguments:
	arg 1	-> String to convert.
	arg 2 	-> Path to output-textfile.

*/
int main(int argc, char* argv[]) 
{
	// Check if arguments are given.
	if(argc<3) exit(EXIT_FAILURE);

	// Declare variables.
	int ch, row, bit;
	char* result_rows[5];

	// Allocate memory for all characters in input-string (height: 5, width: 4).
	for (row=0; row<5; row++)
	{
		result_rows[row] = calloc(strlen(argv[1]) * 4, sizeof(char));
	}

	// Store each letter bitwise in the "result_rows".
	for(ch=0; ch<strlen(argv[1]); ch++)
		for(row=5; row-->0;)
			for(bit=0; bit<4; bit++)
				if (LETTERS[(tolower(argv[1][ch])) - 97] & (1 << (row*4+bit)))
					result_rows[row][ch * 4 + bit] = 0xB6;
				else 
					result_rows[row][ch * 4 + bit] = 0xA0;

	// Write as characters into text-file.
	FILE* file = fopen(argv[2], "w");
	if(file==NULL) exit(EXIT_FAILURE);
	for(row=5; row-->0;)
	{
		for(bit=0; bit<strlen(argv[1])*4; bit++)
		{
			if(!(bit%4)) fprintf(file, " ");
			fprintf(file, "%c", result_rows[row][bit]);
		}
		fprintf(file, "\n");
	}
	fclose(file);

    // Free memory.
	for (row=0; row<5; row++) free(result_rows[row]);

	// Exit.
	return EXIT_SUCCESS;
}
