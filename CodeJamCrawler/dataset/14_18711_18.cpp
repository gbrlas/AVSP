#include "stdio.h"
#include "string.h"

#if 1

#undef SKC
#define IN_FILE	"IO/CJ14-1B-1.in"

#define P 		printf
#define N		100
#define L		100

char s[N][L+1], c[N][L+1];
int off[N], cnt[N][L+1];

int main(void)
{
	int t,tst;

	FILE* fin = stdin;
#ifdef SKC
	fin = fopen(IN_FILE,"r");
	if(fin == NULL)
	{
		printf("Cannot Open file %s\n", IN_FILE);
		return 0;
	}
#endif

	fscanf(fin, "%d", &tst);
	for(t=1 ; t<=tst ; ++t)
	{
		int i,j,res=0,n,k;

		fscanf(fin,"%d", &n);
		memset(c,0,sizeof(c[0])*n);
		memset(cnt,0,sizeof(cnt[0])*n);
		memset(off,0,sizeof(off[0])*n);

		P("Case #%d: ", t);

		for(i=0 ; i<n ; ++i)
		{
			fscanf(fin,"%s", s+i);
			c[i][0] = s[i][0];
			cnt[i][0] = 1;
			k=0;
			for(j=1 ; s[i][j] ; ++j)
			{
				if(c[i][k] == s[i][j])
					cnt[i][k]++;
				else
				{
					k++;
					c[i][k] = s[i][j];
					cnt[i][k] = 1;
				}
			}
			off[i] = k;
		}

		k = off[0];
		for(i=1 ; i<n ; ++i)
		{
			if(k != off[i])
				goto NO;
		}

		for(j=0 ; j<=k ; ++j)
		{
			char ch = c[0][j];
			for(i=1 ; i<n ; ++i)
			{
				if(ch != c[i][j])
					goto NO;
			}
		}

		for(j=0 ; j<=k ; ++j)
		{
			int ctr = cnt[0][j];
			for(i=1 ; i<n ; ++i)
				ctr += cnt[i][j];
			ctr = (ctr+n/2) / n;
			for(i=0 ; i<n ; ++i)
			{
				int val = ctr - cnt[i][j];
				if(val < 0)
					val = -val;
				res += val;
			}
		}


		P("%d\n",res);
		continue;
NO:
		P("Fegla Won\n");
	}

#ifdef SKC
	fclose(fin);
#endif

	return 0;
}

#endif
