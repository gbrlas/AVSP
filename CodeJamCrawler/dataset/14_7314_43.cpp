#include <iostream>
#include <cmath>
#define ll long long
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	
	int ilez;
	cin>>ilez;
	
	for(int aa=0; aa<ilez; aa++)
	{
		cout<<"Case #"<<aa+1<<": ";
		ll p, q;
		char tmp;
		cin>>p>>tmp>>q;
		
		for(ll n=2; n<=sqrt(q+1); n++)
		{
			while(p%n==0 && q%n==0) {q/=n; p/=n;}
		}		
		
		ll a=1;
		while(a<q) a*=2;
		if(a!=q)
			cout<<"impossible"<<endl;
		else
		{
			ll k=q/(2*p);
			if(q%(2*p)!=0) k++;
			ll wynik=1;
			ll tmp=1;
			while(tmp<k) {tmp*=2; wynik++;}
				cout<<wynik<<endl;
		}
	}
}
