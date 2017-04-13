#include <stdio.h>

#include "DataTypes.h"

#define LF				0x0A	//Line Feed
#define SP				0x20	

#define Lmax	16
#define Dmax	5000

void vFileParseError()
{
}


int scanList[Dmax], scanCtr = 0, tempScanCtr = 0, tempScanList[Dmax] ;

void scanFirstLetter(char ch);
void scanAnotherLetter( char ch, int pos );
void doMagic();

char refreshList = 1;

unsigned int uiLetters = 0, uiWords= 0, uiTestCases = 0;

//WordList
U8Bit ucWordList[Dmax][Lmax];
	

int main()
{
	U8Bit ucInFileName[] = {"A-large.in"};
	U8Bit ucOutFileName[] = {"A-large.out"};
	
	FILE *pstInFile, *pstOutFile;

	//Counters
	unsigned int uiTCCtr = 0, uiLCtr = 0, uiWCtr = 0;
	
	pstInFile = fopen( ucInFileName, "r" );
	pstOutFile = fopen( ucOutFileName, "w" );
	

	//Read L, D, N	
	fscanf( pstInFile, "%d", &uiLetters );
	
		
	if( fgetc(pstInFile) != SP )
			vFileParseError();
	
	fscanf( pstInFile, "%d", &uiWords );
	
	
	if( fgetc(pstInFile) != SP )
			vFileParseError();
	
	fscanf( pstInFile, "%d", &uiTestCases );
	
	if( fgetc(pstInFile) != LF )
	{
		vFileParseError();	
		return 0;
	}

	uiWCtr = 0;
	
	while( uiWCtr < uiWords )
	{
		
		fscanf( pstInFile, "%s", ucWordList[uiWCtr] );
		uiWCtr++;

	}
	
	if( fgetc(pstInFile) != LF )
	{
		vFileParseError();	
		return 0;
	}

	
	uiTCCtr = 0;

	int iPos = 0;
	
	char inputChar;

	
	while( uiTCCtr < uiTestCases )
	{			
		iPos = 0;
		refreshList = 1;
		
		inputChar = fgetc(pstInFile);	// the first letter scanned
		
		if( feof(pstInFile) )
			break;
		
		if( inputChar == '(' )	//combination of chars in this position
		{
			while(1)
			{
				inputChar = fgetc(pstInFile);			
				if( inputChar == ')')
					break;
				scanFirstLetter( inputChar );
				refreshList = 0;
			}
		}
		else	//single character
		{
			scanFirstLetter( inputChar );
		}
		
		
		
		if( scanCtr == 0)	//no pattern match for first letter itself, so this test case is useless
		{	
			//do nothing
		}
		else	//first letter scanning resulted in some pattern match
		{
			iPos++;
			while( iPos < uiLetters )
			{				
				refreshList = 1;
				inputChar = fgetc(pstInFile);
				
				if( inputChar == '(' )	//number of chars in this position
				{
					while(1)
					{
						inputChar = fgetc(pstInFile);
							
						if( inputChar == ')')
							break;
						scanAnotherLetter( inputChar, iPos );
						refreshList = 0;
					}
				}
				else	//single character
				{
					scanAnotherLetter( inputChar, iPos );
				}
				
				doMagic();
				
				
				if( scanCtr == 0)	//no pattern match for the letter at this position, so this test case is useless
				{
					break;	//no more scanning of subsequent letters
				}
				iPos++;
			}
		}
		
		fprintf( pstOutFile, "Case #%d: %d\n", uiTCCtr + 1, scanCtr );
		
		while( fgetc(pstInFile) != LF )
		{}
		
		
		uiTCCtr++;
	}
	
	fclose( pstOutFile );
	fclose( pstInFile );
		
	return  0;
}

void scanFirstLetter( char ch )
{
	int i;
	
	if( refreshList == 1 )
		scanCtr = 0;
	
	for( i = 0; i < uiWords; i++ )
	{
		if( ucWordList[i][0] == ch )
		{
			scanList[scanCtr] = i;
			scanCtr++;
		}
	}
}

void scanAnotherLetter( char ch, int pos )
{
	int i;
	
	if( refreshList == 1 )
		tempScanCtr = 0;

	for( i = 0; i < scanCtr; i++ )
	{
		if( ucWordList[scanList[i]][pos] == ch )
		{
			tempScanList[tempScanCtr] = scanList[i];
			tempScanCtr++;
		}
	}
}

void doMagic()	//copy tempScanList to scanList
{
	int i;
	
	for( i = 0; i < tempScanCtr; i++)
	{
		scanList[i] = tempScanList[i];
	}
	scanCtr = tempScanCtr;
}
