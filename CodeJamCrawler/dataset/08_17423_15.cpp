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

vi prime_factorization(long x)   // not tested before
{
	long i,c;			
	vi ret;

	c = x;

	while (c%2== 0)
	{
		ret.push_back(2);
		c/=2;
	}

	for(i=3 ; i*i<=c ; )
	{
		if (c%i==0)
		{
			ret.push_back(i);
			c/=i;
		}
	
		else
			i+=2;
	}

	if (c>1) 
		ret.push_back(c);

	return ret;
}


FILE *in = fopen("B-small-attempt2.in","r");
//FILE *in = fopen("B-large.in","r");
//FILE *in = fopen("b.in","r");
FILE *out= fopen("b.out","w");

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

vector< vi > y;
int p;

int share(int uu, int vv)
{
	int i=0,j=0;

	while(i<y[uu].size() && j<y[vv].size())
	{
		if(y[uu][i]==y[vv][j] && y[uu][i]>=p)
			return 1;

		if(y[uu][i]==y[vv][j])
			i++,j++;

		else if(y[uu][i]>y[vv][j])
			j++;
		else i++;
	}

	return 0;

}

int mat[1010][1010];


int main()
{
	int i,z,tests,a,b,j,u,v,c,d,k;
	int h[1010];
	vector< vi > x;
	vi temp;
	y.clear();
	y.push_back(temp);
	y.push_back(temp);
	
	fscanf(in,"%d",&tests);

	for(i=2; i<=1000; i++)
		y.push_back(prime_factorization(i));

	

	fo(z,tests)
	{
		printf("%d\n",z);
		fprintf(out,"Case #%d: ",z+1);
		fscanf(in,"%d%d%d",&a,&b,&p);

		CL(h,-1);
		CL(mat,0);
		fo(i,1001) fo(j,1001)
		if(share(i,j))
			mat[i][j]=1;
		k=0;
		
		for(i=a; i<=b; i++)
		{
			if(h[i]==-1)
			for(j=i+1; j<=b; j++)
				if(h[j]!=-1 && mat[i][j])
					break;

			if(h[i]==-1 && j<=b)
				h[i]=h[j];
			else if(h[i]==-1)
			{
				h[i]=k;
				k++;
			}

			for(j=i+1; j<=b; j++)
				if(h[j]==-1 && mat[i][j])
					h[j]=h[i];
		}

		fprintf(out,"%d\n",k);
		
	}

	return 0;
}

