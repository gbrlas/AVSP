#include <cstdio>
#include <string>
#include <iostream>

const char a[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
using namespace std;

string s;

int main(){
	int test=0;
	cin>>test;
	getline(cin,s);
	for (int T=1; T<=test; ++T){
		getline(cin,s);
		cout<<"Case #"<<T<<": ";
		for (int i=0; i<s.size(); ++i)
			if (s[i]>='a' && s[i]<='z')
				cout<<a[s[i]-'a'];
			else
				cout<<' ';
		cout<<endl;
	}
}
