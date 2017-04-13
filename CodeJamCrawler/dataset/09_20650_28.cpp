#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define VI vector<int>
#define PII pair<int,int>
#define f0(i,n) for(i = 0; i < n; i++)
#define eps 1e-9
#define MP make_pair

char a[100][100];
int d[100];

using namespace std;

int i , j , k , n , m , p;

int main()
{
	freopen("d:/input.txt" , "r" , stdin);
	freopen("d:/output.txt" , "w" , stdout);
	int t;
	cin>>t;
	for (int tt = 0; tt < t; tt++)
	{
		cin>>n;
		gets(a[0]);
		for (i = 0; i < n; i++)
			gets(a[i]);

		for (i = 0; i < n; i++)
		{
			d[i] = 0;
			for(j = 0; j < n; j++)
				if (a[i][j] == '1')
					d[i] = j;
		}

		int ans = 0;
		for (i = 0; i < n; i++)
		{
			if (d[i] > i)
			for (j = i+1; j < n; j++)
			{
				if (d[j] <= i)
				{
					while (j > i)
					{
						swap(d[j] , d[j-1]);
						ans++;
						j--;
					}
					break;
				}
			}
		}

		cout<<"Case #"<<tt+1<<": ";
		cout<<ans<<endl;
	}
	return 0;
}