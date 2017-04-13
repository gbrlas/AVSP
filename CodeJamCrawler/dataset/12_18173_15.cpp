
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

char c[]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
string s;

void read ()
{
	getline(cin,s);
}

void solve ()
{
	for(size_t i=0;i<s.size();++i)
		if(isalpha(s[i]))
			s[i]=c[s[i]-'a'];
}

void out (int cc)
{
	cout<<"Case #"<<cc<<": "<<s<<'\n';
}

int main ()
{
	freopen ("input.in","r",stdin);
	freopen ("output.out","w",stdout);
	int t;
	cin>>t;
	getline(cin,s);
	for(int i=1;i<=t;++i)
	{
		read ();
		solve ();
		out (i);
	}
	return 0;
}
