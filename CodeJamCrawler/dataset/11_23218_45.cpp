// Codejam_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;



int next(int ncurrentPos, char crobot, char *crobotArray, int narrayLength)
{
	int nnewPos;	
	for (nnewPos=ncurrentPos+1; nnewPos<narrayLength; nnewPos++)
	{
		if (crobotArray[nnewPos] == crobot)
			break;
	}
	return nnewPos;
}


int go(char crobot, int nCurrPos, int nDestPos, int *bottonArray)
{
	if ( nCurrPos<nDestPos )
		nCurrPos++;
	else if ( nCurrPos>nDestPos )
		nCurrPos--;

	return nCurrPos;
}





int _tmain(int argc, _TCHAR* argv[])
{

	ifstream readfile;
	ofstream writefile;

	string line;
	int nTestCases;

	string strFileName = "A-small-attempt0";

	readfile.open( (strFileName.append(".in")).c_str() );
	writefile.open( (strFileName.append(".out")).c_str() );



	if(readfile.is_open())
	{
		if(writefile.is_open())
		{
			getline (readfile,line);
			stringstream convert(line);
			if ( !(convert >> nTestCases) )//give the value to nTestCases using the characters in the string
				nTestCases = 0;	
			cout << "Number of test cases : " << nTestCases << endl;

			if(nTestCases > 0)
			{
				for(int nCurrentTestCase = 1; nCurrentTestCase<=nTestCases; nCurrentTestCase++)
				{
					int nLength;			// for the length of the path (N)


					getline (readfile,line);

					char* cline = (char *)line.c_str();
					char * cword;
					cword = strtok (cline," ,.-");

					stringstream convertN(cword);
					if ( !(convertN >> nLength) )//give the value to nLength using the characters in the string
					{
						cout << "error occurred in converting string to int nLength" << endl;
						return 0;
					}
					//cout << "First number is : " << nLength << endl;

					char *robotArray = new char[nLength];
					int *bottonArray = new int[nLength];


					
					for (int i=0; i<nLength; i++)
					{
						cword = strtok (NULL, " ,.-");
						robotArray[i] = *cword;


						cword = strtok (NULL, " ,.-");
						stringstream convertBotten(cword);
						if ( !(convertBotten >> bottonArray[i]) )//give the value to bottonArray[i] using the characters in the string
						{
							cout << "error occurred in converting string to bottonArray[" << i << "]" << endl;
							return 0;
						}

						//cout << robotArray[i] << " " << bottonArray[i] << endl;
					}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

					int nResult = 0;		// for the result


					bool idleFlagO;
					bool idleFlagB;

					int ndestB = next(-1, 'B', robotArray, nLength);
					int ndestO = next(-1, 'O', robotArray, nLength);


					if ( ndestB<nLength )
						idleFlagB = false;
					if ( ndestO<nLength )
						idleFlagO = false;


					int nCurrentLength = 0;
					int nCurrentPosB = 1;
					int nCurrentPosO = 1;

					while ( nCurrentLength<nLength )
					{
						if(robotArray[nCurrentLength] == 'B')
						{
							//cout << "Current letter is : B" << endl;

							if( nCurrentPosB==bottonArray[ndestB] )
							{
								//cout << nResult << " : Press B " << bottonArray[ndestB];

								nCurrentPosO = go('O', nCurrentPosO, bottonArray[ndestO], bottonArray);
								//cout << " << >> O moves to : " << nCurrentPosO << endl;

								ndestB =  next(ndestB, 'B', robotArray, nLength);
								nCurrentLength++;
							}
							else
							{
								nCurrentPosB = go('B', nCurrentPosB, bottonArray[ndestB], bottonArray);
								//cout << nResult << " : B moves to : " << nCurrentPosB;

								nCurrentPosO = go('O', nCurrentPosO, bottonArray[ndestO], bottonArray);
								//cout << " << >> O moves to : " << nCurrentPosB << endl;
							}
						}
						else if(robotArray[nCurrentLength] == 'O')
						{
							//cout << "Current letter is : O" << endl;

							if( nCurrentPosO==bottonArray[ndestO] )
							{
								nCurrentPosB = go('B', nCurrentPosB, bottonArray[ndestB], bottonArray);
								//cout << nResult << " : B moves to : " << nCurrentPosB;

								//cout << " << >> Press O " << bottonArray[ndestO] << endl;

								ndestO =  next(ndestO, 'O', robotArray, nLength);
								nCurrentLength++;
							}
							else
							{
								nCurrentPosB = go('B', nCurrentPosB, bottonArray[ndestB], bottonArray);
								//cout << nResult << " : B moves to : " << nCurrentPosB;

								nCurrentPosO = go('O', nCurrentPosO, bottonArray[ndestO], bottonArray);
								//cout << " << >> O moves to : " << nCurrentPosO << endl;
							}
						}
						nResult++;
					}
					cout << ">>>>>>>>>>>>>>>>> Result is : " << nResult << endl;
					writefile << "Case #" <<nCurrentTestCase<< ": " << nResult << endl;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////					
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


				}
			}
			else
				cout << "Error in test cases number" << endl;




			writefile.close();
		}
		else
		{
			cout << "Error while opening writer" << endl;
		}
	}
	else
	{
		readfile.close();
		cout << "Error while opening reader" << endl;
	}

	char c;
	cin >> c;
}

