#include "stdio.h"
#include <iostream>
#include <cmath>
using namespace std;

#define fr(a,b,c) for(a=(b); a<(c); ++a)
#define fo(a,c) fr((a),0,(c))
#define fo1(a,c) fr((a),1,(c))
#define fi(n) fo(i,(n))
#define fj(n) fo(j,(n))
#define fk(n) fo(k,(n))
#define fi1(n) fo1(i,(n))
#define fj1(n) fo1(j,(n))
#define fk1(n) fo1(k,(n))

#define ni(n) scanf("%d", &n)
#define nf(n) scanf("%f", &n)
#define nd(n) scanf("%lf", &n)
#define ns(n) scanf("%s", n)
#define nl(n) scanf("%ld", &n)
#define nll(n) scanf("%lld", &n)
#define nllu(n) scanf("%llu", &n)


int C, TC=1;
////////////////////////////////////
typedef unsigned long long ull;
int i,j,r,c;
char a[55][55];
////////////////////////////////////
int main()
{
	//freopen("C:\\Users\\root\\Desktop\\code\\temp\\gc\\Release\\B-small-practice.in", "r+", stdin);
	//freopen("C:\\Users\\root\\Desktop\\code\\temp\\gc\\Release\\B-small-practice.out", "w+", stdout);
	for (scanf ("%d", &C); TC <= C; TC++)
	{
		////////////////////////////////////
		printf("Case #%d:\n",TC);
		bool bImp = false;
		int rcount;
		memset(a,0,sizeof(a));
		cin>>r>>c;	
		fi(r)
		{
			scanf("%s",a[i]);
			rcount=0;
			fj(c)if(a[i][j]=='#')++rcount;
			if(rcount&1)
				bImp = true;
		}
		if(bImp)
		{
			printf("Impossible\n");
			continue;
		}

		fi(r-1)
		{
			fj(c-1)
			{
				if(a[i][j]=='#')
				{
					if( (a[i][j+1]=='#') && (a[i+1][j]=='#') && (a[i+1][j+1]=='#') )
					{
						a[i][j]=a[i+1][j+1]='/';
						a[i][j+1]=a[i+1][j]='\\';
					}
				}
			}
		}

		fi(r)
			printf("%s\n",a[i]);

		////////////////////////////////////
	}

	return 0;
}


