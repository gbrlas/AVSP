#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<int> atime[2], btime[2];

int t,na,nb;

int firsttime(int mytime, int idx) {
	if(idx==0) {
		for(int i=0;i<atime[0].size();i++) if(atime[0][i]>=mytime) return i;
	}
	else {
		for(int i=0;i<btime[0].size();i++) if(btime[0][i]>=mytime) return i;
	}
	return -1;
}

void eval(int mytime, int place) {
	while(true) {
		int idx=firsttime(mytime,place);
		//cout<<"FDFSDFSDAFSDA     "<<idx<<','<<place<<"      "<<mytime<<endl;
		if(idx==-1) return;
		int nexttime;
		if(place==0) {
			nexttime=atime[1][idx]+t;
			atime[0].erase(atime[0].begin()+idx);
			atime[1].erase(atime[1].begin()+idx);
		} else {
			nexttime=btime[1][idx]+t;
			btime[0].erase(btime[0].begin()+idx);
			btime[1].erase(btime[1].begin()+idx);
		}
		mytime=nexttime;
		place=1-place;
	}
}

void solve() {
	int aret=0, bret=0;
	while(atime[0].size()+btime[0].size()>0) {
		//cout<<"DOGGY "<<atime[0].size()<<' '<<btime[0].size()<<endl;
		if(btime[0].size()==0||(atime[0].size()>0&&(atime[0][0]<btime[0][0]||(atime[0][0]==btime[0][0]&&atime[1][0]<=btime[1][0])))) {
			//cout<<"***"<<atime[0][0]<<endl;
			aret++;
			eval(atime[0][0],0);
		} else {
			//cout<<"+++"<<btime[0][0]<<endl;
			bret++;
			eval(btime[0][0],1);
		}
	}
	cout<<aret<<' '<<bret<<endl;
}

int main() {
	int cases;
	cin>>cases;
	int a,b;
	char c;
	for(int tc=1;tc<=cases;tc++) {
		cin>>t;
		cin>>na>>nb;
		for(int i=0;i<na;i++) {
			cin>>a>>c>>b;
			atime[0].push_back(a*60+b);
			cin>>a>>c>>b;
			atime[1].push_back(a*60+b);
		}
		for(int i=0;i<nb;i++) {
			cin>>a>>c>>b;
			btime[0].push_back(a*60+b);
			cin>>a>>c>>b;
			btime[1].push_back(a*60+b);
		}
		for(int i=0;i<atime[0].size();i++)
			for(int j=0;j+1<atime[0].size();j++)
			if(atime[0][j]>atime[0][j+1]||(atime[0][j]==atime[0][j+1]&&atime[1][j]>atime[1][j+1])) {
				swap(atime[0][j],atime[0][j+1]);
				swap(atime[1][j],atime[1][j+1]);
			}
		for(int i=0;i<btime[0].size();i++)
			for(int j=0;j+1<btime[0].size();j++)
			if(btime[0][j]>btime[0][j+1]||(btime[0][j]==btime[0][j+1]&&btime[1][j]>btime[1][j+1])) {
				swap(btime[0][j],btime[0][j+1]);
				swap(btime[1][j],btime[1][j+1]);
			}
		cout<<"Case #"<<tc<<": ";
		solve();
	}
}
