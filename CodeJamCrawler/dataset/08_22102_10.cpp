#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;


char str[10000] ;
bool visit[10000] ; 
int k , length , ans[10000] , Min ; 
int mid[10000] ;

void judge() ;
void run() ;

int main()
{
	freopen("D-small-attempt1.in","r",stdin);
	freopen("shark.out","w",stdout);
	int text , Case ; 
	while ( 1 == scanf("%d",&text ))
	{
		for(Case = 1 ; Case <= text ; Case ++)
		{
			scanf("%d%s",&k, str);
			memset(visit , false  , sizeof(visit)) ;
			length = 0 ; Min = -100000 ;
			run ();
			printf("Case #%d: %d\n",Case,Min);
		}
	}
	return 0;
}


void judge()
{
	int i  = 0  , j , sum , len = strlen(str) , Count = 0 ;
	while( i < len )
	{
		for( j = 0 ; j < length ; j ++)
			mid[i++] = str[ans[j]-1+Count];
		Count += k ;
	}
	sum = 0 ; i = 0 ; 
	while ( i < len )
	{
		j = i ;
		while(  j + 1 < len && mid[j] == mid[j+1])
			j ++ ;
		j ++ ;
		i = j ;
		sum ++ ;
	}
	if(Min == -100000 || sum < Min)
		Min = sum ;
}


void run()
{
	int i;
	if(length == k)
	{
		judge();
		return ;
	}
	for(i = 1 ; i <= k ; i ++)
	{
		if(visit[i])
			continue ;
		visit[i] = true ;
		ans[length ++] = i ;
		run();
		length -- ;
		visit[i] = false ;
	}
}