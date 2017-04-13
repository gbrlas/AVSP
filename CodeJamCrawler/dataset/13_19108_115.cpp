//////////////////////////////////////////
//   Bismillahir Rahmanir Rahim        //
//   Author      : Shohan Ahmed Sijan //
//   Country     : Bangladesh        //
//   Algorithm   : 
//   Complexity  : %
//   University  : East West University //
/////////////////////////////////////////
#pragma warning(disable:4786)
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define Re(i,n) for(i=0;i<n;i++)
#define inf 999999999
#define PI acos(-1)
#define EPS 1e-12
#define sqrt(x) sqrt(abs(x))
#define P pair<int,int>
#define N 1009
#define NN 100000000000005

typedef  __int64 I;

I Max(I a,I b)
{
	return a>b?a:b;
}
I Min(I a,I b)
{
	return a<b?a:b;
}

//................................
I num[N];
char n2[20];
bool pe(I n1)
{
	int i,l=log10(n1);
	sprintf(n2,"%I64d",n1);
	for(i=0;i<=l/2;i++)
		if(n2[i]!=n2[l-i])return false;
	return true;
}
int main()
{
	freopen("cs.in","r",stdin);
	freopen("C_output.txt","w",stdout);
	int i,j,test,cas=1,in=0;
	I a,b;

	for(i=1;i<=1000;i++)//10000002
	{
		if(pe(i))
		{
			if(pe(i*i))
			{
				num[in++]=i*i;
			}
		}
	}

	scanf("%d",&test);
	while(test--)
	{
		scanf("%I64d %I64d",&a,&b);
		int cnt=0;
		for(i=0;i<in;i++)
			if(a<=num[i] && num[i]<=b)
				cnt++;
		printf("Case #%d: %d\n",cas++,cnt);
	}

	return 0;
}