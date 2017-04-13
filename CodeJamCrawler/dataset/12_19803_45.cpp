#include<iostream>
#include<string>
#include<cctype>
using namespace std;

char a[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	string s;
	getline(cin,s);
	for (int i=0;i<n;i++)
	{
		getline(cin,s);
		cout<<"Case #"<<i+1<<": ";
		for (string::size_type j=0;j<s.size();j++)
			if (islower(s[j])) cout<<a[s[j]-'a'];
			else cout<<s[j];
		cout<<'\n';
	}
	return 0;
}
