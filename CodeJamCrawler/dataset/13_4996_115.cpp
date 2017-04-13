#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int w(string s){
	int x=0, o=0;
	for(int i=0; i<4; ++i){
		x += (s[i]=='X' || s[i]=='T');
		o += (s[i]=='O' || s[i]=='T');
	}
	if(x==4) return 1;
	if(o==4) return 2;
	return 0;
}

int main(){
	int cases;
	cin >> cases;
	
	for(int q=1; q<=cases; ++q){
		cout << "Case #" << q << ": ";
		
		string s[4];
		for(int i=0; i<4; ++i) cin >> s[i];
		
		int dots=0;
		for(int i=0; i<4; ++i) for(int j=0; j<4; ++j) dots += (s[i][j]=='.');
		int win=0;
		
		string tr[4];
		for(int i=0; i<4; ++i) for(int j=0; j<4; ++j) tr[j] += s[i][j];
		
		
		for(int i=0; i<4; ++i){
			win = max(win, w(s[i]));
			win = max(win, w(tr[i]));
		}
		
		win = max(win, w(string() + s[0][0] + s[1][1] + s[2][2] + s[3][3]));
		win = max(win, w(string() + s[0][3] + s[1][2] + s[2][1] + s[3][0]));
		
		if(win == 1) cout << "X won";
		else if(win == 2) cout << "O won";
		else if(dots == 0) cout << "Draw";
		else cout << "Game has not completed";
		cout << '\n';
	}
	return 0;
}
