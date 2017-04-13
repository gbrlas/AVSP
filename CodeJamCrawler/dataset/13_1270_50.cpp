#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

char check1(char a[4][4])
{
	for (int i = 0; i < 4; i++) {
		char c = a[i][0];
		if (c == '.') {
			continue;
		}
		if (c == 'T') {
			c = a[i][1];
		}
		
		int j;
		for (j = 1; j < 4; j++) {
			if (a[i][j] != c && a[i][j] != 'T') {
				break;
			}
		}
		if (j == 4) {
			return c;
		}
	}
	return '1';
}

char check2(char a[4][4])
{
	for (int i = 0; i < 4; i++) {
		char c = a[0][i];
		if (c == '.') {
			continue;
		}
		if (c == 'T') {
			c = a[1][i];
		}
		int j;
		for (j = 1; j < 4; j++) {
			if (a[j][i] != c && a[j][i] != 'T') {
				break;
			}
		}
		if (j == 4) {
			return c;
		}
	}
	
	return '1';
}

char check3(char a[4][4])
{
	char c = a[0][0];
	int i;
	if (c == 'T')
		c = a[1][1];
	for (i = 1; i < 4; i++) {
		if (a[i][i] != c && a[i][i] != 'T') {
			break;
		}
	}
	if (i == 4 && c != '.') {
		return c;
	}
	
	c = a[0][3];
	if (c == '.') {
		return c;
	}
	if (c == 'T') {
		c = a[1][2];
	}
	
	for (i = 1; i < 4; i++) {
		if (a[i][3 - i] != c && a[i][3 - i] != 'T') {
			break;
		}
	}
	if (i == 4) {
		return c;
	}
	return '1';
}

int main()
{
	ofstream f("ab.txt");
	int t;
	scanf("%d", &t);
	getchar();
	int k = 0;
	while(t--) {
		char a[4][4];
		int flag = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				scanf("%c", &a[i][j]);
				if (a[i][j] == '.') {
					flag = 1;
				}
			
			}
			getchar();
		}
		getchar();
		char c;
		c = check1(a);

		if (c == 'X' || c == 'O') {
			printf("Case #%d: %c won\n", ++k, c);
			f << "Case #" << k << ": " << c << " won" << endl;
			continue;
		}
		
		c = check2(a);

		if (c == 'X' || c == 'O') {
			printf("Case #%d: %c won\n", ++k, c);
			f << "Case #" << k << ": " << c << " won" << endl;
			continue;	
		}
		
		c = check3(a);

		if (c == 'X' || c == 'O') {
			printf("Case #%d: %c won\n", ++k, c);
			f << "Case #" << k << ": " << c << " won" << endl;
			continue;
		}
		
		if (flag == 1) {
			printf("Case #%d: Game has not completed\n", ++k);
			f << "Case #" << k << ": " << "Game has not completed" << endl;
		} else {
				printf("Case #%d: Draw\n", ++k);	
				f << "Case #" << k << ": " << "Draw" << endl;		
		}
			
	}
}