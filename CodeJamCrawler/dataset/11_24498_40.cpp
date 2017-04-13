#include <iostream>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <iomanip>
#include <bitset>
#include <ctime>
#include <climits>
using namespace std;

#define maxn 55

int row,col;
char rec[maxn][maxn];

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small.out","w",stdout);
	int i,j;
	int test,cases;
	scanf("%d",&test);
	char tmpc;
	for (cases = 1;cases<=test; cases++)
	{
		memset(rec,0,sizeof(rec));
		printf("Case #%d:\n",cases);
		scanf("%d %d",&row,&col);
		getchar();
		for (i=0;i<row;i++)
		{
			gets(rec[i]);
		}
		bool flag = 0;
		int cnt = 1;
		for (i=0;i<row;i++)
		{
			for (j =0;j<col;j++)
			{
				if ('#'==rec[i][j])
				{
					if (rec[i][j+1]!='#'||rec[i+1][j]!='#'||rec[i+1][j+1]!='#')
					{
						flag = 1;
						goto label1;
					}
					rec[i][j] = '//';
					rec[i][j+1] = '\\';
					rec[i+1][j] = '\\';
					rec[i+1][j+1] = '//';
				}
			}
		}
label1:
		if (flag)
		{
			printf("Impossible\n");
		} 
		else
		{
			for (i=0;i<row;i++)
			{
				for (j =0;j<col;j++)
				{
					printf("%c",rec[i][j]);
				}
				printf("\n");
			}
		}
	}
}