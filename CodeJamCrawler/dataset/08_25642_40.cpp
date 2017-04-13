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
		cout<<"Case #"<<tc<<": "<<solveeasy(a,b)<<endl;
		/*
		vector<llong> pa, na, pb, nb;
		int za=0, zb=0;
		for(int i=0;i<n;i++) if(a[i]>0) pa.push_back(a[i]);
		else if(a[i]<0) na.push_back(a[i]);
		else za++;
		
		for(int i=0;i<n;i++) if(b[i]>0) pb.push_back(b[i]);
		else if(b[i]<0) nb.push_back(b[i]);
		else zb++;
		cout<<"
		*/
	}
}
