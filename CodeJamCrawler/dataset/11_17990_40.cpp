#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int nc,n,w,sol[10],p[10],u[10],v[10];
bool flag;
vector <int> r;

void dfs(int k) {
	if(flag) return;
	if(k==n) {
		for(int i=0;i<r.size();++i) {
			int t=0;
			for(int j=0;j<n;++j)
				if((1<<j)&r[i])
					if(!((1<<p[j])&t))
						t^=(1<<p[j]);
			if(t!=(1<<nc)-1) return;
		}
		flag=true;
		for(int i=0;i<n;++i) sol[i]=p[i]+1;
	}
	else {
		for(int i=0;i<nc&&!flag;++i) {
			p[k]=i;
			dfs(k+1);
		}
	}
}

void wall(const vector<int> &d) {
	bool room=true;
	for(int i=0;i<w;++i) {
		int a=-1,b=-1;
		for(int j=0;j<d.size();++j)
			if(u[i]-1==d[j]) a=j;
			else if(v[i]-1==d[j]) b=j;
		if(a==-1||b==-1) continue;
		int t=a-b;
		if(t<0) t=-t;
		if(t==1||t==d.size()-1) continue;
		if(a>b) swap(a,b);
		vector <int> ra,rb;
		for(int i=a;i<=b;++i) ra.push_back(d[i]);
		for(int i=b;i<d.size();++i) rb.push_back(d[i]);
		for(int i=0;i<=a;++i) rb.push_back(d[i]);
		room=false;
		wall(ra);
		wall(rb);
		break;
	}
	if(room) {
		int t=0;
		for(int i=0;i<d.size();++i) t^=(1<<d[i]);
		r.push_back(t);
	}
}

int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int cc;
	cin>>cc;
	for(int cid=1;cid<=cc;++cid) {
		cin>>n>>w;
		for(int i=0;i<w;++i) cin>>u[i];
		for(int i=0;i<w;++i) cin>>v[i];
		vector <int> t;
		for(int i=0;i<n;++i) t.push_back(i);
		r.clear();
		wall(t);
		for(int i=0;i<n;++i) sol[i]=1;
		for(nc=n;nc>1;--nc) {
			flag=false;
			dfs(0);
			if(flag) break;
		}
		cout<<"Case #"<<cid<<": "<<nc<<endl;
		for(int i=0;i+1<n;++i) cout<<sol[i]<<" ";
		cout<<sol[n-1]<<endl;
	}
	return 0;
}
