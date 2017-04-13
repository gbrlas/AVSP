#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

typedef unsigned int uint;

int main (int argc, char * const argv[]) 
{
	if ( argc != 2 )
	{
		cerr << "USAGE: " << argv[0] << " <inputFile>." << endl;
		return -1;
	}
	
	ifstream fileIn(argv[1]);
	if ( !fileIn )
	{
		cerr << "Error: Could not open file " << argv[0] << "for read.\n";
		return -1;
	}
	
	// Get # cases.
	uint numCases = 0;
	fileIn >> numCases;
	if ( !fileIn )
	{
		cerr << "Error: Could not read # cases.\n";
		return -1;
	}
	
	const uint MAX_ENGINES = 100;
	const uint MAX_ENGINE_NAME_LEN = 100;
	char engineNames[MAX_ENGINES][MAX_ENGINE_NAME_LEN + 1];
	char queryString[MAX_ENGINE_NAME_LEN + 1];
	bool seenFlags[MAX_ENGINES];
	uint numEngines = 0;
	uint numQueries = 0;
	uint numSwitches = 0;
	uint numSeenFlagsSet = 0;
	
	for ( uint caseIndex = 0; caseIndex < numCases; caseIndex++ )
	{	// Process each case.
		fileIn >> numEngines;
		fileIn.getline(queryString, MAX_ENGINE_NAME_LEN);	// skip newline.
		
		for ( uint engineIndex = 0; engineIndex < numEngines; engineIndex++ )
		{
			fileIn.getline(engineNames[engineIndex], MAX_ENGINE_NAME_LEN);
		}

/*
		for ( uint i = 0; i < engineNames.size(); i++ )
		{	
			cout << engineNames[i] << endl;
		}
 */
		
		fileIn >> numQueries;
		fileIn.getline(queryString, MAX_ENGINE_NAME_LEN);	// skip newline.
		
		// As each query is read. Mark that engine's seen flag.
		// When all engines have their flags set, that is when we must
		// switch (to something other than that last engine).
		// At that point, clear all the flags except for that last guy and repeat.
		numSwitches = 0;
		numSeenFlagsSet = 0;
		memset(seenFlags, 0, sizeof(bool) * MAX_ENGINES);
		
		for ( uint queryIndex = 0; queryIndex < numQueries; queryIndex++ )
		{
			fileIn.getline(queryString, MAX_ENGINE_NAME_LEN);
			for ( uint engineIndex = 0; engineIndex < numEngines; engineIndex++ )
			{
				if ( seenFlags[engineIndex] == false )
				{
					if ( strcmp(queryString, engineNames[engineIndex]) == 0 )
					{
						seenFlags[engineIndex] = true;
						numSeenFlagsSet++;
						
						if ( numSeenFlagsSet >= numEngines )
						{	// Hit all the engines. Need to switch.
							numSwitches++;
							numSeenFlagsSet = 1;
							memset(seenFlags, 0, sizeof(bool) * MAX_ENGINES);
							seenFlags[engineIndex] = true;
						}
						
						break;
					}
				}
			}
		}
		
		cout << "Case #" << caseIndex + 1 << ": " << numSwitches << endl;
		
	}
	

	fileIn.close();
	
    return 0;
}
