#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <queue>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cctype>
using namespace std;

#define llong long long

int n;

llong solveeasy(vector<llong> a, vector<llong> b) {
	llong ret=1LL<<62;
	sort(a.begin(),a.end());
	do {
		llong res=0;
		for(int i=0;i<n;i++) res+=a[i]*b[i];
		ret=min(ret,res);
	} while(next_permutation(a.begin(),a.end()));
	return ret;
}

llong abs(llong a) {
	if(a<0) return -a;
	return a;
}

vector<llong> positive(vector<llong> a) {
	vector<llong> ret;
	for(int i=0;i<a.size();i++)
		ret.push_back(abs(a[i]));
	sort(ret.begin(),ret.end(),greater<llong>());
	return ret;
}

llong solvehard(vector<llong> a, vector<llong> b) {
	vector<llong> pa, na, pb, nb;
	int za=0, zb=0;
	
	for(int i=0;i<n;i++) if(a[i]>0) pa.push_back(a[i]);
	else if(a[i]<0) na.push_back(a[i]);
	else za++;
		
	for(int i=0;i<n;i++) if(b[i]>0) pb.push_back(b[i]);
	else if(b[i]<0) nb.push_back(b[i]);
	else zb++;
	
	sort(pa.begin(),pa.end(),greater<int>());
	sort(nb.begin(),nb.end());
	
	sort(pb.begin(),pb.end(),greater<int>());
	sort(na.begin(),na.end());
	llong ret=0;
	while(pa.size()>0&&nb.size()>0) {
		ret+=pa[0]*nb[0];
		pa.erase(pa.begin());
		nb.erase(nb.begin());
	}
	
	while(na.size()>0&&pb.size()>0) {
		ret+=na[0]*pb[0];
		na.erase(na.begin());
		pb.erase(pb.begin());
	}
	if((na.size()+pa.size()==0)||(nb.size()+pb.size())==0) return ret;
	
	if(na.size()!=0&&pa.size()!=0||nb.size()!=0&&pb.size()!=0) cout<<"NOOO"<<endl;
	
	if(pa.size()==0) pa=positive(na);
	if(pb.size()==0) pb=positive(nb);
	
	while(za&&pb.size()>0) {
		za--;
		pb.erase(pb.begin());
	}
	
	while(zb&&pa.size()>0) {
		zb--;
		pa.erase(pa.begin());
	}
	
	if(pa.size()==0||pb.size()==0) return ret;
	
	if(pa.size()!=pb.size()) cout<<"FUCK"<<endl;
	for(int i=0;i<pa.size();i++) ret+=pa[i]*pb[pa.size()-1-i];
	return ret;
}

int main() {
	int cases;
	cin>>cases;
	for(int tc=1;tc<=cases;tc++) {
		cin>>n;
		vector<llong> a(n), b(n);
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		cout<<"Case #"<<tc<<": "<<solvehard(a,b)<<endl;
	}
}
