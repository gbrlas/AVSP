//#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cctype>

using namespace std;

int dx=200,dy=200;
int a[400][400];
int i,j,k,l,o,p,n,m;

int getans(int i,int j){
	int q,w,e,r,t=0;
	for (q=1;q<=n;q++)
	for (w=1;w<=q;w++){
		e=2*i-q;
		r=w;
		if (a[e+dx][r+dy]!=-1&&a[e+dx][r+dy]!=a[q+dx][w+dy]) return 10000;
		e=q;
		r=w+q-i+(j-w)*2;
		if (a[e+dx][r+dy]!=-1&&a[e+dx][r+dy]!=a[q+dx][w+dy]) return 10000;
		t=max(t,abs(i-q));
		t=max(t,abs(j-w));
	}
	return t*2+1;
}

int getmax(int i,int j){
	int q,w,e=0;
	for (q=1;q<2*n;q++)
	for (w=1;w<2*n;w++)
	if (a[q][w]!=-1) e=max(e,abs(i-q)+abs(j-w));
	return e+1;
}

bool check(int i,int j){
	int q,w,e,r;
	for (q=1;q<2*n;q++)
	for (w=1;w<2*n;w++)
	if (a[q][w]!=-1){
		e=2*i-q;r=w;
		if (e>=0&&e<2*n&&a[e][r]!=-1&&a[e][r]!=a[q][w]) return false;
		e=q;r=2*j-w;
		if (r>=0&&r<2*n&&a[e][r]!=-1&&a[e][r]!=a[q][w]) return false;
	}
	return true;
}

int main(){
	int T=0;
	for (scanf("%d",&o);o--;){
		scanf("%d",&n);
		memset(a,-1,sizeof(a));
		for (i=1;i<=n;i++){
			j=n-i+1;
			for (k=1;k<=i;k++){
				scanf("%d",&a[i][j]);
				j+=2;
			}
		}
		for (i=n+1;i<2*n;i++){
			j=1+i-n;
			for (k=1;k<=2*n-i;k++){
				scanf("%d",&a[i][j]);
				j+=2;
			}
		}
		/*for (i=1;i<2*n;i++){
			for (j=1;j<2*n;j++) printf("%d ",a[i][j]);
			printf("\n");
		}*/
		l=10000;
		for (i=1;i<2*n;i++)
		for (j=1;j<2*n;j++){
			if (!check(i,j)) continue;
			l=min(l,getmax(i,j));
		}
		T++;
		printf("Case #%d: ",T);
		printf("%d\n",l*(l-1)/2+l*(l+1)/2-n*(n-1)/2-n*(n+1)/2);
	}
	return 0;
}
