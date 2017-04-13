#include "Utilities.h"

typedef struct
{
	char robot;
	int button;

}Term;

bool IniInputFile( vector< vector<Term> > &seqs, const string &fileInput )
{
	long unsigned i = 0, j = 0;
	vector<string> fls;
	if ( !ReadFileStream( fls, fileInput ) )
	{
		cout<<"ReadFileStream() error!"<<endl;
		return false;
	}

	for ( i = 1; i < fls.size(); ++i )
	{
		string str;
		vector<Term> tmpSeq;

		istringstream inStr( fls[i] );
		inStr >> str;
		while ( inStr >> str )
		{
			Term tmpTerm;
			tmpTerm.robot = str[0];
			inStr >> str;
			tmpTerm.button = atoi(str.c_str());

			tmpSeq.push_back( tmpTerm );
		}
		seqs.push_back( tmpSeq );
	}
	return true;
}

long unsigned RobotsWalk( const vector<Term> &seqs )
{
	int oCurr = 0, bCurr = 0;
	int oPrevBt = 1, bPrevBt = 1;
	long unsigned int pCurr = 0;

	long unsigned i = 0;

	for ( i = 0; i < seqs.size(); ++i )
	{
		long unsigned move = 0, push = 0;

		if ( seqs[i].robot == 'O' )
		{
			move = oCurr + abs(seqs[i].button - oPrevBt) * 1;
			push = move > pCurr ? (move+1) : (pCurr+1);

			pCurr = push;
			oPrevBt = seqs[i].button;
			oCurr = push;
		}
		else 
		{
			move = bCurr + abs(seqs[i].button - bPrevBt) * 1;
			push = move > pCurr ? (move+1) : (pCurr+1);

			pCurr = push;
			bPrevBt = seqs[i].button;
			bCurr = push;
		}
	} 
	return pCurr;
}

int main( int argc,char *argv[] )
{
	long int i = 0;
	string fileInput = "A-small-attempt1.in";
	ofstream oFp("output.txt", ios::trunc);
	if ( !oFp )
	{
		return 0;
	}
	vector< vector<Term> > seqs;
	IniInputFile( seqs, fileInput );

	for ( i = 0 ; i != seqs.size(); ++i )
	{
		oFp<<"Case #"<<i+1<<": "<<RobotsWalk( seqs[i] )<<endl;
		cout<<"Case #"<<i+1<<": "<<RobotsWalk( seqs[i] )<<endl;
	}
	oFp.close();
	return 1;
}
