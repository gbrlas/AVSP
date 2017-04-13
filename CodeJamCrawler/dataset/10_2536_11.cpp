//#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>

using namespace std;

int i,j,k,l,o,p,n,m;
int a[10],ans;

int check(int A,int p){
	if (a[0]>=p) return -1;
	if (n==1) return -1;
	int B=(a[1]-a[0]*A)%p;
	for (int q=1;q<n;q++){
		if (a[q]!=((a[q-1]*A+B)%p+p)%p) return -1;
	}
	return ((a[n-1]*A+B)%p+p)%p;
}

int main(){
	int T=0;
	for (scanf("%d",&o);o--;){
		T++;
		printf("Case #%d: ",T);
		scanf("%d%d",&m,&n);
		for (i=0;i<n;i++) scanf("%d",&a[i]);
		if (m==1) m=10;
		if (m==2) m=100;
		if (m==3) m=1000;
		if (m==4) m=10000;
		ans=-1;
		for (i=2;i<m;i++){
			for (j=2;j<i;j++) if (i%j==0) break;
			if (j!=i) continue;
			for (j=0;j<i;j++){
				k=check(j,i);
				if (k==-1) continue;
				if (ans==-1) ans=k;
				else if (k!=ans) ans=-2;
			}
		}
		if (ans>=0) printf("%d\n",ans);
		else printf("I don't know.\n");
	}
    return 0;
}
