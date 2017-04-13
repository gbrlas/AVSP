// r1b1.cpp : Defines the entry point for the console application.
//
#include "stdio.h"
#include <iostream>


int main(int argc, char* argv[])
{
	int TestCases;
	std::cin >> TestCases;

	for ( int Test = 0; Test < TestCases; ++Test )
	{
		int NumTeams;
		scanf( "%d\n", &NumTeams );
		double* Wins = new double[ NumTeams ];
		double* WinPct = new double[ NumTeams ];
		double* MyOppWinPct = new double[ NumTeams ];
		double** OppWinOffset = new double*[NumTeams];
		double** OppWinPct = new double*[NumTeams];
	
		int** Opponents = new int*[NumTeams];
		int* NumGames = new int[NumTeams];
		for ( int Team = 0; Team < NumTeams; ++Team )
		{
			Wins[ Team ] = 0;
			WinPct[ Team ] = 0;
			NumGames[Team] = 0;
			OppWinOffset[ Team ] = new double[ NumTeams ];
			Opponents[ Team ] = new int[ NumTeams ];
			for ( int Game = 0; Game < NumTeams; ++Game )
			{
				char inChar;
				scanf( "%c", &inChar );

				if ( inChar == '.' ) {
					OppWinOffset[Team][ Game ] = 0;
				} else if ( inChar == '1' ) {
					++Wins[ Team ];
					Opponents[Team][ NumGames[Team] ] = Game;
					OppWinOffset[ Team ][ NumGames[Team] ] = -1;
					++NumGames[Team];
				} else if ( inChar == '0' ) {
					Opponents[Team][ NumGames[Team] ] = Game;
					OppWinOffset[ Team ][ NumGames[Team] ] = 0;
					++NumGames[Team];
				}
			}
			if ( Team < NumTeams - 1 ) {
				scanf("\n");
			}
			WinPct[ Team ] = Wins[ Team ] / NumGames[ Team ];
		}

		for ( int Team = 0; Team < NumTeams; ++Team )
		{
			OppWinPct[ Team ] = new double[ NumTeams ];
			for ( int Game = 0; Game < NumGames[ Team ]; ++Game )
			{
				OppWinPct[ Team ][ Game ] = ( Wins[ Team ] + OppWinOffset[ Team ][ Game ] ) / ( NumGames[Team] - 1 );
			}
		}

		for ( int Team = 0; Team < NumTeams; ++Team )
		{
			MyOppWinPct[ Team ] = 0;
			for ( int Game = 0; Game < NumGames[ Team ]; ++Game )
			{
				int i = 0;
				for ( ; i < NumGames[ Opponents[ Team ][ Game ] ]; ++i ) {
					if ( Opponents[ Opponents[ Team ][ Game ] ][ i ] == Team ) {
						break;
					}
				}
				MyOppWinPct[Team] += OppWinPct[ Opponents[ Team ][ Game ] ][ i ];
			}
			MyOppWinPct[Team] /= NumGames[Team];
		}

		printf( "Case #%d:\n", Test + 1 );
		for ( int Team = 0; Team < NumTeams; ++Team )
		{
			double MyOppOppWinPct = 0;
			for ( int Game = 0; Game < NumGames[ Team ]; ++Game )
			{
				MyOppOppWinPct += MyOppWinPct[ Opponents[ Team ][ Game ] ];
			}
			MyOppOppWinPct /= NumGames[ Team ];

			double RPI = ( 0.25 * WinPct[ Team ] ) + ( 0.5 * MyOppWinPct[ Team ] ) + ( 0.25 * MyOppOppWinPct );
			printf( "%.15f\n", RPI );
		}
		printf( "\n" );
	}

	return 0;
}


