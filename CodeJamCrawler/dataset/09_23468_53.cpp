#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string lookup="welcome to code jam";
string phrase[100];
int matches[100];
int testcases;

int readinputfile();
int cases();

int main()
{
	readinputfile();
	cases();
	return (0);
}

int cases() {

	//ofstream outputfile;
	//outputfile.open ("g:\\C-small-attempt0.out");
	//if (outputfile.is_open()) {
	if (1==1) {
		int i,j[19];
		for ( i=0,matches[i]=0; i<testcases; i++ ) {
			for ( j[0]=0; j[0]<500 && (1*phrase[i][j[0]])!=0; j[0]++ ) {
				if (lookup[0]==phrase[i][j[0]]) {

					for ( j[1]=j[0]+1; j[1]<500 && (1*phrase[i][j[1]])!=0; j[1]++ ) {

						if (lookup[1]==phrase[i][j[1]]) {

							for ( j[2]=j[1]+1; j[2]<500 && (1*phrase[i][j[2]])!=0; j[2]++ ) {
								if (lookup[2]==phrase[i][j[2]]) {

									for ( j[3]=j[2]+1; j[3]<500 && (1*phrase[i][j[3]])!=0; j[3]++ ) {
										if (lookup[3]==phrase[i][j[3]]) {

											for ( j[4]=j[3]+1; j[4]<500 && (1*phrase[i][j[4]])!=0; j[4]++ ) {
												if (lookup[4]==phrase[i][j[4]]) {

													for ( j[5]=j[4]+1; j[5]<500 && (1*phrase[i][j[5]])!=0; j[5]++ ) {
														if (lookup[5]==phrase[i][j[5]]) {

															for ( j[6]=j[5]+1; j[6]<500 && (1*phrase[i][j[6]])!=0; j[6]++ ) {
																if (lookup[6]==phrase[i][j[6]]) {

																	for ( j[7]=j[6]+1; j[7]<500 && (1*phrase[i][j[7]])!=0; j[7]++ ) {
																		if (lookup[7]==phrase[i][j[7]]) {

																			for ( j[8]=j[7]+1; j[8]<500 && (1*phrase[i][j[8]])!=0; j[8]++ ) {
																				if (lookup[8]==phrase[i][j[8]]) {

																					for ( j[9]=j[8]+1; j[9]<500 && (1*phrase[i][j[9]])!=0; j[9]++ ) {
																						if (lookup[9]==phrase[i][j[9]]) {

																							for ( j[10]=j[9]+1; j[10]<500 && (1*phrase[i][j[10]])!=0; j[10]++ ) {
																								if (lookup[10]==phrase[i][j[10]]) {

																									for ( j[11]=j[10]+1; j[11]<500 && (1*phrase[i][j[11]])!=0; j[11]++ ) {
																										if (lookup[11]==phrase[i][j[11]]) {

																											for ( j[12]=j[11]+1; j[12]<500 && (1*phrase[i][j[12]])!=0; j[12]++ ) {
																												if (lookup[12]==phrase[i][j[12]]) {

																													for ( j[13]=j[12]+1; j[13]<500 && (1*phrase[i][j[13]])!=0; j[13]++ ) {
																														if (lookup[13]==phrase[i][j[13]]) {

																															for ( j[14]=j[13]+1; j[14]<500 && (1*phrase[i][j[14]])!=0; j[14]++ ) {
																																if (lookup[14]==phrase[i][j[14]]) {

																																	for ( j[15]=j[14]+1; j[15]<500 && (1*phrase[i][j[15]])!=0; j[15]++ ) {
																																		if (lookup[15]==phrase[i][j[15]]) {

																																			for ( j[16]=j[15]+1; j[16]<500 && (1*phrase[i][j[16]])!=0; j[16]++ ) {
																																				if (lookup[16]==phrase[i][j[16]]) {

																																					for ( j[17]=j[16]+1; j[17]<500 && (1*phrase[i][j[17]])!=0; j[17]++ ) {
																																						if (lookup[17]==phrase[i][j[17]]) {

																																							for ( j[18]=j[17]+1; j[18]<500 && (1*phrase[i][j[18]])!=0; j[18]++ ) {
																																								if (lookup[18]==phrase[i][j[18]]) {
																																									matches[i]=(matches[i]==9999)?0:matches[i]+1;
																																								}
																																							}
																																						}
																																					}
																																				}
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			printf ("Case #%d: %04d\n",i+1,matches[i]);
			//cout << "Case #" << i << ": " << matches[i] << endl;
		}
	}
	else cout << "Error opening file for output" << endl;
	return (0);
}

int readinputfile()
{
	ifstream inputfile;

	inputfile.open ("g:\\C-small-attempt0.in");
	if (inputfile.is_open())
	{
		int pc,i;
		string inputline;
		getline (inputfile,inputline);
		for ( i=0,testcases=0 ; inputline[i] != ' ' && (int)(inputline[i])-48 >= 0 && (int)(inputline[i])-48 <= 9 && i<=10; i++ ) testcases = 10*testcases + ((int)(inputline[i])-48);
		for ( pc=0; pc<testcases ; pc++ ) {
			getline (inputfile,phrase[pc]);
		}
		inputfile.close();
	}
	else cout << "unable to open file";
	return (0);
}
