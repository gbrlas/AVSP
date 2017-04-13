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

int test,t,a[100],i,j,k,p,ans;



int main()
{
	freopen("c:/input.txt","r",stdin);
	freopen("c:/output.txt","w",stdout);
	cin>>test;
	string s;
	for ( t = 1; t <= test; t++)
	{	
			cout<<"Case #"<<t<<": ";
			cin>>k>>s;
			for (i = 0; i <= k; i++)
			{
				a[i] = i;
			}

			ans  = 100000;

				string t = "";
				for (i = 0; i < s.size(); i++)
				{
					j = i % k;
					p = i - i % k;
					t = t + s[p + a[j]];
				}

				int num = 1;
				for (i = 1; i  < s.size(); i++)
					if (t[i] != t[i-1]) num++;
				

				ans = min(ans,num);


			

			while (next_permutation(a,a+k))
			{
				t = "";
				for (i = 0; i < s.size(); i++)
				{
					j = i % k;
					p = i - i % k;
					t = t + s[p + a[j]];
				}

				int num = 1;
				for (i = 1; i  < s.size(); i++)
					if (t[i] != t[i-1]) num++;
				

				ans = min(ans,num);
			}
			cout<<ans<<endl;
			
	
	}
	return 0;
}