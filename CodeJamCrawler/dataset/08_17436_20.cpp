#include<stdio.h>
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<functional>
#include<queue>
#include<set>
#include<map>
using namespace std;
#define fo(i,n) for(i=0;i<(n);++i) 
#define CL(a,b) memset(a,b,sizeof(a))
#define inf 1<<30
typedef vector<int> vi ; 
typedef vector<string> vs ;
typedef _int64 ll;



//FILE *in = fopen("b.in","r");
//FILE *in = fopen("B-large-attempt0.in","r");
FILE *in = fopen("B-small-attempt0.in","r");
FILE *out= fopen("b.out","w");

ll area(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
	return( (x1*y2 - y1*x2 + y1*x3 
		- x1*y3 + x2*y3 - x3*y2) / 2.0 );
}



int main()
{
	ll z,tests,ret=0,x2,y2,x3,y3,x1,y1,n,m,flag,a,cur;
	fscanf(in,"%I64d",&tests);


	fo(z,tests)
	{
		fprintf(out,"Case #%I64d: ",z+1);
		fscanf(in,"%I64d%I64d%I64d",&n,&m,&a);
		printf("%d\n",z);

		x1=0;
		flag=1;

		fo(x2,n+1) fo(x3,n+1) fo(y1,m+1) fo(y3,m+1)
		{
			cur=-y1*x2+y1*x3+x2*y3;
			y2=cur-a;

			if(y2>=0 && x3!=0 && y2%x3==0 && (y2/x3)<=m)
			{
				flag=0;
				y2/=x3;
				fprintf(out,"%I64d %I64d %I64d %I64d %I64d %I64d\n",x1,y1,x2,y2,x3,y3); 
				//if(area(x1,y1,x2,y2,x3,y3)==a || area(x1,y1,x2,y2,x3,y3)==-a) 
				//	printf("good\n");
				goto g;
			}

			y2=cur+a;

			if(y2>=0 && x3!=0 && y2%x3==0 && (y2/x3)<=m)
			{
				flag=0;
				y2/=x3;
				fprintf(out,"%I64d %I64d %I64d %I64d %I64d %I64d\n",x1,y1,x2,y2,x3,y3); 
				//if(area(x1,y1,x2,y2,x3,y3)==a || area(x1,y1,x2,y2,x3,y3)==-a) 
				//	printf("good\n");
				goto g;
			}
		}		

g:		if(flag)
			fprintf(out,"%IMPOSSIBLE\n");		
	}

	return 0;
}

