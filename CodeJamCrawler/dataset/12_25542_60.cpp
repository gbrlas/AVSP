// Problem_A.cpp : Defines the entry point for the console application.
//

#include "stl.h"

///////////////////////////////////////////////////////////////////////////////
// TESTING PARAMETERS
const char* FILENAME="A%d.in";
const int FILE_FROM = 1;
const int FILE_TO = 1;
const bool OUT_FILE = true;
FILE *FILE_OUT;
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////

char mapping[][2]={
	{'a', 'y'}, {'b', 'n'}, {'c', 'f'}, {'d', 'i'}, {'e', 'c'}, {'f', 'w'}, {'g', 'l'}, {'h', 'b'}, 
	{'i', 'k'}, {'j', 'u'}, {'k', 'o'}, {'l', 'm'}, {'m', 'x'}, {'n', 's'}, {'o', 'e'}, {'p', 'v'}, 
	{'q', 'z'}, {'r', 'p'}, {'s', 'd'}, {'t', 'r'}, {'u', 'j'}, {'v', 'g'}, {'w', 't'}, {'x', 'h'}, 
	{'y', 'a'}, {'z', 'q'},
};

void ProcessFile(FILE* fin)
{
	int C;
	fscanf(fin, "%d", &C);
	char line[256];
	fgets(line, 256, fin);
	for (int i=0; i<C; ++i)
	{
		char line[256];
		fgets(line, 256, fin);
		for (char* c=line; *c; ++c)
		{
			for (int i=0; i<sizeof(mapping)/sizeof(mapping[0]); ++i)
			{
				if (*c==mapping[i][1])
				{
					*c=mapping[i][0];
					break;
				}
			}
		}
		fprintf(FILE_OUT, "Case #%d: %s", i+1, line);
	}
}

///////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
	char fileName[256];
	for (int file_from=FILE_FROM; file_from<=FILE_TO; ++file_from)
	{
		sprintf(fileName, FILENAME, file_from);
		FILE *fin = fopen(fileName, "r");
		if (OUT_FILE)
		{
			char fileNameOut[256];
			sprintf(fileNameOut, "%s.out", fileName);
			FILE_OUT = fopen(fileNameOut, "w");
		} else
		{
			FILE_OUT = stdout;
		}
		ProcessFile(fin);
		fclose(fin);
		if (OUT_FILE)
		fclose(FILE_OUT);
	}
	int c;
	getc(stdin);
	return 0;
}
