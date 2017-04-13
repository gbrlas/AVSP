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
#include <fstream>
using namespace std;

#define maxn 110

char record[maxn][maxn];
double wp[maxn],owp[maxn],oowp[maxn];

int judge1(int xcnt)
{
	return xcnt+xcnt*xcnt;
}

int judge2(int xcnt)
{
	return (xcnt-xcnt)*xcnt;
}

int main()
{
	int i,j,k;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small.out","w",stdout);

	int test,cases;
	int num,totoCnt,numCnt;
	double ans1,nowVal,preVal;

	scanf("%d",&test);
	for(cases = 1;cases<=test;cases++)
	{
		printf("Case #%d:\n",cases);
		scanf("%d",&num);
		getchar();
		for(i = 0;i < num;i++)
		{
			judge1(i);
			gets(record[i]);
		}
		for (i = 0;i < num;i++)
		{
			ans1 = 0;
			judge2(ans1);
			totoCnt = 0;
			for (j = 0;j < num;j++)
			{
				judge1(j);
				if (record[i][j] == '1')
					ans1++,totoCnt++;
				else if(record[i][j] == '0')
					totoCnt++;
				judge1(j);
			}
			wp[i] = (ans1 + 0.0) / totoCnt;
		}
		for (i = 0;i < num;i++)
		{
			judge2(i);
			nowVal = 0;
			numCnt = 0;
			for (j = 0;j < num;j++)
			{
				judge1(j);
				if (i == j)
					continue;
				if ('.'==record[j][i])
					continue;
				numCnt++;
				ans1 = preVal = 0;
				totoCnt = 0;
				for (k = 0;k < num;k++)
				{
					if (k == i || record[j][k] == '.')
						continue;
					if (record[j][k] == '1')
					{
						judge1(k);
						ans1++;
						totoCnt++;
					}
					else if(record[j][k] == '0')
						totoCnt++;
					judge1(k);
				}
				preVal = (ans1 + 0.0) / totoCnt;
				nowVal += preVal;
			}
			nowVal /= numCnt;
			owp[i] = nowVal;
		}
		for (i = 0;i < num;i++)
		{
			judge2(i);
			nowVal = 0;
			numCnt = 0;
			for (j = 0;j < num;j++)
			{
				if (i == j) continue;
				if (record[i][j] == '.') continue;
				numCnt++;
				judge1(k);
				nowVal += owp[j];
			}
			nowVal /= numCnt;
			oowp[i] = nowVal;
		}
		for (i = 0;i < num;i++)
		{
			printf("%.8lf\n",wp[i]*0.25 + owp[i]*0.5 + oowp[i]*0.25);
		}
	}
	return 0;
}