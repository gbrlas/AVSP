/*
Author          : MaShuo
Data            : 
*/

#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

const	int			maxn	= 20;
const	int			maxs	= 100 + 10;
const	int			maxq	= 1000 + 10;
const	int			oo	= 5000;

int				n , s , q , t , answer;
string				data1[maxs] , data2[maxq];
int				f[maxs][maxq];

void				init()
{
	int			i;
	answer = oo;
	memset(f , -1 , sizeof(f));
	scanf("%d\n" , &s);
	for (i = 0;i < s;i++) getline(cin , data1[i]);
}
int				min(int a , int b)
{
	return a < b ? a : b;
}
void				calc(int u , int v)
{
	int			i;
	f[u][v] = oo;
	if (data1[u] == data2[v]) return;
	if (v == 0)
	{
		f[u][v] = 0;
		return;
	}
	for (i = 0;i < s;i++)
	{
		if (f[i][v-1] == -1) calc(i , v - 1);
		if (i == u) f[u][v] = min(f[u][v] , f[i][v - 1]); else f[u][v] = min(f[u][v] , f[i][v - 1] + 1);
	}
}
void				work()
{
	int			i;
	scanf("%d\n" , &q);
	if (q == 0) 
	{
		answer = 0;
		return;
	}
	for (i = 0;i < q;i++) getline(cin , data2[i]);
	for (i = 0;i < s;i++)
	{
		calc(i , q - 1);
		answer = min(answer , f[i][q - 1]);
	}
}
void				print()
{
	printf("Case #%d: %d\n" , t , answer);
}
int				main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	for(scanf("%d\n" , &n) , t = 1;t <= n;t++)
	{
		init();
		work();
		print();
	}
}