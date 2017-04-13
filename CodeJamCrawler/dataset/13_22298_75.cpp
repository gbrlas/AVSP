#include <iostream>
#include <vector>
using namespace std;

int cs;
string s[4];

void transpose() {
	for(int i=0;i<4;i++)
		for(int j=i;j<4;j++) {
			swap(s[i][j],s[j][i]);
		}
			
}

bool XWin() {
	bool ok = false;
	for(int i=0;i<4;i++) ok |= s[i] == "XXXX" || s[i] == "XXXT" || s[i] == "XXTX" || s[i] == "XTXX" || s[i] == "TXXX";
	transpose();
	for(int i=0;i<4;i++) ok |= s[i] == "XXXX" || s[i] == "XXXT" || s[i] == "XXTX" || s[i] == "XTXX" || s[i] == "TXXX";
	transpose();

	string diag = "";
	for(int i=0;i<4;i++) diag += s[i][i];
	ok |= diag == "XXXX" || diag == "XXXT" || diag == "XXTX" || diag == "XTXX" || diag == "TXXX";

	diag = "";
	for(int i=0;i<4;i++) diag += s[i][3-i];
	ok |= diag == "XXXX" || diag == "XXXT" || diag == "XXTX" || diag == "XTXX" || diag == "TXXX";
	return ok;
}

bool OWin() {
	bool ok = false;
	for(int i=0;i<4;i++) ok |= s[i] == "OOOO" || s[i] == "OOOT" || s[i] == "OOTO" || s[i] == "OTOO" || s[i] == "TOOO";
	transpose();
	for(int i=0;i<4;i++) ok |= s[i] == "OOOO" || s[i] == "OOOT" || s[i] == "OOTO" || s[i] == "OTOO" || s[i] == "TOOO";
	transpose();

	string diag = "";
	for(int i=0;i<4;i++) diag += s[i][i];
	ok |= diag == "OOOO" || diag == "OOOT" || diag == "OOTO" || diag == "OTOO" || diag == "TOOO";

	diag = "";
	for(int i=0;i<4;i++) diag += s[i][3-i];
	ok |= diag == "OOOO" || diag == "OOOT" || diag == "OOTO" || diag == "OTOO" || diag == "TOOO";
	return ok;
}

string getAnswer() {
	if(XWin())return "X won";
	if(OWin())return "O won";
	bool filled = true;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			filled &= s[i][j] != '.';
	if(filled) return "Draw";
	return "Game has not completed";
}

int main() {

	int runs;
	scanf("%d" , &runs);
	while(runs-- > 0) {
		for(int i=0;i<4;i++) cin >> s[i];
		string ans  = getAnswer();
		printf("Case #%d: %s\n", ++cs, ans.c_str());
	}

	return 0;
}
