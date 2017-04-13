#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("A-large.in");
	ofstream fout("out.txt");
	int t; fin >> t;
	char b[4][4];
	for(int c = 1; c <= t; c++)
	{
		fout << "Case #" << c << ": ";
		char p;//fin >> p;
		bool empty = false;
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				fin >> p; b[i][j] = p;
				if(p == '.') empty = true;
			}
			//fin >> p;
		}
		bool xw = false, ow = false;
		for(int i = 0; i < 4; i++){
			bool xe = false, oe = false;
			for(int j = 0; j < 4; j++)
				if(b[i][j] == '.') { oe = xe = true; break;}
				else if(b[i][j] == 'X') { oe = true; if(xe) break; }
				else if(b[i][j] == 'O') { xe = true; if(oe) break; }
			if(!oe && xe) { ow = true; }
			else if(!xe && oe) { xw = true; } 
			else if(!xe && !oe) { xw = ow = true; }
		}
		//if(xw) {fout << "X won" << endl; continue;}
		//if(ow) {fout << "O won" << endl; continue;}
		for(int j = 0; j < 4; j++){
			bool xe = false, oe = false;
			for(int i = 0; i < 4; i++)
				if(b[i][j] == '.') { oe = xe = true; break;}
				else if(b[i][j] == 'X') { oe = true; if(xe) break; }
				else if(b[i][j] == 'O') { xe = true; if(oe) break; }
			if(!oe && xe) { ow = true; }
			else if(!xe && oe) { xw = true; } 
			else if(!xe && !oe) { xw = ow = true; }
		}
		//if(xw) {fout << "X won" << endl; continue;}
		//if(ow) {fout << "O won" << endl; continue;}
		bool xe = false, oe = false;
		for(int i = 0; i < 4; i++)
			if(b[i][i] == '.') { oe = xe = true; break;}
			else if(b[i][i] == 'X') { oe = true; if(xe) break; }
			else if(b[i][i] == 'O') { xe = true; if(oe) break; }
		if(!oe && xe) { ow = true; }
		else if(!xe && oe) { xw = true; }
		else if(!xe && !oe) { xw = ow = true; }
		xe = false, oe = false;
		for(int i = 0; i < 4; i++)
			if(b[i][3-i] == '.') { oe = xe = true; break;}
			else if(b[i][3-i] == 'X') { oe = true; if(xe) break; }
			else if(b[i][3-i] == 'O') { xe = true; if(oe) break; }
		if(!oe && xe) { ow = true; }
		else if(!xe && oe) { xw = true; }
		else if(!xe && !oe) { xw = ow = true; }
		if(xw && !ow) {fout << "X won" << endl; continue;}
		if(ow && !xw) {fout << "O won" << endl; continue;}
		if(empty && !xw && !ow) fout << "Game has not completed" << endl;
		else fout << "Draw" << endl;
	}
	fin.close();
	fout.close();
	return 0;
}