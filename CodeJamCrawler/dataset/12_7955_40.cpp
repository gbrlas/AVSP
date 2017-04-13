#include <iostream>
#include <cstdio>

#define MAX 2000002

using namespace std;

int getDivisor(int x, int &d)
{
	int p=1;
	d = 1;
	while(1)
	{
   	if(x>=p && x<10*p)
   	{
   		return p;
   	}
   	else
   	{
	   	p=p*10;
   		d++;
   	}
	}
}


int main()
{
	
	freopen("C-large.in", "r", stdin);
	freopen("op.out", "w", stdout);
	
	int t, a, b;
	int c, d, p, ans, x, i, r;
	int v[MAX];
	cin>>t;
	
	for(int tc=1; tc<=t; tc++)
	{	
		cin>>a>>b;
		
		ans = 0;
		for(i=a; i<=b; i++)
			v[i] = 0;
		
		for(x=a; x<=b; x++)
		{
			c = 1;
			p = getDivisor(x, d);
			r = x;
			for(i=1; i<=d-1; i++)
			{
				r = 10*(r%p) + r/p;
				if(x < r && r <= b && v[r] == 0)
				{
					c++;
					v[r] = 1;
				}
			}
			ans = ans + c*(c-1)/2;
		}
		cout<<"Case #"<<tc<<": "<<ans<<endl;
	}
	
	return 0;
}
		