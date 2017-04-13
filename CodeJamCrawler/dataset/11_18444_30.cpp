#include "Utilities.h"


void GenSubsets( vector< vector<int> > &allSubsets, const vector<int> &oriSet )
{
	int i = 0;
	int max = 1 << oriSet.size();

	for ( i = 0; i != max; i++ )
	{
		int binNum = i, index = 0;
		vector< int > subset;
		
		while( binNum > 0 )
		{
			if ( (binNum & 1) > 0 )//Don't forget this
			{
				subset.push_back( oriSet[index] );
			}
			binNum >>= 1;
			index++;
		}

		if ( subset.empty() || subset.size() == oriSet.size() )
		{
			continue;
		}
/*
		for ( int j = 0; j != subset.size(); ++j )
		{
			cout<<subset[j]<<" ";
		}
		cout<<endl;
*/
		allSubsets.push_back( subset );
	}
}

void GenDiffSet( vector< int > &diffSet, const vector<int> &oriSet, const vector<int> &allSet )
{
	long unsigned i = 0;

	for ( i = 0; i != allSet.size(); ++i )
	{
		if ( find( oriSet.begin(), oriSet.end(), allSet[i] ) == oriSet.end() )
		{
			diffSet.push_back( allSet[i] );
		}
	}
}
long unsigned GenXorSum( const vector<int> &values )
{
	long unsigned i = 0;
	long unsigned sum = 0;
	
	for ( i = 0; i < values.size(); ++i )
	{
		sum ^= values[i];
	}
	return sum;
}
long unsigned GenPlusSum( const vector<int> &values )
{
	long unsigned i = 0;
	long unsigned sum = 0;
	
	for ( i = 0; i < values.size(); ++i )
	{
		sum += values[i];
	}
	return sum;
}
bool IniInputFile( vector< vector<int> > &cases, const string &fileInput )
{
	long unsigned i = 0, j = 0;
	vector<string> fls;
	if ( !ReadFileStream( fls, fileInput ) )
	{
		cout<<"ReadFileStream() error!"<<endl;
		return false;
	}

	for ( i = 2; i < fls.size(); ++i )
	{
		string str;
		vector<int> tmpCandies;

		istringstream inStr( fls[i] );
		while ( inStr >> str )
		{
			tmpCandies.push_back( atoi( str.c_str() ) );
		}
		cases.push_back( tmpCandies );
		++i;
	}
	return true;
}

bool CheckSplit( long unsigned &maxValue, const vector<int> &candies )
{
	long unsigned i = 0;
	long unsigned sum = 0;
	vector< vector<int> > allSubsets;
	
	sum = GenXorSum( candies );
	if ( sum != 0 )
	{
		return false;
	}
	
	if ( candies.size() == 2 )
	{
		maxValue = candies[0];
		return true;
	}
	GenSubsets( allSubsets, candies );

	maxValue = 0;
	for ( i = 0; i != allSubsets.size(); ++i )
	{
		vector< int > diffSet;

		GenDiffSet( diffSet, allSubsets[i], candies );

		if ( GenXorSum( diffSet ) == GenXorSum( allSubsets[i] ) )
		{
			long unsigned sumTmp = GenPlusSum( allSubsets[i] );
			if ( sumTmp > maxValue )
			{
				maxValue = sumTmp;
			}
		}
	}
	return true;
}

int main( int argc,char *argv[] )
{
//	int a[] = { 1,2,3,4,5,6 };
//	vector< vector<int> > allSubsets;
//	vector<int> oriSet(a, a + sizeof(a) / sizeof(int));
//	GenSubsets( allSubsets, oriSet );

	long unsigned i = 0;
	long unsigned maxValue;
	string fileInput = "C-small-attempt0.in";
	vector< vector<int> > cases;

	IniInputFile( cases, fileInput );

	ofstream oFp( "output.txt", ios::trunc );
	if ( !oFp )
	{
		return 0;
	}
	for ( i = 0; i != cases.size(); ++i )
	{
		if ( !CheckSplit( maxValue, cases[i] ) )
		{
			oFp<<"Case #"<<i+1<<": "<<"NO"<<endl;
		}
		else
		{
			oFp<<"Case #"<<i+1<<": "<<maxValue<<endl;
		}
	}
	oFp.close();
	return 1;
}
