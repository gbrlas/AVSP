#include <iostream>
#include <cstring>

using namespace std;

string board[4];

int main(){
	int t; cin >> t;
	for (int zz = 1; zz <= t; zz++){
		for (int i = 0; i < 4; i++)
			cin >> board[i];
			
		bool comp = true;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				if (board[i][j] == '.')
					comp = false;
		
		//rows
		bool otot = false;
		bool xtot = false;
		
		for (int i = 0; i < 4; i++){
			bool owin = true;
			bool xwin = true;
			for (int j = 0; j < 4; j++){
				if (board[i][j] == 'O') xwin = false;
				else if (board[i][j] == 'X') owin = false;
				else if (board[i][j] == '.'){
					xwin = false;
					owin = false;
				}
			}
			otot = max(otot,owin);
			xtot = max(xtot,xwin);
		}
		
		//cols
		for (int j = 0; j < 4; j++){
			bool owin = true;
			bool xwin = true;
			for (int i = 0; i < 4; i++){
				if (board[i][j] == 'O') xwin = false;
				else if (board[i][j] == 'X') owin = false;
				else if (board[i][j] == '.'){
					xwin = false;
					owin = false;
				}
			}
			otot = max(otot,owin);
			xtot = max(xtot,xwin);
		}
		
		//diags
		bool owin = true;
		bool xwin = true;
		for (int i = 0; i < 4; i++){
			if (board[i][i] == 'O') xwin = false;
			else if (board[i][i] == 'X') owin = false;
			else if (board[i][i] == '.'){
				xwin = false;
				owin = false;
			}
		}
		otot = max(otot,owin);
		xtot = max(xtot,xwin);
		
		owin = true;
		xwin = true;
		for (int i = 0; i < 4; i++){
			if (board[i][3-i] == 'O') xwin = false;
			else if (board[i][3-i] == 'X') owin = false;
			else if (board[i][3-i] == '.'){
				xwin = false;
				owin = false;
			}
		}
		otot = max(otot,owin);
		xtot = max(xtot,xwin);
		
		cout << "Case #" << zz << ": ";
		if (otot) cout << "O won" << endl;
		else if (xtot) cout << "X won" << endl;
		else if (comp) cout << "Draw" << endl;
		else cout << "Game has not completed" << endl;
	}

	return 0;
}
