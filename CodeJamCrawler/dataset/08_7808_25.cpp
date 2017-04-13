#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "engine.h"

using namespace std;

unsigned int saveUniverse( fstream& );
bool compareEngines( const Engine*, const Engine* );
void clearEOL( fstream& );

int main( const int argc, const char* argv[] )
{
	//if the file name is passed on the command line, open that one, else defaults to input.txt
	string inputFileName( "input.txt" );
	if( argc >= 2 )
	{
		inputFileName = argv[1];
	}

	//open the input file
	fstream file( inputFileName.c_str(), ios_base::in );
	if( !file )
	{
		cout << "Failed to open the file: " << inputFileName;
		return 1;
	}

	//read the number of cases
	unsigned int nCases( 0 );
	file >> nCases;

	//run each case
	for( unsigned int i = 0; i < nCases; i++ )
	{
		cout << "Case #" << i + 1 << ": " << saveUniverse( file ) << endl;
	}

	return 0;
}

unsigned int saveUniverse( fstream& file )
{
	//read the number of engines
	unsigned int nEngines( 0 );
	file >> nEngines;
	clearEOL( file );

	//get the name of each engine
	vector<Engine*> engines;
	map<string,Engine*> engineMap;
	for( unsigned int i = 0; i < nEngines; i++ )
	{
		char name[101];
		file.getline( name, 100 );
		Engine* e = new Engine( name );
		engines.push_back( e );
		engineMap.insert( make_pair<string,Engine*>( string( name ), e ) );
	}

	//get the number of queries
	unsigned int nQueries( 0 );
	file >> nQueries;
	clearEOL( file );

	//read in all the queries
	//just store the location where the serach engine appears in the query list
	for( unsigned int i = 0; i < nQueries; i++ )
	{
		char query[101];
		file.getline( query, 100 );
		engineMap.find( string( query ) )->second->addQuery( i );
	}

	//figure out how many times we must switch
	unsigned int nSwitches( 0 );
	unsigned int queryIndex( 0 );
	while( queryIndex < nQueries )
	{
		//find the engine with the greatest query appearance and increment to that query index
		sort( engines.begin(), engines.end(), compareEngines );
		queryIndex = (*engines.begin())->nextAppearance() - 1;
		for( unsigned int i = 0; i < engines.size(); i++ )
			engines.at( i )->clearAppearancesBefore( queryIndex );

		nSwitches++;
	}

	//an extra switch was counted, if there were any queries
	if( nSwitches > 0 )
		nSwitches--;

	//clean up
	for( unsigned int i = 0; i < engines.size(); i++ )
	{
		delete engines.at( i );
	}

	return nSwitches;
}

bool compareEngines( const Engine* e1, const Engine* e2 )
{
	return e1->nextAppearance() > e2->nextAppearance();
}

void clearEOL( fstream& file )
{
	char trash[4];
	file.getline( trash, 4 );
}