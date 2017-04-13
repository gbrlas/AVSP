#include <cstdio>
#include <cstdlib>
#include <cstring>

int n ;
char dic[11000][20] ;
char dis[11000][30] ;
char vc[30] ;
int len[11000] ;
int ans ;
char good[11000] ;
char set[30] ;
int pos[11000] ;

int diff(int id1, int id2, int c)
{
	char ch = c+'a' ;
	int i ;
	
	if(dis[id1][c]!=dis[id2][c])
	{
		return 1 ;
	}
	
	for(i=0;i<len[id1];i++)
	{
		if((dic[id1][i]==ch&&dic[id2][i]!=ch)||(dic[id1][i]!=ch&&dic[id2][i]==ch))
		{
			return 1 ;
		}
	}

	return 0 ;
}

int calc(int id)
{
	int i, j, k ;
	int p = 0, poscnt = 0 ;
	
	memset(vc,0,sizeof(vc)) ;
	
	for(i=0;i<n;i++)
	{
		if(len[i]==len[id])
		{
			for(j=0;j<26;j++)
			{
				vc[j] += dis[i][j] ;
			}
			pos[i] = 1 ;
			poscnt++ ;
		}
		else
		{
			pos[i] = 0 ;
		}
	}
	
	for(i=0;i<26&&poscnt>1;i++)
	{
		if(vc[set[i]-'a']==0)
		{
			continue ;
		}
		if(dis[id][set[i]-'a']==0)
		{
			p++ ;
		}
		for(j=0;j<n;j++)
		{
			if(pos[j]==1&&j!=id&&diff(id,j,set[i]-'a')==1)
			{
				pos[j] = 0 ;
				poscnt-- ;
				for(k=0;k<26;k++)
				{
					vc[k] -= dis[j][k] ;
				}
			}
		}
	}
	
	return p ;
}

void test(void)
{
	int id ;
	int ansid = -1 ;
	int ansv ;
	int tmp ;

	scanf("%s",set) ;
	for(id=0;id<n;id++)
	{
		tmp = calc(id) ;
		if(tmp>ansv||ansid==-1)
		{
			ansv = tmp ;
			ansid = id ;
		}
	}
	
	printf(" %s",dic[ansid]) ;
}

void sol(int tc)
{
	int i, j ;
	int m ;
	
	memset(dis,0,sizeof(dis)) ;
	
	scanf("%d%d",&n,&m) ;
	
	for(i=0;i<n;i++)
	{
		scanf("%s",dic[i]) ;
		len[i] = strlen(dic[i]) ;
		for(j=0;j<len[i];j++)
		{
			dis[i][dic[i][j]-'a'] = 1 ;
		}
	}
	
	printf("Case #%d:",tc) ;

	for(i=0;i<m;i++)
	{
		test() ;
	}
	
	printf("\n") ;
}

int main(void)
{
	int i, t ;
	
	scanf("%d",&t) ;
	
	for(i=1;i<=t;i++)
	{
		sol(i) ;
	}

	return 0 ;
}
