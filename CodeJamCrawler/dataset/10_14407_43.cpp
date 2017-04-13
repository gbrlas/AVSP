#include <iostream>
#include <string.h>

using namespace std;

int g[2000];
int d[1000005][2];
unsigned long long re[2000][2];
unsigned long long sum;
int tmp,t,r,k,n,ren;
bool visit[2000];

int main()
{
	int si,i,j;
	freopen("C-small-attempt0.in","r",stdin);
	freopen("answer.txt","w",stdout);
	cin >> t;
	for ( si = 1; si <= t; ++ si)
	{
		cin >> r >> k >> n;
		memset(visit,0,sizeof(visit));
		for ( i = 0; i < n; ++ i)
		{
			scanf("%d",&g[i]);
		}
		for ( i = 0; i < n; ++ i)
		{
			tmp = 0;
			j = i;
			while (tmp + g[j]<= k)
			{			
				tmp = tmp + g[j];
				++ j;				
				if (j == n)
				{
					j = 0;
				}
				if (j == i) break;			
			}
			d[i][0] = tmp;
			d[i][1] = j;
//			cout << d[i][0] << " " << d[i][1] << endl;
		}
//		cout << "ok" << endl;
		ren = 1;
		re[0][0] = 0;
		re[0][1] = 0;
		re[ren][0] = d[0][0];
		re[ren][1] = d[0][1];
		visit[0] = 1;
//		cout << re[ren][0] << " " << re[ren][1] << endl;
		while (!visit[re[ren][1]])
		{
			visit[re[ren][1]] = 1;
			++ ren;
			tmp = re[ren - 1][1];
			re[ren][0] =(unsigned long long)re[ren - 1][0] + d[tmp][0];
			re[ren][1] = d[tmp][1];
//			cout << re[ren][0] << " " << re[ren][1] << endl;
		}
		for ( i = 0; i < ren; ++ i)
		{
			if (re[ren][1] == re[i][1])
				break;
		}
//		cout << i << endl;
		if (ren >= r)
		{
			cout << "Case #" << si << ": " << re[r][0] << endl;
		}
		else
		{
			r = r - i;
			sum =(unsigned long long)re[i][0];
			sum =(unsigned long long) sum + (unsigned long long)r / (ren - i) * (re[ren][0] - re[i][0]);
			tmp = r % (ren - i);
			sum =(unsigned long long)sum + re[tmp + i][0] - re[i][0];
			cout << "Case #" << si << ": " << sum << endl;
		}
	}
		
		
			
	return 0;
	
}
