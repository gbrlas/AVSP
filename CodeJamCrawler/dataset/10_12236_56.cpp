#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<sstream>

using namespace std;
vector<string> v;
struct tree{
	map<string,tree> m;
	int makdr(int i)
	{
		if( i == v.size()) return 0;
		if(m.find( v[i]) == m.end())
			return m[v[i]].makdr(i+1) + 1 ;
		return m[v[i]].makdr(i+1);
	}
};
tree T;

int make(string& s)
{
	for(int i=0;i<(int)s.size();i++)
		if(s[i] == '/') s[i] = ' ' ;
	string ss;
	stringstream iss(s);
	v.clear();
	while(iss>>ss)
		v.push_back(ss);

	return T.makdr(0);

}
int main()
{
	freopen("in.txt","rt",stdin);
	freopen("out.txt","wt",stdout);
	int TC,ans,i,n,m;
	string s;
	cin>>TC;
	for(int tc = 1;tc<= TC;tc++)
	{
		ans = 0;
		T.m.clear();
		cin>>n>>m;
		for(i=0;i<n;i++)
		{
			cin>>s;
			make(s);
		}

		for(i=0;i<m;i++)
		{
			cin>>s;
			ans+=make(s);
		}

		printf("Case #%d: %d\n",tc,ans);


	}
}