#include <iostream>
#include <vector>

using namespace std;

enum res
{
	X,
	O,
	Nul,
	Nend
};

res test(char m[4][4])
{
	res r = Nul;
	int o = 0;
	int x = 0;
	int t = 0;
	for (int i = 0; i < 4; i++) {
		switch(m[i][i]) {
			case 'X' :
				x++;
				break;
			case 'O' :
				o++;
				break;
			case 'T' :
				t++;
				break;
		}
	}

	if ( x == 4 || (x == 3 && t == 1))
		return X;
	if ( o == 4 || (o == 3 && t == 1))
		return O;

	x=0;
	t=0;
	o=0;

	for (int i = 0; i < 4; i++) {
		switch(m[i][3-i]) {
			case 'X' :
				x++;
				break;
			case 'O' :
				o++;
				break;
			case 'T' :
				t++;
				break;
		}
	}

	if ( x == 4 || (x == 3 && t == 1))
		return X;
	if ( o == 4 || (o == 3 && t == 1))
		return O;

	for (int i = 0; i < 4; i++) {
		x = 0;
		o = 0;
		t = 0;
		for (int j = 0; j < 4; j++) {
			if ( m[i][j] == '.')
				r = Nend;
			switch(m[i][j]) {
				case 'X' :
					x++;
					break;
				case 'O' :
					o++;
					break;
				case 'T' :
					t++;
					break;
			}
		}

		if ( x == 4 || (x == 3 && t == 1))
			return X;
		if ( o == 4 || (o == 3 && t == 1))
			return O;
	}

	for (int i = 0; i < 4; i++) {
		x = 0;
		o = 0;
		t = 0;
		for (int j = 0; j < 4; j++) {
			switch(m[j][i]) {
				case 'X' :
					x++;
					break;
				case 'O' :
					o++;
					break;
				case 'T' :
					t++;
					break;
			}
		}

		if ( x == 4 || (x == 3 && t == 1))
			return X;
		if ( o == 4 || (o == 3 && t == 1))
			return O;
	}

	return r;
}

int main()
{
	int T;
	cin >> T;
	for(int c = 1; c <= T; c++) {
		char m[4][4];
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				cin >> m[i][j];
		res r = test(m);
		cout << "Case #" << c << ": ";
		switch(r) {
			case X :
				cout << "X won";
				break;
			case O :
				cout << "O won";
				break;
			case Nul :
				cout << "Draw";
				break;
			case Nend :
				cout << "Game has not completed";
				break;
		}
		cout << endl;
	}
}
