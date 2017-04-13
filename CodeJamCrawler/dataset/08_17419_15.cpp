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

class node
{
public:

};

//FILE *in = fopen("A-small.in","r");
//FILE *in = fopen("A-large.in","r");
FILE *in = fopen("A-small-attempt0.in","r");
FILE *out= fopen("a.out","w");

string readline()
{
	char ch;
	string ret;

	while(fscanf(in,"%c",&ch)!=EOF)
	{
		if(ch=='\n') return ret;
		ret+=ch;
	}

	return ret;
}

vector< ll > xx,yy;
ll n, A, B, C, D, x0, y00, M;

void gen()
{
	ll X,Y,i;
	xx.clear();
	yy.clear();
	fscanf(in,"%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&n, &A, &B, &C, &D, &x0, &y00 , &M);
	X = x0; 
	Y = y00;
	xx.push_back(X);
	yy.push_back(Y);

	fo(i,n)
	{
		X = (A * X % M + B) % M;
		Y = (C * Y % M + D) % M;
		xx.push_back(X);
		yy.push_back(Y);
	}
}


int main()
{
	int i,z,tests,j,k;
	ll ret=0;
	fscanf(in,"%d",&tests);

	fo(z,tests)
	{
		fprintf(out,"Case #%d: ",z+1);
		gen();
		ret=0;
		
		fo(i,n) for(j=i+1; j<n; j++) for(k=j+1; k<n ; k++)
		{
			if((xx[i]+xx[j]+xx[k])%3==0 && (yy[i]+yy[j]+yy[k])%3==0)
				ret++;
		}

		fprintf(out,"%I64d\n",ret);		
	}

	return 0;
}

