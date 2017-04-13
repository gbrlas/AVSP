#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <assert.h>
#include <sstream>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find() != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define PI 3.1415926535
#define INF 9876543210

int main()
{
	//freopen("A-large.in","r",stdin);
	//freopen("A-large.out","w",stdout);
	int TC=0,i,j,k;
	scanf("%d",&TC);
	for(k=1;k<=TC;k++)
	{
		string str;
		char game[5][5];
		for(i=0;i<4;i++)
		{
			cin>>str;
			for(j=0;j<str.size();j++)
			{
				game[i][j]=str[j];
			}
		}
		char ch='Z';
		int ans=0;
		for(i=0;i<4;i++)
		{
			int flag=0;
			int x=0,o=0;
			for(j=0;j<4;j++)
			{
				if(game[i][j]=='T')
					flag++;
				if(game[i][j]=='X')
					x++;
				if(game[i][j]=='O')
					o++;
			}
			if((flag==1 && x==3) || x==4)
				{
					ch = 'X';
					ans = 1;
					break;
				}
			if((flag==1 && o==3) || o==4)
				{
					ch = 'O';
					ans = 1;
					break;
				}	
		}
		if(ans==1)
		{
			printf("Case #%d: %c won\n",k,ch);
			continue;
		}
		ch='Z';
		ans=0;
		for(j=0;j<4;j++)
		{
			int flag=0;
			int x=0,o=0;
			for(i=0;i<4;i++)
			{
				if(game[i][j]=='T')
					flag++;
				if(game[i][j]=='X')
					x++;
				if(game[i][j]=='O')
					o++;
			}
			if((flag==1 && x==3) || x==4)
				{
					ch = 'X';
					ans = 1;
					break;
				}
			if((flag==1 && o==3) || o==4)
				{
					ch = 'O';
					ans = 1;
					break;
				}	
		}
		if(ans==1)
		{
			printf("Case #%d: %c won\n",k,ch);
			continue;
		}
		int flag=0;
		int x=0,o=0;
		for(i=0;i<4;i++)
		{
				if(game[i][i]=='T')
					flag++;
				if(game[i][i]=='X')
					x++;
				if(game[i][i]=='O')
					o++;
		}
		if((flag==1 && x==3) || x==4)
			{
				ch = 'X';
				ans = 1;
			}
		if((flag==1 && o==3) || o==4)
			{
				ch = 'O';
				ans = 1;
			}	
		if(ans==1)
		{
			printf("Case #%d: %c won\n",k,ch);
			continue;
		}
		flag=0;
		x=0,o=0;	
		for(i=0,j=3;i<4 && j>=0;i++,j--)
		{
				if(game[i][j]=='T')
					flag++;
				if(game[i][j]=='X')
					x++;
				if(game[i][j]=='O')
					o++;
		}
		if((flag==1 && x==3) || x==4)
			{
				ch = 'X';
				ans = 1;
			}
		if((flag==1 && o==3) || o==4)
			{
				ch = 'O';
				ans = 1;
			}	
		if(ans==1)
		{
			printf("Case #%d: %c won\n",k,ch);
			continue;
		}
		ans = 0;
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				if(game[i][j]=='.')
					ans=1;
			}
		}
		if(ans==0)
			printf("Case #%d: Draw\n",k);
		else
			printf("Case #%d: Game has not completed\n",k);
		char nl;
		nl = getc(stdin);
		
	}
	return 0;
}