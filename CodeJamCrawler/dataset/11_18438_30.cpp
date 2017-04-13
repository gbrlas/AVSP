#include "Utilities.h"

void TruncateStr( string &str )
{
	unsigned long int nStr;
	
	for ( nStr = 0; nStr < str.length(); nStr++ )
	{
		if ( str[nStr] == 0x0A || str[nStr] == 0x0D )
		{
			str.erase( str.begin() + nStr, str.end() );
			break;
		}
	}
}	///*
bool ReadFileStream( vector<string> &fls, const string &file )
{
	string str, sline;
	fls.clear();
	
	ifstream infile( file.c_str() ); 
	if ( !infile )
	{
		cout<<file<<" dose not exist!"<<endl;
		return false;
	}

	while ( getline( infile, sline ) )
    {
    	str = sline;
    	TruncateStr( str );
    	fls.push_back( str );
    }
    
	if ( fls.size() == 0 )
	{
		cout<<"FileLines.size() == 0 in "<<file<<endl;
		return false;
	}

	return true;
}	
//*/
