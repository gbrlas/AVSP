#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

const int maxn = 1e4+10;

typedef pair<int,int> pii;

struct comp{
	int operator ()(const pii& a, const pii &b) {
		return a.second<b.second;
	}
};

int comp2(const pii &a,const pii& b) {
	return a.first<b.first;
}

int mark[maxn];

int main() {
	int t;
	cin>>t;
	for(int tn=0;tn<t;tn++) {
		int n;
		cin>>n;
		vector<pii> in;
		for(int i=0;i<n;i++) {
			int d,l;
			cin>>d>>l;
			in.push_back(pii(d,l));
		}
		int d;
		cin>>d;
		priority_queue<pii,vector<pii>,comp> pq;
		memset(mark,0,sizeof mark);
		int temp = min(in[0].second,in[0].first);
		pq.push(pii(0,temp));
		int flag = 0;
		while(pq.size()>0) {
			pii now = pq.top();
			pq.pop();
			if(mark[now.first])
				continue;
			mark[now.first] = 1;
			int pos = in[now.first].first;
			if(pos+now.second>=d) {
				flag = 1;
				break;
			}
			int range = 1+pos;//now.second/2;
			int l1 = lower_bound(in.begin(),in.end(),pii(range,0),comp2) - in.begin();
			int l2 = upper_bound(in.begin(),in.end(),pii(now.second+pos,0),comp2) - in.begin();
			for(int i=l1;i<l2;i++) {
				int l = min(in[i].first-pos,in[i].second);
				if(l+in[i].first>=d) {
					flag = 1;
					break;
				}
				pq.push(pii(i,l));
			}
			if(flag)
				break;
		}
		cout<<"Case #"<<tn+1<<": ";
		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}
