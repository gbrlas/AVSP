#include <stdio.h>
#include <algorithm>
using namespace std;
int T,NA,NB ;
struct Node
{
	int st,en ;
	int flag ;
}list[500];
int A[5000],B[5000] ;
bool Com(Node a,Node b)
{
	return a.st < b.st ;
}
void solve()
{
	int i,j;
	memset(A,0,sizeof(A));
	memset(B,0,sizeof(B));
	sort(&list[0],&list[NA+NB],Com);
	int CountA = 0 ;
	int CountB = 0 ;
	for(i = 0 ; i < NA+NB ; i ++)
	{
		if(list[i].flag == 1)
		{
			for(j = list[i].st ; j >= 0 ; j --)
			{
				if(A[j] > 0)
					break ;
			}
			if(j < 0)
			{
				CountA ++ ;
				B[list[i].en+T] ++ ;
			}
			else
			{
				A[j] -- ;
				B[list[i].en+T] ++ ;
			}
		}
		else
		{
			for(j = list[i].st ; j >= 0 ; j --)
			{
				if(B[j] > 0)
					break ;
			}
			if(j < 0)
			{
				CountB ++ ;
				A[list[i].en+T] ++ ;
			}
			else
			{
				B[j] -- ;
				A[list[i].en+T] ++ ;
			}
		}
	}
	printf("%d %d\n",CountA,CountB);
	return ;
}
int main()
{
	int Case ;
	int N ;
	int i;
	char st[200],en[200];
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	while(1 == scanf("%d",&N))
	{
		for(Case = 1 ; Case <= N ; Case ++)
		{
			scanf("%d %d %d",&T,&NA,&NB);
			for(i = 0 ; i < NA ; i ++)
			{
				scanf("%s %s",st,en);
				list[i].st = ((st[0]-'0')*10+st[1]-'0')*60+(st[3]-'0')*10+st[4]-'0';
				list[i].en = ((en[0]-'0')*10+en[1]-'0')*60+(en[3]-'0')*10+en[4]-'0';
				list[i].flag = 1 ;
			}
			for(i = NA ; i < NB+NA ; i ++)
			{
				scanf("%s %s",st,en);
				list[i].st = ((st[0]-'0')*10+st[1]-'0')*60+(st[3]-'0')*10+st[4]-'0';
				list[i].en = ((en[0]-'0')*10+en[1]-'0')*60+(en[3]-'0')*10+en[4]-'0';
				list[i].flag = 2 ;
			}
			printf("Case #%d: ",Case);
			solve();
		}
	}
	return 0;
}