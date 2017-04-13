#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char a[10][10];

int doit(){
	bool fnsh = true;
	for (int i=1; i<=4; i++)
		for (int j=1; j<=4; j++)
		if ( a[i][j]=='.' ) fnsh = false;

	for (int i=1; i<=4; i++){
		int x=0, y=0, z=0;
		for (int j=1; j<=4; j++)
		if ( a[i][j]=='X' )
			x++;else
		if ( a[i][j]=='O' )
			y++;else
		if ( a[i][j]=='T' )
			z++;
		if ( x==4 || x==3 && z==1 ) return 1;
		if ( y==4 || y==3 && z==1 ) return -1;
	}

	for (int j=1; j<=4; j++){
		int x=0, y=0, z=0;
		for (int i=1; i<=4; i++)
		if ( a[i][j]=='X' )
			x++;else
		if ( a[i][j]=='O' )
			y++;else
		if ( a[i][j]=='T' )
			z++;
		if ( x==4 || x==3 && z==1 ) return 1;
		if ( y==4 || y==3 && z==1 ) return -1;
	}

	int x=0, y=0, z=0;
	for (int i=1; i<=4; i++)
	if ( a[i][i]=='X' )
		x++;else
	if ( a[i][i]=='O' )
		y++;else
	if ( a[i][i]=='T' )
		z++;
	if ( x==4 || x==3 && z==1 ) return 1;
	if ( y==4 || y==3 && z==1 ) return -1;

	 x=0, y=0, z=0;
	for (int i=1; i<=4; i++)
	if ( a[i][4-i+1]=='X' )
		x++;else
	if ( a[i][4-i+1]=='O' )
		y++;else
	if ( a[i][4-i+1]=='T' )
		z++;

	if ( x==4 || x==3 && z==1 ) return 1;
	if ( y==4 || y==3 && z==1 ) return -1;

	if ( fnsh ) return 0;
	return 2;
}

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);
	int T, CASE=0;
	for(scanf("%d", &T);T--;){
		printf("Case #%d: ", ++CASE);
		for (int i=1; i<=4; i++){
			for (int j=1; j<=4; j++){
				char ch;
				do{ scanf("%c",&ch); }while ( !(ch=='X'||ch=='T'||ch=='O'||ch=='.') );
				a[i][j] = ch;
			}
		}
		int ret = doit();
		if ( ret==1 )
			printf(" X won\n");else
		if ( ret==-1 )
			printf(" O won\n");else
		if ( ret==0 )
			printf(" Draw\n");else
		if ( ret==2 )
			printf(" Game has not completed\n");
	}
	return 0;
}
