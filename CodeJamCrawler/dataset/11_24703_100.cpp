#include <cstdio>
#include <cstdlib>
#include <cstring>

int oppose[50][50] ;
int react[50][50] ;
int has[50] ;
int stack[110] ;
int top ;

int conflict(void)
{
	int i, j ;
	
	for(i=0;i<50;i++)
	{
		for(j=i+1;j<50;j++)
		{
			if(has[i]>0&&has[j]>0&&oppose[i][j]==1)
			{
				return 1 ;
			}
		}
	}
	
	return 0 ;
}

void invoke(int id)
{
	int tmp ;

	stack[top++] = id ;
	has[id]++ ;
	
	while(top>1)
	{
		if(react[stack[top-1]][stack[top-2]]!=-1)
		{
			tmp = react[stack[top-1]][stack[top-2]] ;
			has[stack[top-1]]-- ;
			has[stack[top-2]]-- ;
			top-- ;
			top-- ;
			stack[top++] = tmp ;
			has[tmp]++ ;
		}
		else
		{
			break ;
		}
	}
	
	if(conflict()==1)
	{
		memset(has,0,sizeof(has)) ;
		top = 0 ;
	}
}

void calc(int turn)
{
	int i ;
	int n ;
	int f ;
	char str[110] ;

	memset(oppose,0,sizeof(oppose)) ;
	memset(react,0xff,sizeof(react)) ;

	scanf("%d",&n) ;
	for(i=0;i<n;i++)
	{
		scanf("%s",str) ;
		react[str[0]-'A'][str[1]-'A'] = react[str[1]-'A'][str[0]-'A'] = str[2]-'A' ;
	}
	
	scanf("%d",&n) ;
	for(i=0;i<n;i++)
	{
		scanf("%s",str) ;
		oppose[str[0]-'A'][str[1]-'A'] = oppose[str[1]-'A'][str[0]-'A'] = 1 ;
	}
	
	scanf("%d",&n) ;
	scanf("%s",str) ;
	top = 0 ;
	memset(has,0,sizeof(has)) ;
	for(i=0;i<n;i++)
	{
		invoke(str[i]-'A') ;
	}
	
	printf("Case #%d: [",turn) ;
	f = 1 ;
	for(i=0;i<top;i++)
	{
		if(f==1)
		{
			f = 0 ;
		}
		else
		{
			printf(", ") ;
		}
		printf("%c",stack[i]+'A') ;
	}
	printf("]\n") ;
}

int main(void)
{
	int i, t ;

	scanf("%d",&t) ;

	for(i=1;i<=t;i++)
	{
		calc(i) ;
	}

	return 0 ;
}
