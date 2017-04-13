#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

double w[10000];
string c[10000];
int ll[10000],rr[10000];
int p,q,b;
vector<string> v;
vector<string> ch;

void build(int q)
{
	ll[q]=rr[q]=-1;
	p++;
	w[q]=atof(v[p].c_str());
	p++;
	if (v[p]==")")
	{
		p++;
		return;
	}
	c[q]=v[p];
	p++;
	ll[q]=(b++);
	build(ll[q]);
	rr[q]=(b++);
	build(rr[q]);
	p++;
}
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
	int n;
	cin>>n;
	for(int nn=1;nn<=n;nn++)
	{
		v.clear();

		int m,l;
		cin>>l;
		string line;		
		getline(cin,line);
		string s="";
		for(int j=0;j<l;j++)
		{
			getline(cin,line);
			s+=line+" ";
		}
		string ss="";
		for (int j=0;j<s.length();j++)
			if (s[j]=='(')
				ss+=" ( ";
			else if (s[j]==')')
				ss+=" ) ";
			else
				ss+=s[j];
		istringstream sin(ss);
		string sss;
		while (sin>>sss)
			v.push_back(sss);
		b=1;
		p=0;
		q=0;
		build(0);
		cout<<"Case #"<<nn<<": "<<endl;
		cin>>m;
		for(int mm=0;mm<m;mm++)
		{
			int mmm;
			cin>>s>>mmm;
			ch.clear();
			for (int j=0;j<mmm;j++)
			{
				cin>>s;
				ch.push_back(s);
			}
			double ans=1;
			q=0;
			while (1)
			{
				ans*=w[q];
				if (ll[q]<0 && rr[q]<0)
					break;
				int sudu=0;
				for(int j=0;j<ch.size();j++)
				{
					if(ch[j]==c[q])
						sudu=1;
				}
				if (sudu==1)
					q=ll[q];
				else
					q=rr[q];
			}			
			cout << fixed << setprecision(10) <<ans<< endl;
			//cout<<setprecision(10)<<ans<<endl;
		}
	}
	return 0;
}

