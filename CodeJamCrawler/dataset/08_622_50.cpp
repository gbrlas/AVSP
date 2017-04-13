#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int maxn=200;
int t;
struct Trip {
	int start,end;
	int from;
};
struct Train {
	int stop;
	int start;
};
inline bool operator<(const Trip& t1,const Trip& t2) {
	return t1.start<t2.start||(t1.start==t2.start&&t1.end<t2.end);
}
inline int timeint(const string& str) {
	return ((str[0]-'0')*10+(str[1]-'0'))*60+(str[3]-'0')*10+str[4]-'0';
}
Trip trip[maxn+1];
Train train[maxn+1];
int tnums;

int get_train(int start,int from) {
	int r=-1;
	int starttime=999999;
	for(int i=0;i<tnums;i++) {
		if(train[i].stop==from) {
			if(train[i].start<=start) {
				if(starttime>train[i].start) {
					starttime=train[i].start;
					r=i;
				}
			}
		}
	}
	return r;
}

int main() {
	int na,nb;
	int n;
	cin>>n;
	for(int tc=1;tc<=n;tc++) {
		cin>>t;
		cin>>na>>nb;
		int from[2];
		memset(from,0,sizeof from);
		string s1,s2;
		for(int i=0;i<na;i++) {
			cin>>s1>>s2;
			trip[i].start=timeint(s1);
			trip[i].end=timeint(s2);
			trip[i].from=0;
		}
		for(int i=na;i<na+nb;i++) {
			cin>>s1>>s2;
			trip[i].start=timeint(s1);
			trip[i].end=timeint(s2);
			trip[i].from=1;
		}
		sort(trip,trip+na+nb);
		tnums=0;
		for(int i=0;i<na+nb;i++) {
			int r=get_train(trip[i].start,trip[i].from);
			//if(i==1) cout<<r<<train[r].start<<endl;
			if(r==-1) {
				//no train
				train[tnums].start=trip[i].end+t;
				train[tnums].stop=trip[i].from^1;
				from[trip[i].from]++;
				tnums++;
			}else{
				train[r].start=trip[i].end+t;
				train[r].stop=trip[i].from^1;
			}
		}
		cout<<"Case #"<<tc<<": "<<from[0]<<' '<<from[1]<<endl;
	}
	return 0;
}


