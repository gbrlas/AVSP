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

const	int			maxn	= 100;
const	int			maxp	= 1000;
const	int			maxk	= 1000;
const	int			maxl	= 1000;


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
	int			poi = 0;
	sort(data , data + l);
	for (int i = 1;i <= k;i++) rec[i] = 1;
	for (int i = l - 1;i >= 0;i--)
	{
		poi = nxt(poi);
		answer += rec[poi] * data[i];
		rec[poi]++;
	}
}
void				print()
{
	printf("Case #%d: %lld\n" , ti , answer);
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