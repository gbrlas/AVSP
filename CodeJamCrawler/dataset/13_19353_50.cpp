/*Shashank Shekhar JUET*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <cctype>
 
using namespace std;
 
#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(i=(a);i<(n);++i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x);
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl

bool palin(int a)
{
    int t1=a,t2=0;
	while(t1!=0)
	{
		t2=t2*10+t1%10;
		t1/=10;
	}
	return (a==t2);
}
int main()
{
	int t,a,b,c,count=0;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d %d",&a,&b);
		c=a+b;
		b=max(a,b);
		a=c-b;
		count=0;
		for(int j=a;j<=b;j++)
		{
			if(palin(j))
			{
				if(sqrt(j)-(int)sqrt(j)==0.0)
				{
					if(palin((int)sqrt(j)))
					count++;
				}	
			}
		}
		cout<<"Case #"<<i<<": "<<count<<"\n";
	}
	return 0;
	
}