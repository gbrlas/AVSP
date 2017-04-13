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

const	int			maxlen	= 13;

char				data[maxlen];

int				t[maxlen] , len , n , ti , ans;

long long			answer;


void				init()
{
	ans = 0;
	scanf("%s\n" , data);
	len = strlen(data);
}
void				calc()
{
	long long		temp = 0;
	int			q;

	q = 1;
	answer = 0;
	temp = data[0] - '0';
	//for (int i = 0;i < len - 1;i++) printf("%d " ,t[i]);  printf("***\n");
	
	for (int i = 0;i < len - 1;i++)
	{
		if (t[i] == 0)
		{
			temp = temp * 10 + (data[i + 1] - '0');
		}
		if (t[i] == 1)
		{
			answer = answer + temp * q;
			q = 1;
			temp = data[i + 1] - '0';
		}
		if (t[i] == 2)
		{
			answer = answer + temp * q;
			q = -1;
			temp = data[i + 1] - '0';
		}
		//printf("%I64d\n" , temp );

	}
	
	answer = answer + temp * q;
	//printf("%I64d" , answer) ; printf("\n");
	if (answer % 2 == 0||answer % 3 == 0||answer % 5 == 0||answer % 7 == 0) ans ++;
}
void				dfs(int pos)
{
	if (pos == len - 1)
	{
		calc();
		return;
	}
	for(int i = 0;i < 3;i++)
	{
		t[pos] = i;
		dfs(pos + 1);
	}
}
void				work()
{
	dfs(0);
	//calc();
}
void				print()
{
	printf("Case #%d: %d\n" , ti , ans);
}
int				main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	for (scanf("%d\n" , &n) , ti =1;ti <= n;ti++)
	{
		init();
		work();
		print();
	}
}