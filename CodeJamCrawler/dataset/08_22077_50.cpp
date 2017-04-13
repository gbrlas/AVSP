#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std ;
struct O
{
	int start ;
	bool operator < (const O &a) const
	{
		return a.start < start;
	}
};
O temp;

struct Node
{
	int start , end ;
	
};
Node nodeA[1000] , nodeB[1000];
priority_queue<O> line[2] , haha;
bool useA[1000] , useB[1000] ; 
bool cmp(Node a , Node b)
{
	return a.start < b.start ;
}

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("BB.out","w",stdout);
	int text , Case ;
	while ( 1 == scanf("%d",&text))
	{
		for ( Case = 0 ; Case < text ; Case++)
		{
			int A , B , i , j , T ; 
			char Time[10] ;
			scanf("%d",&T);
			scanf("%d%d",&A, &B);
			line[0] = haha ;
			line[1] = haha ;
			for ( i = 0 ; i < A ; i ++)
			{
				scanf("%s",Time) ; 
				int a , b ;
				a = b = 0 ;
				nodeA[i].start = 0 ;
				for ( j = 0 ; j < 2 ; j ++)
					a = a * 10 + Time[j] - '0' ;
				for ( j = 3 ; j < 5 ; j ++)
					b = b * 10 + Time[j] - '0' ;
				nodeA[i].start = a * 60 + b ;
				a = b = 0 ;
				scanf("%s",Time) ;
				nodeA[i].end = 0;
				for ( j = 0 ; j < 2 ; j ++)
					a = a * 10 + Time[j] - '0' ;
				for ( j = 3 ; j < 5 ; j ++)
					b = b * 10 + Time[j] - '0' ;
				nodeA[i].end = a * 60 + b ;
				temp.start  = nodeA[i].end + T ;
				line[1].push(temp) ;
			}
			for ( i = 0 ; i < B ; i ++)
			{
				scanf("%s",Time) ; 
				int a , b ;
				a = b = 0 ;
				nodeB[i].start = 0 ;
				for ( j = 0 ; j < 2 ; j ++)
					a = a * 10 + Time[j] - '0' ;
				for ( j = 3 ; j < 5 ; j ++)
					b = b * 10 + Time[j] - '0' ;
				nodeB[i].start = a * 60 + b ;
				a = b = 0 ;
				scanf("%s",Time) ;
				nodeB[i].end = 0;
				for ( j = 0 ; j < 2 ; j ++)
					a = a * 10 + Time[j] - '0' ;
				for ( j = 3 ; j < 5 ; j ++)
					b = b * 10 + Time[j] - '0' ;
				nodeB[i].end = a * 60 + b ;
				temp.start = nodeB[i].end + T ;
				line[0].push(temp );
			}
			sort(&nodeA[0] , &nodeA[A] ,cmp) ;
			sort(&nodeB[0] , &nodeB[B] ,cmp) ;
			int ans[2] ; ans[0] = ans[1] = 0;
			for ( i = 0 ; i < A ; i ++)
			{
				if(!line[0].empty() && line[0].top().start <= nodeA[i].start)
					line[0].pop();
				else 
					ans[0] ++ ;
			}
			for ( i = 0 ; i < B ; i ++)
			{
				if(!line[1].empty() && line[1].top().start <= nodeB[i].start)
					line[1].pop();
				else 
					ans[1] ++ ;
			}
			printf("Case #%d: %d %d\n",Case+1 , ans[0] , ans[1]);
		}
	}
	return 0 ;
}