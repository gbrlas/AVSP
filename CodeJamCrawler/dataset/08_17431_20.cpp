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
#define inf 1<<25
typedef vector<int> vi ; 
typedef vector<string> vs ;
typedef _int64 ll;

class node
{
public:

};

//FILE *in = fopen("a.in","r");
FILE *in = fopen("A-large.in","r");
//FILE *in = fopen("A-small-attempt1.in","r");
FILE *out= fopen("a.out","w");

int aa[10000];
int typ[10000];
int best[10000][2];
int n,m,x;

int solve(int turn, int v)
{
	if(turn==7 && v==1)
		printf("");

	int &ret=best[turn][v];
	if(ret!=-1) return ret;
	ret=inf;
	int a,b,c,d,cur,i=turn;



	if(turn>x)
	{
		if(v==aa[turn])
			return ret=0;
		return ret=inf;
	}

	a=solve(turn*2,1);
	b=solve(turn*2,0);
	c=solve(turn*2+1,1);
	d=solve(turn*2+1,0);

	if(v==1)
	{
		cur= aa[i]==1 ? 0:1;
		if(typ[i]==0 && cur!=0) cur=inf;
		cur+=a+c;
		if(cur<ret) ret=cur;

		cur= aa[i]==0 ? 0:1;
		if(typ[i]==0 && cur!=0) cur=inf;
		cur+= a<c ? a:c;
		if(cur<ret) ret=cur;
	}

	else
	{
		cur= aa[i]==1 ? 0:1;
		if(typ[i]==0 && cur!=0) cur=inf;
		cur+= b<d ? b:d;
		if(cur<ret) ret=cur;

		cur= aa[i]==0 ? 0:1;
		if(typ[i]==0 && cur!=0) cur=inf;
		cur+= b+d;
		if(cur<ret) ret=cur;
	}

	return ret;
}


int main()
{
	int i,z,tests,ret=0,v;
	fscanf(in,"%d",&tests);

	fo(z,tests)
	{
		fprintf(out,"Case #%d: ",z+1);

		fscanf(in,"%d%d",&n,&v);
		
		x=(n-1)/2;
		CL(best,-1);

		fo(i,n)
		{
			if(i+1<=x)
				fscanf(in,"%d%d",&aa[i+1],&typ[i+1]);
			else
				fscanf(in,"%d",&aa[i+1]);
		}

		/*fo(i,n)
		{
			if(i+1<=x)
				printf("%d %d\n",aa[i],typ[i]);
			else
				printf("%d\n",aa[i]);
		}*/

		ret=solve(1,v);

		if(ret<inf) 
			fprintf(out,"%d\n",ret);
		else
			fprintf(out,"IMPOSSIBLE\n");

		//printf("done\n");
	}

	return 0;
}

