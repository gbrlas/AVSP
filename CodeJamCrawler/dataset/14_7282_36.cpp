#include <iostream>
#include <algorithm>
#include <map>
#include <iomanip>
using namespace std;
#define ld long double
#define ll long long
ld C, F, X;

inline bool maleje(ll a);
inline ld prize(ll a);
inline ld absd(ld a){if(a>0) return a; return -a;}
map <int, ld> MAP;

int main()
{
	ios_base::sync_with_stdio(0);
	cout<<fixed<<setprecision(7);
	int ilez;
	cin>>ilez;
	for(int aa=0; aa<ilez; aa++)
	{
		MAP.clear();
		cin>>C>>F>>X;
		MAP[0]=0;
//		cout<<prize(0);
		ll maxdomow=1;
		while(maleje(maxdomow))
		{
			maxdomow*=2;
		}
		ll p=0, q=maxdomow, s;
		while(p<q)
		{
			s=(p+q)/2;
			if(maleje(s))
			{
				p=s+1;
			}
			else
			{
				q=s;
			}
		}
		p-=3; q+=3;
		ll tmpll=0;
		p=max(p, tmpll);
		ld wynik=prize(p);
		for(ll a=p+1; a<=q; a++)
		{
//			cout<<prize(a)<<endl;
			wynik=min(wynik, prize(a));
		}
		cout<<"Case #"<<aa+1<<": "<<wynik<<endl;
	}
}
inline bool maleje(ll a)
{
	if(prize(a)>prize(a+1))
		return 1;
	return 0;
}
inline ld prize(ll a)
{
//	cout<<a<<endl;
//	int tmpaaa;
//	cin>>tmpaaa;
	if(a==0) return (X/2.0);
	if(MAP[a]!=0)
		return MAP[a]+(X/(F*a+2.0));
	prize(a-1);
	MAP[a]=MAP[a-1]+(C/(F*(a-1)+2.0));
	return MAP[a]+(X/(F*a+2.0));
}
