#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>

using namespace std;
#define SMALL
//#define LARGE


/*void A()
{
#ifdef SMALL
	freopen("A-small-practice.in","rt",stdin);
	freopen("A-small.out","wt",stdout);
#endif
#ifdef LARGE
	freopen("A-large.in","rt",stdin);
	freopen("A-large.out","wt",stdout);
#endif
	int nc;
	cin >> nc;
	cin.ignore();

	for(int inc=0;inc<nc;inc++)
	{
		int N,M;
		cin>>N>>M;
		cin.ignore();
		int* lawn=new int[N*M];
		int *lines=new int[N];
		int *col=new int[M];

		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
				cin>>lawn[i*M+j];
			}
			cin.ignore();
		}

				for(int i=0;i<N;i++)
		{
			int c=lawn[i*M];
			lines[i]=1;
			for(int j=1;j<M;j++)
			{
				if(lawn[i*M+j]!=c)
				{
					lines[i]=0;
					break;
				}
				
			}
		}

		for(int j=0;j<M;j++)
		{
			int c=lawn[j];
			col[j]=1;
			for(int i=0;i<N;i++)
			{
				if(lawn[i*M+j]!=c)
				{
					col[j]=0;
					break;
				}
			}
		}

		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
				if(!(lines[i]+col[j]))
					goto YES;
			}
		}

		cout<<"YES";
		goto end;
YES:
		cout<<"NO";
end:
		cout<<"\n";
	}
}*/

__int64 inv(__int64 num)
{
 __int64 rev = 0,dig;
 while (num > 0)
 {
      dig = num % 10;
      rev = rev * 10 + dig;
      num = num / 10;
 }

 return rev;
}

int fair_square_search(__int64 A,__int64 B)
{
	__int64 sqrtA=(std::sqrt((long double)A));

	int c=0;

	if(A==1 || (A==sqrtA*sqrtA && (inv(sqrtA)==sqrtA && inv(A)==A)))
		c++;
	for(__int64 i=sqrtA+1;i*i<=B;i++)
	{
		
		if(inv(i)==i && inv(i*i)==i*i)
		{
			c++;
		}
	}
	return c;
}

void A()
{
#ifdef SMALL
	freopen("A-small-practice.in","rt",stdin);
	freopen("A-small.out","wt",stdout);
#endif
#ifdef LARGE
	freopen("A-large.in","rt",stdin);
	freopen("A-large.out","wt",stdout);
#endif
	int nc;
	cin >> nc;
	cin.ignore();

	for(int inc=0;inc<nc;inc++)
	{
		cout<<"Case #"<<inc+1<<": ";
		int N,M;
		cin>>N>>M;
		cin.ignore();
		cout<<fair_square_search(N,M)<<"\n";
	}
}

int main()
{
	A();
	return 0;
}