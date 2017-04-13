#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void calDec(int &res, vector<double> &naomi, int nb,int ne, vector<double> &ken, int kb,int ke) {
	if(nb>ne) {
		return;
	}
	if(naomi[nb]>ken[kb]) {
		res++;
		calDec(res,naomi,nb+1,ne,ken,kb+1,ke);
	}else {
		calDec(res,naomi,nb+1,ne,ken,kb,ke-1);
	}
}

void cal(int &res, vector<double> &naomi,vector<double> &ken) {
	int lastKen = 0;
	int size = naomi.size();
	for(int i=0;i<size;i++) {
		while(lastKen<size&&ken[lastKen]<naomi[i]) {
			lastKen++;
		}
		if(lastKen>=size) {
			res++;
		}
		lastKen++;
	}}

int main() {
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	int t;
	cin>>t;
	for(int index=1;index<=t;index++) {
		cout<<"Case #"<<index<<": ";
		int n;
		cin>>n;
		vector<double> naomi(n,0);
		vector<double> ken(n,0);
		for(int i=0;i<n;i++) {
			cin>>naomi[i];
		}
		for(int i=0;i<n;i++) {
			cin>>ken[i];
		}
		sort(naomi.begin(),naomi.end());
		sort(ken.begin(),ken.end());
		int decRes=0;
		int res = 0;
		calDec(decRes,naomi,0,n-1,ken,0,n-1);
		cal(res,naomi,ken);
		cout<<decRes<<" "<<res;
		cout<<endl;
	}
	
}