// Codejam_B.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <list>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{

	ifstream readfile;
	ofstream writefile;

	string line;
	int nTestCases;

	string strFileName = "B-large";
	string strInFileName = strFileName;
	string strOutFileName = strFileName;

	readfile.open( (strInFileName.append(".in")).c_str() );
	writefile.open( (strOutFileName.append(".out")).c_str() );



	if(readfile.is_open())
	{
		if(writefile.is_open())
		{
			getline (readfile,line);
			stringstream convert(line);
			if ( !(convert >> nTestCases) )//give the value to nTestCases using the characters in the string
				nTestCases = 0;	
			//cout << "Number of test cases : " << nTestCases << endl;

			if(nTestCases > 0)
			{
				for(int nCurrentTestCase = 1; nCurrentTestCase<=nTestCases; nCurrentTestCase++)
				{
					int nCombines;			// for the number of combines (C)
					int nOpposed;			// for the number of opposed  (D)
					int nInvokes;				// for the number of invokes  (N) 


					// Read the line of the test case
					getline (readfile,line);
					char* cline = (char *)line.c_str();
					char * cword;


					///////////// Gets the number of combines and the those characters combines /////////////////
					cword = strtok (cline," ,.-");
					stringstream convertCombines(cword);
					if ( !(convertCombines >> nCombines) )	//give the value to nCombines using the characters in the string
					{
						cout << "error occurred in converting string to int nCombines" << endl;
						return 0;
					}

					list<char *> lstCombines;
					//cout << "Number of combines is : " << nCombines << " : ";
					for(int i=0; i<nCombines; i++)
					{
						cword = strtok (NULL, " ,.-");
						lstCombines.push_back(cword);
						//cout << *(lstCombines.rbegin()) << " ";
					}					
					//cout << endl;
					/////////////////////////////////////////////////////////////////////////////////////////////





					///////////// Gets the number of opposed and the those characters opposed /////////////////
					cword = strtok (NULL," ,.-");
					stringstream convertOpposed(cword);
					if ( !(convertOpposed >> nOpposed) )	//give the value to nOpposed using the characters in the string
					{
						cout << "error occurred in converting string to int nOpposed" << endl;
						return 0;
					}
					
					list<char *> lstOpposed;
					//cout << "Number of opposed is : " << nOpposed << " : ";
					for(int i=0; i<nOpposed; i++)
					{
						cword = strtok (NULL, " ,.-");
						lstOpposed.push_back(cword);
						//cout << *(lstOpposed.rbegin()) << " ";
					}
					//cout << endl;
					/////////////////////////////////////////////////////////////////////////////////////////////





					///////////// Gets the list of invokes /////////////////
					cword = strtok (NULL," ,.-");
					stringstream convertInvokes(cword);
					if ( !(convertInvokes >> nInvokes) )	//give the value to nInvokes using the characters in the string
					{
						cout << "error occurred in converting string to int nInvokes" << endl;
						return 0;
					}

					char *cInvokes;
					cword = strtok (NULL," ,.-");
					if (cword != NULL)
					{
						cInvokes = cword;
						//cout << "Number of invokes is : " << nInvokes << " : " << cInvokes << endl;
					}


					if (nInvokes>0)
					{
					//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
					//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

						string strResult = "";

						for (int nCurrentCharacter=0; nCurrentCharacter<nInvokes; nCurrentCharacter++)
						{
							if (strResult.size() == 0)
							{
								strResult.replace(0,0, cInvokes, nCurrentCharacter,1);
								//cout << "Bgn : " << strResult << endl;
							}
							else
							{
								//cout << nCurrentCharacter << " - " << strResult << endl;
								bool iscombined = false;

								if (!strResult.empty())
								{
									////////// Check for a combine ////////////////////
									string lastPairA = "ab";
									lastPairA[0] = strResult[strResult.size()-1];
									lastPairA[1] = cInvokes[nCurrentCharacter];
									string lastPairB = "ab";
									lastPairB[0] = cInvokes[nCurrentCharacter];
									lastPairB[1] = strResult[strResult.size()-1];
									//cout << lastPair << endl;

									list<char *>::iterator itr;
									for ( itr=lstCombines.begin() ; itr != lstCombines.end(); itr++ )
									{
										//cout << "1. " << *itr << " 2. " << lastPairA << endl;
										if ( (strncmp( lastPairA.c_str(), *itr, 2) == 0) || (strncmp( lastPairB.c_str(), *itr, 2) == 0))
										{
											iscombined = true;
											//cout << "Matched : " << *itr;
											//cout << " >> Before : " << strResult;
											strResult.replace(strResult.size()-1,strResult.size(),*itr,2,3);
											//cout << " << After : " << strResult << endl;
											//cout << nCurrentCharacter << " - " << strResult << ".C1." << endl;
											break;
										}
									}
									if(!iscombined)
									{
										strResult.replace(strResult.size(),1,cInvokes,nCurrentCharacter,1);
										//cout << nCurrentCharacter << " - " << strResult << ".C2." << endl;
									}
									////////////////////////////////////////////////////



									///////// Check for a oppossed /////////////////////
									for ( itr=lstOpposed.begin() ; itr != lstOpposed.end(); itr++ )
									{
										//cout << "opposed" << endl;

										string oppA = *itr;
										string oppB = "ab";
										oppB[0] = oppA[1];
										oppB[1] = oppA[0];

										char cfirst = oppA[0];
										char csecond = oppA[1];


										size_t found;

										//cout << "opposed -" << cfirst << "-" << csecond << "    +" << (strResult.find(&oppA[0], 0, 1) != string.npos) <<  "+" << "+" << (strResult.find(&oppA[1], 0, 1) != string.npos) <<  "+" << endl;

										if ( ( (strResult.find(&oppA[0], 0, 1) != string.npos) && (strResult.find(&oppA[1], 0, 1) != string.npos) ) == 1 )
										{
											//cout << "MMatched : " << *itr;
											//cout << " >> BBefore : " << strResult;
											//cout << " +" << strResult[0] << strResult[strResult.size()-1] << "+";
											strResult.replace(0,strResult.size(),"");
											//cout << " << AAfter : " << strResult << endl;
											break;
										}
									}

									////////////////////////////////////////////////////
								}
							}
						}



































						char *cResult = (char *)strResult.c_str();
						writefile << "Case #" <<nCurrentTestCase<< ": [";
						if (strlen(cResult) > 0)
						{
							writefile << cResult[0];
							for(int i=1; i<strlen(cResult); i++)
								writefile << ", " << cResult[i];
						}
						writefile << "]" << endl;
					//////////////////////////////////////////////////////////////////////////////////////////////////////////////////					
					//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
					}
					else
						writefile << "Case #" <<nCurrentTestCase<< ": []" << endl;



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

	system("PAUSE");
}

