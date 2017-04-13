#include	<cstdio>
#include	<cstdlib>
#include	<iostream>
#include	<vector>
#include	<string>
#include	<cmath>
#include	<algorithm>
#include	<conio.h>
#include	<windows.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	long v1[1000],v2[1000];
	long sum;
	int n,m;
	for(int a=0;a<t;a++)
	{
		cin >> n;
		for(m=0;m<n;m++)
			cin >> v1[m];
		for(m=0;m<n;m++)
			cin >> v2[m];
		sum=0;
		sort(v1,v1+n);
		sort(v2,v2+n);
		for(m=0;m<n;m++)
		{
			sum+=v1[m]*v2[n-m-1];
		}
		cout << "Case #"<< a+1 << ": " << sum << endl;
	}
	return 0;
}