#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string dict[5000];
string testcase[500];
int wordlen;
int dictlen;
int testcases;

int readfile();
int writefile();
int cases();

int main()
{
	readfile();
	cases();
	//cout << "il " << wordlen << ", lc " << dictlen << ", tc " << testcases << endl;
	//cout << inputmatrix[3] << endl;
	//writefile();
	return (0);
}

int cases() {

	ofstream outputfile;
	outputfile.open ("g:\\A-large.out");
	if (outputfile.is_open()) {

		int tc,dc,dcc,tcc,fail,matches;
		for ( matches=0,tc=0; tc<testcases ; tc++,matches=0 ) {
			//cout << "begin case: " << testcase[tc] << endl;
			for ( dc=0; dc<dictlen; dc++ ) {
				//cout << " comparing with: " << dict[dc] << endl;
				for ( dcc=0,tcc=0,fail=0; dcc<wordlen && fail==0; dcc++,tcc++ ) {
					if ( testcase[tc][tcc] != '(' ) {
						//cout << "  single checking " << testcase[tc][tcc] << " against " << dict[dc][dcc] << endl;
						if ( testcase[tc][tcc] != dict[dc][dcc] ) fail=1;
					}
					else {
						for ( fail=1,tcc++; testcase[tc][tcc]!=')' ; tcc++ ){
							//cout << " multiple checking " << testcase[tc][tcc] << " against " << dict[dc][dcc] << endl;
							if ( testcase[tc][tcc] == dict[dc][dcc] ) fail=0;
						}
						//cout << "  multiple closing with fail=" << fail << endl;
					}
				}
				matches+=(1-fail);
				//cout << " found so far:" << matches << endl;
			}
			//cout << "found:" << matches << endl << endl;
			cout << "Case #" << (tc+1) << ": " << matches  << endl;
			outputfile << "Case #" << (tc+1) << ": " << matches  << endl;
		}
		outputfile.close();
	}
	else cout << "Error opening file for output" << endl;
	return 0;
}

int readfile()
{
	string inputline;
	ifstream inputfile;

	inputfile.open ("g:\\A-large.in");
	if (inputfile.is_open())
	{

		int i=0;
		wordlen=0;
		dictlen=0;
		testcases=0;
		getline (inputfile,inputline);

		for ( i=0; inputline[i] != ' ' && (int)(inputline[i])-48 >= 0 && (int)(inputline[i])-48 <= 9 && i<=10; i++ ) wordlen = 10*wordlen + ((int)(inputline[i])-48);
		for ( i++; inputline[i] != ' ' && (int)(inputline[i])-48 >= 0 && (int)(inputline[i])-48 <= 9 ; i++ ) dictlen = 10*dictlen + ((int)(inputline[i])-48);
		for ( i++; inputline[i] != ' ' && (int)(inputline[i])-48 >= 0 && (int)(inputline[i])-48 <= 9 ; i++ ) testcases = 10*testcases + ((int)(inputline[i])-48);

		for ( i=0; i < dictlen && !inputfile.eof(); i++ )
		{ getline (inputfile,inputline); dict[i] = inputline; }

		for ( i=0; i < testcases && !inputfile.eof(); i++ )
		{ getline (inputfile,inputline); testcase[i] = inputline; }

		inputfile.close();
	}
	else cout << "unable to open file";
	return (0);
}
