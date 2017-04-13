#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
#include<iomanip>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#include<memory.h>
#include<iomanip>
using namespace std;

typedef pair<int,int> ii;

int mas[1000][1000];
int vx[1000][1000], vy[1000][1000];
int m[1000][1000];

int main()
{
	int test_count;
	cin>>test_count;
	for(int test_num=0;test_num<test_count;test_num++)
	{
		int R,C,D;
		cin>>R>>C>>D;
		for(int i=0;i<R;i++)
		{
			string s;
			cin>>s;
			for(int j=0;j<C;j++)
			{
				mas[i+1][j+1]=s[j]-'0';
			}
		}
		for(int i=0;i<=R;i++)
			m[i][0]=vx[i][0]=vy[i][0]=0;
		for(int j=0;j<=C;j++)
			m[0][j]=vx[0][j]=vy[0][j]=0;
		for(int i=1;i<=R;i++)
			for(int j=1;j<=C;j++)
			{
				vx[i][j]=vx[i][j-1]+vx[i-1][j]-vx[i-1][j-1]+mas[i][j]*i;
				vy[i][j]=vy[i][j-1]+vy[i-1][j]-vy[i-1][j-1]+mas[i][j]*j;
				m[i][j]=m[i][j-1]+m[i-1][j]-m[i-1][j-1]+mas[i][j];
			}

		int l = min(R,C);
		bool ok = false;
		for(;l>=3;l--)
		{
			for(int i=1;i<=R-l+1;i++)
				for(int j=1;j<=C-l+1;j++)
				{
					int VX = vx[i+l-1][j+l-1]-vx[i+l-1][j-1]-vx[i-1][j+l-1]+vx[i-1][j-1];
					int VY = vy[i+l-1][j+l-1]-vy[i+l-1][j-1]-vy[i-1][j+l-1]+vy[i-1][j-1];
					
					VX-=(mas[i+l-1][j+l-1]+mas[i+l-1][j])*(i+l-1) +
						(mas[i][j+l-1]+mas[i][j])*(i);
					VY-=(mas[i+l-1][j+l-1]+mas[i][j+l-1])*(j+l-1) +
						(mas[i+l-1][j]+mas[i][j])*(j);

					int M = m[i+l-1][j+l-1]-m[i+l-1][j-1]-m[i-1][j+l-1]+m[i-1][j-1];
					
					M-=mas[i+l-1][j+l-1]+mas[i+l-1][j]+mas[i][j+l-1]+mas[i][j];
					
					if ((2*VX == M*(2*i+l-1)) && (2*VY == M*(2*j+l-1)))
					{
						ok = true;
					}
				}
			if (ok) break;
		}
		if (ok)
			printf("Case #%d: %d\n",test_num+1,l);
		else
			printf("Case #%d: IMPOSSIBLE\n",test_num+1);
	}
	return 0;
}