#include <cstdio>
#include <cstdlib>
#include <cstring>

int map[410][410] ;
int n ;
int ans ;
int used[410] ;

typedef struct
{
	int con[410] ;
	int step ;
	int id ;
} record ;

record rec[410000] ;
int top, rear ;

int cnt(int *str)
{
	int i ;
	int out = 0 ;
	
	for(i=1;i<n;i++)
	{
		if(str[i])
		{
			out++ ;
		}
	}
	
	return out ;
}

void sol(long long tc)
{
	int w, i, a, b, ans1, ans2 ;
	record r, next ;
	int id ;
	
	memset(map,0,sizeof(map)) ;
	memset(used,0,sizeof(used)) ;
	
	scanf("%d%d",&n,&w) ;
	for(i=0;i<w;i++)
	{
		scanf("%d,%d",&a,&b) ;
		map[a][b] = map[b][a] = 1 ;
	}
	
	top = rear = 0 ;
	
	memset(r.con,0,sizeof(r.con)) ;
	r.step = 0 ;
	r.id = 0 ;
	r.con[0] = 1 ;
	for(i=0;i<n;i++)
	{
		if(map[0][i]==1)
		{
			r.con[i] = 1 ;
		}
	}
	used[0] = 1 ;
	used[1] = 1 ;
	
	rec[top++] = r ;
	ans = -1 ;
	
	while(top!=rear&&(rec[rear].step<=ans||ans==-1))
	{
		r = rec[rear] ;
		rear++ ;
		id = r.id ;
		used[id] = 1 ;
		if(map[id][1]==1)
		{
			if(ans==-1)
			{
				ans2 = cnt(r.con) ;
				ans = ans1 = r.step ;
			}
			else
			{
				if(cnt(r.con)>ans2)
				{
					ans2 = cnt(r.con) ;
				}
			}
		}
		
		for(i=0;i<n;i++)
		{
			if(used[i]==0&&map[id][i]==1)
			{
				next.step = r.step+1 ;
				next.id = i ;
				for(int j=0;j<n;j++)
				{
					if(r.con[j]==1||map[i][j]==1)
					{
						next.con[j] = 1 ;
					}
					else
					{
						next.con[j] = 0 ;
					}
				}
				rec[top++] = next ;
			}
		}
	}
	
	printf("Case #%I64d: %d %d\n",tc,ans1, ans2-ans1) ;
}

int main(void)
{
	long long i, t ;

	scanf("%I64d",&t) ;

	for(i=1;i<=t;i++)
	{
		sol(i) ;
		fprintf(stderr,"%I64d\n",i) ;
	}

	return 0 ;
}
