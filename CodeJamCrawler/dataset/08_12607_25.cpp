/*
Author          : MaShuo
Data            : 
*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const	int			maxn	= 100 + 10;
const	int			maxp	= 1000+ 10;
const	int			maxk	= 1000+ 10;
const	int			maxl	= 1000+ 10;


int				n , p , k , l , data[maxl] , rec[maxk] , ti;

long long			answer;

void				init()
{
	answer = 0;
	scanf("%d %d %d" , &p , &k , &l);
	for (int i = 0;i < l;i++) scanf("%d" , &data[i]);
}
int				nxt(int w)
{
	if (w == k) return 1 ; else return w + 1;
}

void				work()
{
	long long		temp;
	int			poi = 0;
	sort(data , data + l);
	for (int i = 1;i <= k;i++) rec[i] = 1;
	for (int i = l - 1;i >= 0;i--)
	{
		poi = nxt(poi);
		temp = (long long)rec[poi];
		temp = (long long)temp * data[i]; 
		answer = (long long)answer + temp;
		rec[poi]++;
	}
}
void				print()
{
	printf("Case #%d: %I64d\n" , ti , answer);
}
int				main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	for (scanf("%d" , &n) , ti = 1;ti <= n;ti++)
	{
		init();
		work();
		print();
	}
}