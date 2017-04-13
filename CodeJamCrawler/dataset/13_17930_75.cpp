//============================================================================
// Name        : 2013QualificationA.cpp
// Author      : gnarlycow
//============================================================================

#include <iostream>
#include <string>

using namespace std;

string s[4];

bool checkRow(int r, char player) {
	for(int c=0;c<4;++c)
		if(s[r][c]!=player && s[r][c]!='T')
			return false;
	return true;
}

bool checkCol(int c, char player) {
	for(int r=0;r<4;++r)
		if(s[r][c]!=player && s[r][c]!='T')
			return false;
	return true;
}

bool checkDia1(char player) {
	for(int i=0;i<4;++i)
		if(s[i][i]!=player && s[i][i]!='T')
			return false;
	return true;
}

bool checkDia2(char player) {
	for(int i=0;i<4;++i)
		if(s[i][3-i]!=player && s[i][3-i]!='T')
			return false;
	return true;
}

bool checkDia(char player) {
	return checkDia1(player) || checkDia2(player);
}

string getResult() {
	for(int r=0;r<4;++r) {
		if(checkRow(r,'X')) return "X won";
		if(checkRow(r,'O')) return "O won";
	}
	for(int c=0;c<4;++c) {
		if(checkCol(c,'X')) return "X won";
		if(checkCol(c,'O')) return "O won";
	}
	if(checkDia('X')) return "X won";
	if(checkDia('O')) return "O won";
	for(int i=0;i<4;++i)
		for(int j=0;j<4;++j)
			if(s[i][j]=='.')
				return "Game has not completed";
	return "Draw";
}

int main() {
	int ncases;
	cin>>ncases;
	for(int cid=1;cid<=ncases;++cid) {
		for(int i=0;i<4;++i) cin>>s[i];
		cout<<"Case #"<<cid<<": "<<getResult()<<endl;
	}
	return 0;
}
