#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

char a[6][6],ans,ch;
int T,tq,i,fl,j;

bool gx(int cc,char c){
	int i;
	for(i=1;i<=4;i++)if(a[cc][i]!=c&&a[cc][i]!='T')return false;
	return true;
}

bool gy(int cc,char c){
	int i;
	for(i=1;i<=4;i++)if(a[i][cc]!=c&&a[i][cc]!='T')return false;
	return true;
}

bool gd1(char c){
	int i;
	for(i=1;i<=4;i++)if(a[i][i]!=c&&a[i][i]!='T')return false;
	return true;
}

bool gd2(char c){
	int i;
	for(i=1;i<=4;i++)if(a[i][5-i]!=c&&a[i][5-i]!='T')return false;
	return true;
}

int main (int argc, char * const argv[]) {
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&T);
	for(tq=1;tq<=T;tq++){
		fl=0;
		for(i=1;i<=4;i++)for(j=1;j<=4;j++){
			ch=getchar();
			while(ch!='X'&&ch!='O'&&ch!='T'&&ch!='.')ch=getchar();
			a[i][j]=ch;
			if(ch=='.')fl=1;
		}
		ans='C';
		for(i=1;i<=4;i++){
			if(gx(i,'X'))ans='X';
			if(gx(i,'O'))ans='O';
			if(gy(i,'X'))ans='X';
			if(gy(i,'O'))ans='O';
		}
		if(gd1('X'))ans='X';
		if(gd1('O'))ans='O';
		if(gd2('X'))ans='X';
		if(gd2('O'))ans='O';
		printf("Case #%d: ",tq);
		if(ans=='C'){
			if(fl)puts("Game has not completed");
			if(!fl)puts("Draw");
		}
		if(ans=='X')puts("X won");
		if(ans=='O')puts("O won");
	}
    return 0;
}
