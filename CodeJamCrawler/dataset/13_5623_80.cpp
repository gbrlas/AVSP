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
		int N,M;
		cin>>N>>M;
		cin.ignore();
		int* lawn=new int[N*M];
		int *linesmax=new int[N];
		int *colmax=new int[M];
		cout<<"Case #"<<inc+1<<": ";
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
			linesmax[i]=lawn[i*M];
			for(int j=1;j<M;j++)
			{
				if(lawn[i*M+j]>linesmax[i])
				{
					linesmax[i]=lawn[i*M+j];
				}
				
			}
		}

		for(int j=0;j<M;j++)
		{
			colmax[j]=lawn[j];
			for(int i=0;i<N;i++)
			{
				if(lawn[i*M+j]>colmax[j])
				{
					colmax[j]=lawn[i*M+j];
				}
			}
		}

		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
				if(lawn[i*M+j]<linesmax[i] && lawn[i*M+j]<colmax[j])
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
}

int main()
{
	A();
	return 0;
}