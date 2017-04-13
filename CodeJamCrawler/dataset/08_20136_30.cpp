#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <sstream>

using namespace std;

#define LL long long 
#define PII pair<int,int> 
#define VI vector<int> 
#define VPII vector<PII> 
#define eps 1e-9
#define inf int(1000000000)

int test,t;
int i,j,k,n,m,ans,b[10000];

void solve(int p)
{
	
	
	int a[10000],used[10000];
	for (i = 0; i < 10000; i++) a[i] = 0;

	a[0] = 1;
	int pos,sz;

	pos = -1;
	for (i = 0;  i <= p; i++) used[i] = 0;
	pos = 0;
	used[0] = 1;
	for (i = 1; i < p; i++)
	{
		int num = i;
		int kk = 0;
		while (kk < num)
		{
			if (used[pos] == 1)
			{
				pos ++;
				if (pos == p) pos = 0;
				continue;
			}

			kk ++;
				pos ++;
				if (pos == p) pos = 0;
		}


		while (used[pos] == 1)
		{
		pos ++;
				if (pos == p) pos = 0;		}

		a[pos] = i+1;
		used[pos] = 1;
		
	}

	for (i = 0; i < n; i++) cout<<a[b[i] - 1]<<" ";
	cout<<endl;

}

int main()
{
	freopen("c:/input.txt","r",stdin);
	freopen("c:/output.txt","w",stdout);
	cin>>test;
	for ( t = 1; t <= test; t++)
	{	
		cin>>k>>n;
		for (i = 0; i < n; i++)
		{
			cin>>b[i];
		}

		cout<<"Case #"<<t<<": ";
		solve(k);

	

			
		
	
	}
	return 0;
}