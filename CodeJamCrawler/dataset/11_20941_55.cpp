#include "stdio.h"

struct Combination {
	char In1;
	char In2;
	char Out;
};

struct Opposition {
	char In1;
	char In2;
};

int main(int argc, char* argv[])
{
	int TestCases;
	scanf( "%d", &TestCases );

	for ( int Test = 0; Test < TestCases; ++Test )
	{
		// create list of combinations
		int NumCombos;
		scanf( "%d ", &NumCombos );
		struct Combination* Combos = new Combination[ NumCombos ];

		for ( int i = 0; i < NumCombos; ++i ) {
			scanf( "%c%c%c ", &Combos[ i ].In1, &Combos[ i ].In2, &Combos[ i ].Out );
		}

		// create list of oppositions
		int NumOppos;
		scanf( "%d ", &NumOppos );
		struct Opposition* Oppos = new Opposition[ NumOppos ];

		for ( int i = 0; i < NumOppos; ++i ) {
			scanf( "%c%c ", &Oppos[ i ].In1, &Oppos[ i ].In2 );
		}

		int InputLength;
		scanf( "%d ", &InputLength );

		char* ElementList = new char[ InputLength ];

		int ElementListLength = 0;

		// read input list
		for ( int i = 0; i < InputLength; ++i ) {
			char NewElement;
			scanf( "%c", &NewElement );

			bool ElementDone = false;

			// check for combination
			if ( ElementListLength > 0 ) {
				for ( int i = 0; i < NumCombos; ++i ) {
					if ( Combos[ i ].In1 == NewElement ) {
						if ( ElementList[ ElementListLength - 1 ] == Combos[ i ].In2 ) {
							ElementList[ ElementListLength - 1 ] = Combos[ i ].Out;
							ElementDone = true;
							break;
						}
					} else if ( Combos[ i ].In2 == NewElement ) {
						if ( ElementList[ ElementListLength - 1 ] == Combos[ i ].In1 ) {
							ElementList[ ElementListLength - 1 ] = Combos[ i ].Out;
							ElementDone = true;
							break;
						}
					}
				}
			}

			if ( ElementDone ) {
				continue;
			}

			// check for opposition
			if ( ElementListLength > 0 ) {
				for ( int i = 0; i < NumOppos; ++i ) {
					if ( Oppos[ i ].In1 == NewElement ) {
						for ( int j = 0; j < ElementListLength; ++j ) {
							if ( ElementList[ j ] == Oppos[ i ].In2 ) {
								ElementListLength = 0;
								ElementDone = true;
								break;
							}
						}
					} else if ( Oppos[ i ].In2 == NewElement ) {
						for ( int j = 0; j < ElementListLength; ++j ) {
							if ( ElementList[ j ] == Oppos[ i ].In1 ) {
								ElementListLength = 0;
								ElementDone = true;
								break;
							}
						}
					}
					if ( ElementDone ) {
						break;
					}
				}
			}
			
			if ( ElementDone ) {
				continue;
			}

			// add the element
			ElementList[ ElementListLength ] = NewElement;
			ElementListLength++;
		}

		// print the list
		printf( "Case #%d: [", Test + 1 );

		for ( int i = 0; i < ElementListLength; ++i ) {
			printf( "%c", ElementList[ i ] );

			if ( i < ( ElementListLength - 1 ) ) {
				printf( ", " );
			}
		}

		printf( "]\n" );

		// clean up
		delete[] Combos;
		delete[] Oppos;
		delete[] ElementList;
	}

	return 0;
}



