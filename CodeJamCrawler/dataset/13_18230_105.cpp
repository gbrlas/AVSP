#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <ctype.h>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <iostream>

using namespace std;

typedef pair<int,int> ii;

#define INF 0x3f3f3f3f
#define ll long long

char mat[5][5];

int win(char ch) {
	int cnt;
	for (int i=0; i<4; i++) {
		cnt = 0;
		for (int j=0; j<4; j++)
			if (mat[i][j] == ch || mat[i][j] == 'T') cnt++;
		if (cnt == 4) return 1;
	}
	
	for (int j=0; j<4; j++) {
		cnt = 0;
		for (int i=0; i<4; i++)
			if (mat[i][j] == ch || mat[i][j] == 'T') cnt++;
		if (cnt == 4) return 1;
	}
	
	cnt = 0;
	for (int i=0,j=0; i<4; i++,j++)
		if (mat[i][j] == ch || mat[i][j] == 'T') cnt++;
	if (cnt == 4) return 1;
	
	cnt = 0;
	for (int i=3,j=0; i>=0; i--,j++)
		if (mat[i][j] == ch || mat[i][j] == 'T') cnt++;
	if (cnt == 4) return 1;
	return 0;
}

int main() {
	int nt,nteste=1,flag;
	cin>>nt;
	while (nt--) {
		for (int i=0; i<4; i++)
			cin>>mat[i];
			
		flag = 1;
		for (int i=0; i<4; i++)
			for (int j=0; j<4; j++)
				if (mat[i][j] == '.') {
					flag = 0;	break;
				}
			
		cout << "Case #" << nteste++ << ": ";
		if (win('X')) cout << "X won" << endl;
		else if (win('O')) cout << "O won" << endl;
		else {
			cout << (flag ? "Draw" : "Game has not completed") << endl;
		}
	}
	
	return 0;
}
