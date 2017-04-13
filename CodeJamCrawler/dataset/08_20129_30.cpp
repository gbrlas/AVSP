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
long long A,B,C,D,x0,yy0,M,i,n,x[100001],y[100001],xx,yy,X,Y,j,k,ans;


int main()
{
	freopen("c:/input.txt","r",stdin);
	freopen("c:/output.txt","w",stdout);
	cin>>test;
	for ( t = 1; t <= test; t++)
	{	
			cout<<"Case #"<<t<<": ";
			cin>>n>>A>>B>>C>>D>>x0>>yy0>>M;
			
			X = x0; Y = yy0;
			
			for (i = 0; i < n; i++)
			{
				x[i] = X;
				y[i] = Y;
				X = (A * X + B) % M;
				Y = (C * Y + D) % M;
				
			}

			ans = 0;
			for (i = 0; i < n; i++)
				for (j = 0; j < i; j++)
					for (k = 0; k < j; k++)
					{
						if ((x[i] + x[j] + x[k]) % 3 == 0 && (y[i] + y[j] + y[k]) % 3 == 0) ans++;
					}

					cout<<ans<<endl;
		
	
	}
	return 0;
}