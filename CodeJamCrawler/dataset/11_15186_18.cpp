#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
using namespace std;

struct str{
	double diff;
	int len;
	int w;
	bool operator<(const str& o)const{
		return diff<o.diff;
	}
};

int len[1111];
int w[1111];
str all[1111];

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int ntests;
	cin>>ntests;
	for(int testnum=0; testnum<ntests; testnum++){
		int X, S, R, tt, N;
		cin>>X>>S>>R>>tt>>N;
		double t = tt;
		int tb, te;
		int sum = 0;
		int nall = 0;
		double t0 = 0.0;
		for(int i=0; i<N; i++){
			cin>>tb>>te>>w[i];
			len[i] = te-tb;
			sum+=len[i];
			t0+=double(len[i])/double(S+w[i]);
			all[nall].len = len[i];
			all[nall].diff = double(R-S)/double((S+w[i])*(R+w[i]));
			all[nall].w = w[i];
			nall++;
		}
		t0 += double(X-sum)/double(S);
		all[nall].len = X-sum;
		all[nall].diff = double(R-S)/double(S*R);
		all[nall].w = 0;
		nall++;
		sort(&all[0],&all[nall]);
		for(int i=nall-1; i>=0; i--){
			if(t<=0.0) break;
			double tmp = double(all[i].len)/double(R+all[i].w);
			double tx = min(t,tmp);
			double lx = tx*double(R+all[i].w);
			t0-=(lx*all[i].diff);
			t-=tx;
		}
		cout<<"Case #"<<testnum+1<<": "<<setiosflags(ios::showpoint|ios::fixed)<<setprecision(7)<<t0<<endl;
	}
	return 0;
}