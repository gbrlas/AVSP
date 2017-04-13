/*By Rahul Goutam*/
#include<deque>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<ios>
#include<iostream>
#include<iosfwd>
#include<iomanip>
#include<istream>
#include<ostream>
#include<sstream>
#include<complex>
#include<numeric>
#include<valarray>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;

#define INF 10000000

bool known[110][110];
pair<int,int>sink[110][110];
int m[110][110],h,w;

pair<int,int> flow(int i, int j) {
	if(known[i][j])
		return sink[i][j];
	known[i][j]=1;
	int minm=m[i][j];
	if(i) minm=min(minm,m[i-1][j]);
	if(j) minm=min(minm,m[i][j-1]);
	if(j!=w-1) minm=min(minm,m[i][j+1]);
	if(i!=h-1) minm=min(minm,m[i+1][j]);

	if(minm==m[i][j]) sink[i][j]=make_pair(i,j);
	else if(i && minm==m[i-1][j]) sink[i][j]=flow(i-1,j);
	else if(j && minm==m[i][j-1]) sink[i][j]=flow(i,j-1);
	else if(j!=w-1 && minm==m[i][j+1]) sink[i][j]=flow(i,j+1);
	else if(i!=h-1 && minm==m[i+1][j]) sink[i][j]=flow(i+1,j);
	return sink[i][j];
}

int main() {
	int T,cases=0;
	cin>>T;
	while(T--) {
		memset(m,0,sizeof m);
		memset(known,0,sizeof known);
		cin>>h>>w;
		for(int i=0;i<h;i++) 
			for(int j=0;j<w;cin>>m[i][j++]);
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				if(!known[i][j])
					flow(i,j);
		set< pair<int,int> > s;
		vector< pair<int,int> > v;
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				if(s.find(sink[i][j])==s.end()) {
					v.push_back(sink[i][j]);
					s.insert(sink[i][j]);
				}
		int size=v.size();
		printf("Case #%d:\n",++cases);
		for(int i=0;i<h;i++) {
			for(int j=0;j<w;j++)
				for(int k=0;k<size;k++)
					if(sink[i][j].first==v[k].first && sink[i][j].second==v[k].second) {
						cout<<(char)('a'+k)<<" ";
						break;
					}
			cout<<endl;
		}
	}
	return 0;
}
