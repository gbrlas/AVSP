#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct event {
	int stop;
	int number;

	event(int _stop, int _number):stop(_stop),number(_number) {}

	bool operator<(const event &other) const {
		if(stop != other.stop) return stop<other.stop;
		if(number>0) return true;
		return false;
	}
};

const long long M = 1000002013;
int n;

long long getCost(int nstops) {
	if(nstops==0) return 0;
	long long res = nstops;
	res *= (n+n-nstops+1);
	res /= 2;
	res %= M;
	return res;
}

int main() {
	freopen("Asmall.out","w",stdout);
	int ncases;
	cin>>ncases;
	for(int cid=1;cid<=ncases;++cid) {
		int m,o,e,p;
		vector<event> events;
		cin>>n>>m;
		long long ans = 0;
		for(int i=0;i<m;++i) {
			cin>>o>>e>>p;
			ans = (ans + getCost(e-o)*p%M) % M;
			events.push_back(event(o,p));
			events.push_back(event(e,-p));
		}
		sort(events.begin(),events.end());

		stack<event> cards;
		for(int i=0;i<events.size();++i) {
			if(events[i].number>0) {
				cards.push(events[i]);
			} else {
				int remaining = -events[i].number;
				while(remaining>0) {
					int decrease = min(remaining, cards.top().number);
					ans = (ans - getCost(events[i].stop - cards.top().stop)*decrease%M) % M;
					remaining -= decrease;
					cards.top().number -= decrease;
					if(cards.top().number == 0) cards.pop();
				}
			}
		}
		ans = (ans + M) % M;
		cout<<"Case #"<<cid<<": "<<ans<<endl;
	}
	return 0;
}
