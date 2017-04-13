#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;


#define PII pair<long long,long long>
#define MP make_pair
#define VI vector<int>
#define eps 1e-9
#define inf 1000000007

int a[200];
int t , n , m , i , j , l , h;

int main()
{
	freopen("c:/input.txt","r",stdin);
	freopen("c:/output.txt","w",stdout);
	cin>>t;
	for (int tt = 1; tt <= t; tt++)
	{
		cin>>n>>l>>h;
		for (i = 0; i < n; i++)
			cin>>a[i];

		cout<<"Case #"<<tt<<": ";
		int isans = 0;
		for (i = l; i <= h; i++)
		{
			int d = 0;
			for (j=  0; j <n; j++)
				if ((a[j] % i != 0) && (i % a[j] != 0))
				{
					d = 1;
					break;
				}
			if (!d)
			{
				cout<<i<<endl;
				isans = 1;
				break;
			}
		}

		if (!isans)
			cout<<"NO\n";


		
		
	}
	return 0;
}



