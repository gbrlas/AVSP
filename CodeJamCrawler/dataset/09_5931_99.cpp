#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()	{
	
	freopen("1_large.in","rt",stdin);
	freopen("1_large.out","wt",stdout);
	
	int l,d,n;
	cin>>l>>d>>n;
	vector<string> w(d);
	for(int i=0;i<d;i++) cin>>w[i];
	
	for(int tc=1;tc<=n;tc++)	{
		
		string s;
		cin>>s;
		
		vector<string> v;
		
		for(int i=0;i<s.size();i++)	{
			if(s[i]!='(') v.push_back(string(1,s[i]));
			else {
				int ind = s.find(')', i);
				v.push_back(s.substr(i+1,ind-i));
				i=ind;
			}
		}
		
		int ans=0;
		
		for(int i=0;i<d;i++)		{
			bool ok=1;
			for(int j=0;j<l;j++) if(v[j].find(w[i][j])==-1) {
				ok=false;
				break;
			}
			
			if(ok) ans++;
		}
		
		cout<<"Case #"<<tc<<": "<<ans<<endl;
	}
	
	return 0;
}
