#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include <functional>
#include<vector>
#include<string>
#include <iostream>
#include <sstream>
#include<set>
using namespace std;

#define fo(i,n) for(i=0;i<(n);++i)


typedef vector<int> vi ;
typedef vector<string> vs ;
typedef vector<double> vd ;

#define loop(i,n) for(i=0;i<n;i++)
#define sz(x) x.size();
#define INF (1<<30)

int gcd(int x,int y)
{
	if(x<y)
		gcd(y,x);
	int t;
	while(x%y!=0) t=x%y,x=y,y=t;
	return y;
}

int lcd(vector <int> & arr)
{
	int i, res;
	res = arr.size()!=0 ? arr[0]:0;
	for(i=0;i<arr.size();i++)
	{
		res = (res*arr[i])/gcd(res, arr[i]);
	}
	return res;
}

int main(void)
{
	FILE *in,*out;

	in = fopen("C-small-attempt0.in","r");
	out = fopen("b.out","w");

	int t,T;

	long long i,j,N,L,H,temp,ans;
	vector <long long> v;

	fscanf(in,"%d",&T);

	for(t=0;t<T;t++)
	{
		fscanf(in,"%lld %lld %lld", &N,&L,&H);

		v.resize(0);
		for(i=0;i<N;i++)
		{
			fscanf(in,"%lld", &temp);
			v.push_back(temp);
		}

		for(i=L;i<=H;i++)
		{
			for(j=0;j<v.size();j++)
			{
				if(!(i%v[j] == 0 || v[j]%i== 0))
				{
					break;
				}
			}

			if(j==v.size())
			{
				fprintf(out,"Case #%d: %d\n", t+1, i);
				break;
			}
		}
		if(i==H+1)
			fprintf(out,"Case #%d: NO\n",t+1);
	}
	return 0;
}
