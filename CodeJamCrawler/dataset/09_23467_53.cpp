#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int mapi[100][100][100];
char mapo[100][100][100];
int maph[100];
int mapw[100];
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

	ofstream outputfile;
	outputfile.open ("g:\\B-small-attempt6.out");
	if (outputfile.is_open()) {
		int mc,my,mx,lower;
		int lastletter,lowerpos,nowposletter,lowerposletter;
		for ( mc=0,lastletter=0; mc<testcases; mc++ ) {
			mapo[mc][0][0]=lastletter;
			for ( my=0; my<maph[mc]; my++ ) {
				for ( mx=0; mx<mapw[mc]; mx++ ) {
					if ( mapo[mc][my][mx]!=-1 ) {
						lowerpos=0; nowposletter=mapo[mc][my][mx]; lowerposletter=nowposletter; lower=mapi[mc][my][mx];
						if ( my>0 ) if ( mapi[mc][my-1][mx]<lower ) { lowerpos=1; lowerposletter=mapo[mc][my-1][mx]; lower=mapi[mc][my-1][mx]; }
						if ( mx>0 ) if ( mapi[mc][my][mx-1]<lower ) { lowerpos=2; lowerposletter=mapo[mc][my][mx-1]; lower=mapi[mc][my][mx-1]; }
						if ( mx+1<mapw[mc] ) if ( mapi[mc][my][mx+1]<lower ) { lowerpos=4; lowerposletter=mapo[mc][my][mx+1]; lower=mapi[mc][my][mx+1]; }
						if ( my+1<maph[mc] ) if ( mapi[mc][my+1][mx]<lower ) { lowerpos=3; lowerposletter=mapo[mc][my+1][mx]; lower=mapi[mc][my+1][mx]; }

						if ( nowposletter>0 && lowerposletter>0 && nowposletter!=lowerposletter ) {
							int myint,mxint;
							int major,minor;
							major=(nowposletter>lowerposletter)?nowposletter:lowerposletter;
							minor=(nowposletter>lowerposletter)?lowerposletter:nowposletter;
							//cout << "major is " << major << endl;
							//cout << "minor is " << minor << endl;
							for ( myint=0; myint<maph[mc]; myint++ ) {
								for ( mxint=0; mxint<mapw[mc]; mxint++ ) {
									if ( mapo[mc][myint][mxint]==major ) mapo[mc][myint][mxint]=minor;
									if ( mapo[mc][myint][mxint]>major ) mapo[mc][myint][mxint]--;
								}
							}
							lastletter--;
						}
						if ( nowposletter>0 && lowerposletter==0 )
							switch( lowerpos ) {
								case 1: mapo[mc][my-1][mx]=nowposletter; break;
								case 2: mapo[mc][my][mx-1]=nowposletter; break;
								case 3: mapo[mc][my+1][mx]=nowposletter; break;
								case 4: mapo[mc][my][mx+1]=nowposletter; break;
							}

						if ( nowposletter==0 && lowerposletter>0 )
							mapo[mc][my][mx]=lowerposletter;

						if ( nowposletter==0 && lowerposletter==0 ) {
							lastletter++;
							mapo[mc][my][mx]=lastletter;
							switch( lowerpos ) {
								case 1: mapo[mc][my-1][mx]=lastletter; break;
								case 2: mapo[mc][my][mx-1]=lastletter; break;
								case 3: mapo[mc][my+1][mx]=lastletter; break;
								case 4: mapo[mc][my][mx+1]=lastletter; break;
							}
						}
					}
					{
						int myint,mxint;
						cout << "Debug #" << (mc+1) << ":" << endl;
						for ( myint=0; myint<maph[mc]; myint++ ) {
							for ( mxint=0; mxint<mapw[mc]; mxint++ ) {
								printf("%d ",mapo[mc][myint][mxint]);
							}
							cout << endl;
						}
					}

				}
				cout << endl;
			}

			{
				int myint,mxint;
				int offset=(mapo[mc][0][0]-97);
				cout << "Case #" << (mc+1) << ":" << endl;
				outputfile << "Case #"  << (mc+1) << ":" << endl;
				for ( myint=0; myint<maph[mc]; myint++ ) {
					for ( mxint=0; mxint<mapw[mc]; mxint++ ) {
						printf("%c ",mapo[mc][myint][mxint]-=offset);
						outputfile << mapo[mc][myint][mxint] << " ";
					}
					cout << endl;
					outputfile << endl;
				}
			}
		}
		outputfile.close();
	}
	else cout << "Error opening file for output" << endl;
	return (0);
}

int readinputfile()
{
	string inputline;
	ifstream inputfile;

	inputfile.open ("g:\\B-small-attempt6.in");
	if (inputfile.is_open())
	{

		int mc,my,mx,lcc;
		getline (inputfile,inputline);
		for ( lcc=0,testcases=0 ; inputline[lcc] != ' ' && (int)(inputline[lcc])-48 >= 0 && (int)(inputline[lcc])-48 <= 9 && lcc<=10; lcc++ ) testcases = 10*testcases + ((int)(inputline[lcc])-48);

		for ( mc=0; mc<testcases ; mc++ ) {
			getline (inputfile,inputline);
			for ( lcc=0,maph[mc]=0; inputline[lcc] != ' ' && (int)(inputline[lcc])-48 >= 0 && (int)(inputline[lcc])-48 <= 9 ; lcc++ ) maph[mc] = 10*maph[mc] + ((int)(inputline[lcc])-48);
			for ( lcc++,mapw[mc]=0; inputline[lcc] != ' ' && (int)(inputline[lcc])-48 >= 0 && (int)(inputline[lcc])-48 <= 9 ; lcc++ ) mapw[mc] = 10*mapw[mc] + ((int)(inputline[lcc])-48);
			for ( my=0; my<maph[mc] ; my++ ) {
				getline (inputfile,inputline);
				for ( mx=0,lcc=-1; mx<mapw[mc] ; mx++ ) {
					for ( lcc++; inputline[lcc] != ' ' && (int)(inputline[lcc])-48 >= 0 && (int)(inputline[lcc])-48 <= 9 ; lcc++ ) mapi[mc][my][mx] = 10*mapi[mc][my][mx] + ((int)(inputline[lcc])-48);
					mapo[mc][my][mx]=0;
				}
			}
		}

		inputfile.close();
	}
	else cout << "unable to open file";
	return (0);
}
