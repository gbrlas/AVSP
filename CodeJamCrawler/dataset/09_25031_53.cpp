#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<queue>
#include<string>
#include<cmath>
#include<fstream>
using namespace std;
#define FOR(i,a,b) for(int (i)=(a); (i)<(b); ++(i))
#define all(a) (a).begin(),(a).end()
#define MOD 1000000007

int main()
{
	int l,d,n;
	ifstream fin("C:\\A-small.in");
	ofstream fout("C:\\A-large.out");
	fin>>l>>d>>n;
	string temp;
	set<string> s;
	FOR(i,0,d)
	{
		fin>>temp;
		FOR(i,1,temp.size()+1)
			s.insert(temp.substr(0,i));
	}
	FOR(k,0,n)
	{
		string r;
		fin>>r;
		vector< vector<char> > v(l);
		int cur=0;
		int final=0;
		FOR(i,0,r.size())
		{
			if(r[i]=='(')
			{
				i++;
				while(r[i]!=')')
				{	
					v[cur].push_back(r[i]);
					i++;
				}
			}
			else
				v[cur].push_back(r[i]);
			cur++;
		}
		queue<string> q;
		FOR(i,0,v[0].size())
		{
			string temp;
			if(s.count(temp+v[0][i]))
			q.push(temp+v[0][i]);
		}
		while(!q.empty())
		{
			string temp=q.front();
			q.pop();
			int sz=temp.size();
			if(sz==l)
			{
				if(s.count(temp))final++;
				continue;
			}
			else
			{
				FOR(i,0,v[sz].size())
				{
					string ctr=temp+v[sz][i];
					if(s.count(ctr))
						q.push(ctr);
				}
			}
		}
		fout<<"Case #"<<k+1<<": "<<final<<endl;
	}
}