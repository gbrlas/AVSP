#include <stdio.h>

#define LF				0x0A	//Line Feed
#define SP				0x20	

#define MAXLENGTH	32


void vFileParseError()
{
	printf("\nFile Error!\n");
}


unsigned char string[ MAXLENGTH ], needle[] = {"welcome to code jam"};
const char needleLength = 20;
long findPatterns( int pos, int start, int end );

int main()
{	
	
	unsigned char ucInFileName[] = {"C-small-attempt0.in"};
	unsigned char ucOutFileName[] = {"C-small-attempt0.out"};
	
	FILE *pstInFile, *pstOutFile;

	pstInFile = fopen( ucInFileName, "r" );
	pstOutFile = fopen( ucOutFileName, "w" );


	//Counters
	unsigned int testCases = 0, caseCtr = 0;
	
	
	//Read N
	fscanf( pstInFile, "%d", &testCases );
	
	if( fgetc(pstInFile) != LF )
	{
		vFileParseError();
		return 1;
	}
	
	
	char pos, needleNotFound;
	
	int firstI, nextI, totalChars, unnamedVal;
	long patternsFound = 0;
	
	//Start parsing strings
	while( caseCtr < testCases )
	{
		fgets( string, MAXLENGTH, pstInFile );
		
		totalChars = strlen( string );
		
		patternsFound = findPatterns( 0, 0, totalChars);
		
		if( patternsFound >= 0  && patternsFound <= 9)
		{
			fprintf( pstOutFile, "Case #%d: 000%d\n", caseCtr + 1, patternsFound );
		}
		else if( patternsFound >= 10  && patternsFound <= 99)
		{
			fprintf( pstOutFile, "Case #%d: 00%d\n", caseCtr + 1, patternsFound );
		}
		else if( patternsFound >= 100  && patternsFound <= 999)
		{
			fprintf( pstOutFile, "Case #%d: 0%d\n", caseCtr + 1, patternsFound );
		}
		else if( patternsFound >= 1000  && patternsFound <= 9999)
		{
			fprintf( pstOutFile, "Case #%d: %d\n", caseCtr + 1, patternsFound );
		}
		else
		{
			fprintf( pstOutFile, "Case #%d: %d\n", caseCtr + 1, patternsFound%10000 );
		}
		
		caseCtr++;
	}
	
	
	fclose( pstOutFile );
	fclose( pstInFile );
		
	return  0;
}


long findPatterns( int pos, int start, int end )
{
	long count = 0, i, val;
	
	//printf("' '");
	if( pos == needleLength - 1)
		return 1;

	for( i = start; i < end; i++ )
	{
		if( string[i] == needle[pos] )
		{
			val = findPatterns( pos + 1, i+1, end );
			if( val != 0 )
			{
				count += val;
			}
		}
	}
	return count;
}

