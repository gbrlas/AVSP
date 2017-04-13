#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>
#include<cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)

bool matchs(string s,string t)
{
	int i,j;
	bool res=true;
	char c;
	j=0;
	for(i=0;i<s.size();i++)
	{
		c=s[i];
		if(t[j]=='(')
		{
			bool esta=false;
			while(t[j]!=')')
			{
				if(t[j]==c)esta=true;
				j++;
			}
			if(!esta)res=false;
		}else if (t[j]!=c)res=false;
		j++;
	}
	return res;
}

int main()
{
	int l,d,n;
	cin>>l>>d>>n;
	vector<string> w;
	string s;
	int i,j,res;
	for(i=0;i<d;i++)
	{
		cin>>s;
		w.pb(s);
	}
	for(i=0;i<n;i++)
	{
		cin>>s;
		res=0;
		for(j=0;j<d;j++)if(matchs(w[j],s))res++;
		cout<<"Case #"<<i+1<<": "<<res<<endl;
	}
}
