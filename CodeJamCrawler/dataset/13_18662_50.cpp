#include <iostream>
#include <string>

using namespace std;

int getResult (int test) {
	string s[4];
	for (int i = 0; i < 4; i++) {
		cin>>s[i];
	}

	cout << "Case #"<<test<<": ";
	int x = 0, o = 0;
	bool t = false;
	for (int i = 0; i < 4; i++) {
		if (s[i][i] == 'X') x++;
		if (s[i][i] == 'O') o++;
		if (s[i][i] == 'T') t = true;
	}
	
	if ( (t==true && x==3) || x==4) {
		cout<<"X won"<<endl;
		return 0;
	}
	else if ( (t==true && o==3) || o==4) {
		cout<<"O won"<<endl;
		return 0;
	}
	
	x = 0;
	o = 0;
	t = false;
	
	for (int i = 0; i < 4; i++) {
		if (s[i][3-i] == 'X') x++;
		if (s[i][3-i] == 'O') o++;
		if (s[i][3-i] == 'T') t = true;
	}
	
	if ( (t==true && x==3) || x==4) {
		cout<<"X won"<<endl;
		return 0;
	}
	else if ( (t==true && o==3) || o==4) {
		cout<<"O won"<<endl;
		return 0;
	}
	
	bool dots = false;
	for (int i = 0; i < 4; i++) {
		x = 0; o = 0;
		t = false;
		for (int j = 0; j < 4; j++) {
			if (s[i][j] == 'X') x++;
			if (s[i][j] == 'O') o++;
			if (s[i][j] == 'T') t = true;
			if (s[i][j] == '.') dots = true;
		}
		if ( (t==true && x==3) || x==4) {
			cout<<"X won"<<endl;
			return 0;
		}
		else if ( (t==true && o==3) || o==4) {
			cout<<"O won"<<endl;
			return 0;
		}
		
		x = 0;
		o = 0;
		t = false;
		for (int j = 0; j < 4; j++) {
			if (s[j][i] == 'X') x++;
			if (s[j][i] == 'O') o++;
			if (s[j][i] == 'T') t = true;
			if (s[j][i] == '.') dots = true;
		}
		if ( (t==true && x==3) || x==4) {
			cout<<"X won"<<endl;
			return 0;
		}
		else if ( (t==true && o==3) || o==4) {
			cout<<"O won"<<endl;
			return 0;
		}
	}
	
	
	if (dots == true) {
		cout<<"Game has not completed"<<endl;
		return 0;
	}
	else {
		cout<<"Draw"<<endl;
		return 0;
	}
	
	return 0;
}
		
int main () {
	int test;
	cin>>test;
	
	string str;
	for (int i = 1; i <= test; i++) {
		getResult(i);
		getline(cin,str);
	}
	
	return 0;
}
		
