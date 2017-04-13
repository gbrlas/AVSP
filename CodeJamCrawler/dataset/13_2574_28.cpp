#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct event {
	int type;
	int num;
	int cost;
	int place;
	event(int type, int num, int cost, int place):type(type),num(num),cost(cost),place(place){}
	inline friend int operator <(const event &a, const event &b) {
		if(a.place!=b.place)
			return a.place<b.place;
		return a.type<b.type;
	}
};

const long long mod = 1000002013;

int main() {
	int t;
	cin>>t;
	for(int tn=0;tn<t;tn++) {
		long long n,m;
		cin>>n>>m;
		vector<event> in;
		for(int i=0;i<m;i++) {
			long long o,e,p;
			cin>>o>>e>>p;
			long long len = e-o;
			long long cost = len*n - len*(len-1)/2;
			in.push_back(event(0,p,cost,o));
			in.push_back(event(1,p,cost,e));
		}
		sort(in.begin(),in.end());
		vector<event> stack;
		long long loss = 0;
		for(int i=0;i<in.size();i++) {
			if(in[i].type==0)
				stack.push_back(in[i]);
			else {
				while(in[i].num>0) {
					long long len = in[i].place - stack.back().place;
					long long curcost = len*n - len*(len-1)/2;
					long long curloss =  (stack.back().cost - curcost)%mod;
					int curnum = min(stack.back().num, in[i].num);
					loss = (loss + (curloss * curnum) % mod ) % mod;
					in[i].num -= curnum;
					stack.back().num -= curnum;
					if(stack.back().num==0)
						stack.pop_back();
				}
			}
		}
		loss = ((loss%mod) + mod) % mod;
		cout<<"Case #"<<tn+1<<": "<<loss<<endl;
	}

}
