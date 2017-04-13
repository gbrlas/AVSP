#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>

using namespace std;

long long a[200];
long long len;
long long i,j,k,l,o,p,n,m;
long long d[100000];
long long num[100000];
bool vi[100000];

void relax2(int i,long long j){
	if (d[i]==-1||d[i]>j) d[i]=j;
}

void relax(int i){
	int q;
	for (q=0;q<n;q++){
		if (i+a[q]<m) relax2(i+a[q],d[i]+1);
		else relax2(i+a[q]-m,d[i]);
	}
}

int main(){
	int T=0;
	for (cin>>o;o;o--){
		T++;
		cout<<"Case #"<<T<<": ";
		cin>>len>>n;
		for (i=0;i<n;i++) cin>>a[i];
		sort(a,a+n);
		n--;
		m=a[n];
		for (i=0;i<m;i++) d[i]=-1;
		memset(vi,false,sizeof(vi));
		d[0]=0;
		num[0]=0;
		for (;;){
			for (i=0;i<m;i++) if (d[i]!=-1&&!vi[i]) break;
			if (i==m) break;
			for (j=i+1;j<m;j++) if (d[j]!=-1&&!vi[j]&&d[j]<=d[i]) i=j;
			relax(i);
			vi[i]=true;
		}
		if (d[len%m]==-1||num[len%m]>len/m) cout<<"IMPOSSIBLE\n";
		else {
			//cout<<d[len%m]<<' '<<len/m-num[len%m]<<' ';
			cout<<d[len%m]+len/m<<endl;
		}
	}
    return 0;
}
