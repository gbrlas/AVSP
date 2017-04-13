#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;


#define PII pair<long long,long long>
#define MP make_pair
#define VI vector<>
#define eps 1e-9
#define inf 1000000000000000000LL
#define ll long long

long long a[20000] , g[20000] , u[20000] , d[20000];
long long t , n , m , i , j , l , h , c ,ttt , pos;
vector<long long> v;


int main()
{
	freopen("c:/input.txt","r",stdin);
	freopen("c:/output.txt","w",stdout);
	cin>>ttt;
	for (int tt = 1; tt <= ttt; tt++)
	{
		
		cin>>l>>t>>n>>c;
		for (i = 0; i < c; i++)
			cin>>d[i];
		
		a[0] = 0;
		for (i = 1; i <= n; i++)
			a[i] = a[i-1] + d[(i-1) % c];
		
		v.clear();
		cout<<"Case #"<<tt<<": ";
		


			int d = 0;
			for (i = 0; i < n; i++)
			{
				if (a[i+1] > t/2)
				{
					d = 1;
					if (t / 2 > a[i])
					{
						pos = a[i+1] - t / 2;
					} else
						pos = a[i+1] - a[i];

					
					for (j = i + 1; j < n; j++)
					{
						v.push_back(a[j+1] - a[j]);
						v.push_back(pos);
					}

					sort(v.rbegin() , v.rend());
					ll ans = 0;
					for (i = 0; i < v.size() && i < l; i++)
					{
						ans += v[i];
					}

					cout<<a[n] *2 - ans<<endl;
						
					break;


				}
			}

			if (d == 0)
				cout<<a[n] * 2<<endl;

	}
	return 0;
}



