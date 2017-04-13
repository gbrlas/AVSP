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

long long xx1,yy1,x2,y2,x3,y3,test,t,n,m,i,j,k,l,s;



int main()
{
	freopen("c:/input.txt","r",stdin);
	freopen("c:/output.txt","w",stdout);
	cin>>test;
	for ( t = 1; t <= test; t++)
	{	
			cout<<"Case #"<<t<<": ";
			cin>>n>>m>>s;
			xx1 = yy1 = 0;
			int d = 0;
			for (x2 = 0; x2 <= n; x2++)
				for (y2 = 0; y2 <= m; y2++)
					for (x3 = 0; x3 <= n; x3++)
						for (y3 = 0; y3 <= m; y3++)
						{
							if (d) break;
							if (x2 == 0 && y2 == 0) continue;
							if (x3 == 0 && y3 == 0) continue;
							if (x2 == x3 && y2 == y3) continue;
							long long ss = ((xx1-x2)*(yy1-y3)-(yy1-y2)*(xx1-x3));
							if (ss < 0) ss *= -1;
							if (ss == s)
							{
								cout<<"0 0 "<<x2<<" "<<y2<< " "<<x3<<" "<<y3<<endl;
								d = 1;
							}

						}
						if (d == 0)
						{
							cout<<"IMPOSSIBLE"<<endl;
						}
		
	
	}
	return 0;
}