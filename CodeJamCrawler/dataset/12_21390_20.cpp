#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int x[20],y[20],r[20];
int n,w,l;

long long sqr(int x){
	long long t=x;
	return t*t;
}

bool cross(int a, int b){
	long long t1=sqr(x[a]-x[b]);
	long long t2=sqr(y[a]-y[b]);
	//cout<<t1+t2<<endl;
	if (t1+t2<sqr(r[a]+r[b])) return true;
	return false;
}

bool check(int x){
	for (int i=0; i<x; ++i)
		if (cross(i,x)) return false;
	return true;
}

int main(){
	int test=0;
	scanf("%d",&test);
	for (int T=1; T<=test; ++T){
		scanf("%d %d %d",&n,&w,&l);
		for (int i=0; i<n; ++i)
			scanf("%d",r+i);
		int now=0;
		while (1){
			if (now==n) break;
			int ok=0;
			for (int i=0; i<1000; ++i){
				x[now]=(rand()*32768+rand())%w;
				y[now]=(rand()*32768+rand())%l;
				if (check(now)){
					ok=1;
					break;
				}
			}
			if (ok) ++now; else now=0;
		}
		printf("Case #%d: ",T);
		for (int i=0; i<n; ++i){
			if (i) printf(" ");
			printf("%d %d", x[i], y[i]);
		}
		printf("\n");
	}
}
