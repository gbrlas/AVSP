#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

const short int charoffset = 48;
const char digitmax = 61;
const char casemax = 100;
char testcase[casemax][digitmax];
short int testcase_n1[casemax][digitmax];
short int testcase_n2[casemax][digitmax];
unsigned long int testcase_r[casemax];
short int testcasedigits[casemax];
char dictionary[digitmax];
char tempcase[digitmax];
int testcases;

int readinputfile();

long unsigned int power(int a, int b)
{
     long unsigned int c=1;
     for (int i=0; i<b; i++) c*=a;
     return c;
}

int main()
{
	readinputfile();
	ofstream outputfile;
	outputfile.open ("g:\\A-small-attempt3.out");
	if (outputfile.is_open()) {
	//if (1==1) {
		int tc,i,j;

		// output
		for ( tc=0; tc<testcases; tc++ ){
			cout << "Input #" << tc+1 << ": ";
			for ( i=testcasedigits[tc] ; i>=0 ; i-- ) cout << testcase[tc][i];
			cout << endl;
		}

		for ( tc=0; tc<testcases ; tc++ ) {
			int variations=0;

			for ( i=testcasedigits[tc]; i>=0 ; i-- ) {
				char found=0;
				for ( j=0 ; j<variations && !found ; j++ ) if (testcase[tc][i]==dictionary[j]) { found=1; testcase_n1[tc][i]=j; }
				if ( !found ) { dictionary[variations]=testcase[tc][i]; testcase_n1[tc][i]=variations; variations++; }
			}

			for ( i=0; i<=testcasedigits[tc] ; i++ ) {
				testcase_n2[tc][i]=(testcase_n1[tc][i]>1)?testcase_n1[tc][i]:1-testcase_n1[tc][i];
			}

			variations=(variations>1)?variations:2;
			for ( i=0,testcase_r[tc]=0; i<=testcasedigits[tc] ; i++ ) {
				testcase_r[tc]+=(testcase_n2[tc][i])*power(variations,i);
			}
		}
		cout << endl;

		// output
		for ( tc=0; tc<testcases; tc++ ){
			cout << "Output #" << tc+1 << ": ";
			for ( i=testcasedigits[tc] ; i>=0 ; i-- ) cout << testcase_n1[tc][i];
			cout << endl;
		}
		cout << endl;
		for ( tc=0; tc<testcases; tc++ ){
			cout << "Output #" << tc+1 << ": ";
			for ( i=testcasedigits[tc] ; i>=0 ; i-- ) cout << testcase_n2[tc][i];
			cout << endl;
		}
		cout << endl;
		for ( tc=0; tc<testcases; tc++ ){
			cout << "Output #" << tc+1 << ": " << testcase_r[tc] << endl;
		}
		for ( tc=0; tc<testcases; tc++ ){
			outputfile << "Case #" << tc+1 << ": " << testcase_r[tc] << endl;
		}
	}
	else cout << "Error opening file for output" << endl;
	return (0);
}

int readinputfile()
{
	ifstream inputfile;

	inputfile.open ("g:\\A-small-attempt3.in");
	if (inputfile.is_open())
	{
		int i,j,tc;
		string inputline;
		getline (inputfile,inputline);
		for ( i=0,testcases=0 ; inputline[i] != ' ' && (int)(inputline[i])-48 >= 0 && (int)(inputline[i])-48 <= 9 && i<=8; i++ ) testcases = 10*testcases + ((int)(inputline[i])-charoffset);
		for ( tc=0; tc<testcases ; tc++ ) {
			getline (inputfile,inputline);
			for ( i=0 ; inputline[i] != ' ' && (((int)(inputline[i])-charoffset >= 0 && (int)(inputline[i])-charoffset <= 9) || (inputline[i]>='a' && inputline[i]<='z'))  && i<=32; i++ ) tempcase[i] = (inputline[i]);
			for ( testcasedigits[tc]=i-1,j=testcasedigits[tc] ; j>=0; j-- ) testcase[tc][j] = (j>testcasedigits[tc])?0:tempcase[testcasedigits[tc]-j];
		}
		inputfile.close();
	}
	else cout << "unable to open file";
	return (0);
}
