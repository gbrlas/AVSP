#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string.h>
#include<string>
#include<algorithm>
#define fi(i,a,b) for (int i=a;i<=b;i++)
#define ms(a,b) memset(a,0,sizeof(b))
using namespace std;

int T,ans;
string s[10];
char g[10][10];

void init()
{
	scanf("\n");
	fi(i,1,4) getline(cin,s[i]);
	ms(g,0);
	fi(i,1,4) fi(j,1,4) g[i][j]=s[i][j-1];
}

bool judge(char ch)
{
	bool flag1,flag2;
	fi(i,1,4)
	{
		flag1=true;flag2=true;
		fi(j,1,4)
		{
			if (g[i][j]!=ch && g[i][j]!='T') flag1=false;
			if (g[j][i]!=ch && g[j][i]!='T') flag2=false;
		}
		if (flag1 || flag2) return true;
	}
	flag1=true;flag2=true;
	fi(i,1,4)
	{
		if (g[i][i]!=ch && g[i][i]!='T') flag1=false;
		if (g[i][5-i]!=ch && g[i][5-i]!='T') flag2=false;
	}
	if (flag1 || flag2) return true;
	return false;
}

int work()
{
//X
	if (judge('X')) return 1;
//O
	if (judge('O')) return 2;
//not completed
	fi(i,1,4) fi(j,1,4) if (g[i][j]=='.') return 3;
//draw
	return 4;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&T);
	fi(i,1,T)
	{
		init();
		int ans=work();
		printf("Case #%d: ",i);
		if (ans==1) printf("X won\n");
		else if (ans==2) printf("O won\n");
		else if (ans==3) printf("Game has not completed\n");
		else printf("Draw\n");
	}
	return 0;
}
