#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

string solve();

int main() {
	int num_cases;
	cin >> num_cases;

	for( int case_num=0; case_num<num_cases; ++case_num ) {
		cout << "Case #" << (case_num+1) << ": " << solve() << endl;
	}

	return 0;
}

string solve() {
	char field[4][4];
	for( int i=0; i<4; ++i ) {
		string row;
		cin >> row;
		for( int j=0; j<4; ++j ) {
			field[i][j] = row[j];
		}
	}

	bool foundEmpty;
	for( int i=0; i<4; ++i ) {
		int foundOHor = 0, foundXHor = 0, foundOVer = 0, foundXVer = 0, foundODia = 0, foundXDia = 0;
		for( int j=0; j<4; ++j ) {
			if( field[i][j] == '.' )
				foundEmpty = true;

			switch( field[i][j] ) {
			case 'X':
				++foundXHor;
				break;
			case 'O':
				++foundOHor;
				break;
			case 'T':
				++foundXHor;
				++foundOHor;
				break;
			}

			switch( field[j][i] ) {
			case 'X':
				++foundXVer;
				break;
			case 'O':
				++foundOVer;
				break;
			case 'T':
				++foundXVer;
				++foundOVer;
				break;
			}

			switch( field[j][(i%2)==0?j:3-j] ) {
			case 'X':
				++foundXDia;
				break;
			case 'O':
				++foundODia;
				break;
			case 'T':
				++foundXDia;
				++foundODia;
				break;
			}
		}

		//cout << "Hor: " << foundXHor << " " << foundOHor << endl << "Ver: " << foundXVer << " " << foundOVer << endl << "Dia: " << foundXDia << " " << foundODia << endl << endl;

		if( foundXHor == 4 || foundXVer == 4 || foundXDia == 4) {
			return "X won";
		} else if( foundOHor == 4 || foundOVer == 4 || foundODia == 4 ) {
			return "O won";
		}
	}

	if( foundEmpty )
		return "Game has not completed";
	else
		return "Draw";
}
