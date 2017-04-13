#include<iostream>

using namespace std;

int main()
{
	int t;
	cin>>t;
	char c[26] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
	int cases = 1;
	string s;
	getline(cin,s);
	while(t-->0)
	{
		getline(cin,s);

		string ans;
		for(int i=0;i<(int)s.length();i++)
		{
			if(s[i]==' '){
				ans+=' ';
				continue;
			}
			ans=ans +c[s[i]-'a'];
		}

		cout<<"Case #"<<cases++<<": "<<ans<<endl;
	}
}

		