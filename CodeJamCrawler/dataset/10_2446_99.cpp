//#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>

using namespace std;

int a[1100];
int i,j,k,l,o,p,n,m;

int gcd(int a,int b){
	if (b==0) return a;
	else return gcd(b,a%b);
}

int main(){
	scanf("%d",&o);
	for (int T=1;T<=o;T++){
		printf("Case #%d: ",T);
		scanf("%d",&n);
		for (i=0;i<n;i++) scanf("%d",&a[i]);
		for (i=0;i<n-1;i++) a[i]=abs(a[i+1]-a[i]);
		p=a[0];
		for (i=1;i<n-1;i++) p=gcd(p,a[i]);
		printf("%d\n",(p-a[n-1]%p)%p);
	}
    return 0;
}
