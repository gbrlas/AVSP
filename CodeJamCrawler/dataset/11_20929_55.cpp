#include "stdio.h"

struct Button {
	char Robot;
	int Location;
};

int main(int argc, char* argv[])
{
	int TestCases;
	scanf( "%d", &TestCases );

	for ( int Test = 0; Test < TestCases; ++Test )
	{
		int TotalButtons, ButtonsLeft;
		scanf( "%d", &TotalButtons );

		struct Button* Buttons = new struct Button[ TotalButtons + 1 ];
		Buttons[ TotalButtons ].Location = -1;
		Buttons[ TotalButtons ].Robot = '\0';

		for ( int i = 0; i < TotalButtons; ++i )
		{
			int Button;
			char Robot;
			scanf( " %c %d", &Robot, &Button );

			Buttons[ i ].Robot = Robot;
			Buttons[ i ].Location = Button;
		}

		int TotalMoves = 0;
		
		int Location[2] = { 1, 1 };
		int BotNextButtonIndex[2] = { 0, 0 };
		int NextButtonIndex = 0;
		
		while ( NextButtonIndex < TotalButtons ) 
		{
			while ( Buttons[ BotNextButtonIndex[ 0 ] ].Robot != 'O' && BotNextButtonIndex[ 0 ] < TotalButtons ) {
				++BotNextButtonIndex[ 0 ];
			}

			while ( Buttons[ BotNextButtonIndex[ 1 ] ].Robot != 'B' && BotNextButtonIndex[ 1 ] < TotalButtons ) {
				++BotNextButtonIndex[ 1 ];
			}

			bool ButtonPushed = false;
			for ( int i = 0; i < 2; ++i ) {
				struct Button* NextButton = &Buttons[ NextButtonIndex ];
				struct Button* BotNextButton = &Buttons[ BotNextButtonIndex[ i ] ];
				int BotLocation = Location[ i ];
				if ( NextButton == BotNextButton && BotLocation == NextButton->Location && !ButtonPushed ) {
					// I'm at the next button, push it!
					++NextButtonIndex;
					++BotNextButtonIndex[ i ];
					ButtonPushed = true;
				} else {
					// move toward the next button I want to push
					if ( BotLocation < BotNextButton->Location ) {
						++Location[ i ];
					} else if ( BotLocation > BotNextButton->Location && BotNextButton->Location > 0 ) {
						--Location[ i ];
					}
				}
			}
			++TotalMoves;
		}

		printf( "Case #%d: %d\n", Test + 1, TotalMoves );
	}

	return 0;
}

