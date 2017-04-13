#include <iostream>
#include <string>
#include <cmath>
using namespace std;
bool ispal (int a)
{
	string s;
	while(a!=0)
	{
		s.push_back(a%10+'0');
		a/=10;
	}
	for(int n=0; n<s.length()-n-1; n++)
	{
		if(s[n]!=s[s.length()-n-1]) return 0;
	}
	return 1;
}
int main()
{
	int ilez;
	cin>>ilez;
	long long a, b;
	long long pa, pb;
	long long wynik;
	for(int aa=1; aa<=ilez; aa++)
	{
		wynik=0;
		cin>>a>>b;
		pa=sqrt(a); pb=sqrt(b);
		while(pa<=pb)
		{
			if(pa*pa<=b && pa*pa>=a &&ispal(pa) && ispal(pa*pa))
				wynik++;
			pa++;
		}
		cout<<"Case #"<<aa<<": "<<wynik<<endl;
	}	
}
