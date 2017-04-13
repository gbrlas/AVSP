/* fAnSKyer */
/* 11-02-2010 */
/* replace DT lattice*/
/* Useage: */
/* Directory E:\FeatureProcessor */


#pragma warning (disable:4786) 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int s[10][10];
int o1=0,w1=0,draw=0;;
void check()
{
	int i,j,flag,sum;

	//ij
	for(i=0;i<4;i++)
	{
		sum=0;
		for(j=0;j<4;j++)
		{
			if (s[i][j]==0) {sum=-1; break;} 
			sum+=s[i][j];
		}
		if (sum==103 || sum==4) o1=1;
		if (sum==106 || sum==8) w1=1;
	}

	//ji
	for(i=0;i<4;i++)
	{
		sum=0;
		for(j=0;j<4;j++)
		{
			if (s[j][i]==0) {sum=-1; break;} 
			sum+=s[j][i];
		}
		if (sum==103 || sum==4) o1=1;
		if (sum==106 || sum==8) w1=1;
	}

	//ii
	sum=0;
	for(j=0;j<4;j++)
	{
		if (s[j][j]==0) {sum=-1; break;} 
		sum+=s[j][j];
	}
	if (sum==103 || sum==4) o1=1;
	if (sum==106 || sum==8) w1=1;

	sum=0;
	for(j=0;j<4;j++)
	{
		if (s[j][3-j]==0) {sum=-1; break;} 
		sum+=s[j][3-j];
	}
	if (sum==103 || sum==4) o1=1;
	if (sum==106 || sum==8) w1=1;


//"X won" (the game is over, and X won)
//"O won" (the game is over, and O won)
//"Draw" (the game is over, and it ended in a draw)
//"Game has not completed" (the game is not over yet)

	if (o1==1 && w1==0) {printf("O won\n"); return;}
	if (o1==0 && w1==1) {printf("X won\n"); return;}
	if (draw==1) {printf("Game has not completed\n"); return;}
	printf("Draw\n");
}
int main(int argc,char* argv[])
{
	char name[500],ch[500];	
	int i,j,v,cnt=0,n,t;

	/* read the dictionary */
	freopen("A-small-attempt0.in","r",stdin);
	scanf("%d",&n);
	gets(ch);

	for(t=0;t<n;t++)
	{
		o1=0,w1=0,draw=0;
		for(i=0;i<4;i++)
		{
			gets(ch);
			for(j=0;j<4;j++)
			{
				if (ch[j]=='O') v = 1; //o1
				if (ch[j]=='X') v = 2; //w2
				if (ch[j]=='T') v = 100;
				if (ch[j]=='.') {v = 0; draw=1;}
				s[i][j]=v;
			}
		}
		gets(ch);
		printf("Case #%d: ",t+1);
		check();
	}
}
