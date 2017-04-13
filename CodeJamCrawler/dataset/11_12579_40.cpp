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
#include<map>
#include<stdlib.h>
#include<queue>
//#include<cstdio>
//#include<cstdlib>
using namespace std;

#define fo(i,n) for(i=0;i<(n);++i)


typedef vector<int> vi ;
typedef vector<string> vs ;
typedef vector<double> vd ;

double truncate(double x,int n)
{
	return (floor(x*pow(10,n))*pow(10,-n));
}
int min(int x,int y) {return x<y ? x:y;}
int max(int x,int y) {return x>y ? x:y;}

int best[2000];
vector <int> value;
int solve(int pos, int sum, int xoring, int xoringSum, int sumPile, int xorPile)
{
	if(pos == value.size())
	{
		//printf("%d %d\n",sum, xoring);
		if(sum == xoring)
			return xoringSum;
		else
			return -1;
	}

//	if(best[pos]!=-2)
//		return best[pos];

	int solve1,solve2;
	if(sumPile<value.size()-1)
		solve1 = solve(pos+1, sum+value[pos], xoring, xoringSum, sumPile+1,xorPile);
	else
		solve1=-1;
	if(xorPile < value.size()-1)
		solve2 = solve(pos+1, sum, xoring ^ value[pos], xoringSum+value[pos], sumPile, xorPile+1);
	else
		solve2 = -1;

	best[pos] = max(solve1,solve2);

	//printf("best[pos] = %d\n", best[pos]);
	return best[pos];
}
int main(void)
{
	FILE *in, *out;
	in = fopen("C-small-attempt1.in", "r");
	out= fopen("aOutput.out","w");

	int i,j,t,n,temp,res;

	fscanf(in,"%d",&t);
	for(i=0;i<t;i++)
	{
		fscanf(in,"%d",&n);
		value.resize(0);
		for(j=0;j<n;j++)
		{
			fscanf(in,"%d",&temp);
			value.push_back(temp);
		}

		for(j=0;j<2000;j++)
			best[j] = -2;
		res = solve(0,0,0,0,0,0);
		if(res == -1)
			fprintf(out,"Case #%d: NO\n", i+1);
		else
			fprintf(out,"Case #%d: %d\n", i+1, res);
	}

	return 0;
}
