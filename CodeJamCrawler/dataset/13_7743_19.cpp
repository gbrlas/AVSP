#pragma comment(linker, "/STACK:256000000")
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

long long N, n, m, t, k=0, res=0, res2, kol=0, a[20009], pas[20009], o[100009], e[10009], p[10009], q;

void otv(long long l, long long r)
{
	if (l<r)
	{
	long long sum=0, f=0;
		for (int i = l; i < r; i++)
		{
			sum+=a[i];
		}
	long long minn = 100000000000000009;  
		for (int i = l; i < r; i++)
		{
			minn=min(minn, pas[i]);
		}
			q=sum*N-(sum*(sum-1))/2;
			q=q%1000002013;
			res2+=(minn*q)%1000002013;
		for (int i = l; i < r; i++)
		{
			pas[i]-=minn;
			if (pas[i]==0)
				f=i;
		}
		otv(l, f);
		otv(f+1, r);
	}
	res2=res2%1000002013;
		return;
}

int  main() 
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> t;
	for (int u = 1; u <= t; u++)
	{
		cout << "Case #" << u << ": ";
		cin >> N >> m;
		res=0;
		for (int i = 0; i < 2009; i++)
		{
			a[i]=0;
			pas[i]=0;
		}
		for (int i = 0; i < m; i++)
		{
			cin >> o[i] >> e[i] >> p[i];
			a[2*i]=o[i];
			a[2*i+1]=e[i];
			k=e[i]-o[i];
			q=k*N-(k*(k-1))/2;
			q=q%1000002013;
			res+=(p[i]*q)%1000002013;
		}
		sort(a, a+2*m);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < 2*m; j++)
			{
				if (a[j]>=o[i] && a[j]<e[i])
					pas[j]+=p[i];
			}			
		}
		for (int i = 0; i < 2*m-1; i++)
		{
			a[i]=a[i+1]-a[i];
		}
		res2=0;
		otv(0, 2*m-1);



		cout << (res-res2+1000002013)%1000002013 << "\n";
	}

	return 0;

}