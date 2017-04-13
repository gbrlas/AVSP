#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<string>
using namespace std;

int getit(void)
{
	long long n, A, B, C, D, x0, y0, M;
	scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &n,&A,&B,&C,&D,&x0,&y0,&M);
	vector<long long> vx, vy;
	vx.push_back(x0);
	vy.push_back(y0);
	for (int i=0; i<n-1; i++) {
		x0 = (A*x0+B)%M;
		y0 = (C*y0+D)%M;
		vx.push_back(x0);
		vy.push_back(y0);
	}
	int res=0;
	for (int i=0; i<n; i++)
	for (int j=i+1; j<n; j++)
	for (int k=j+1; k<n; k++) {
		if ((vx[i]+vx[j]+vx[k])%3 == 0 && (vy[i]+vy[j]+vy[k])%3==0)
			res++;
	}
	return res;
}
int main(void)
{
	int ncase;

	scanf("%d", &ncase);
	for (int i=0; i<ncase; i++) {
		int res = getit();
		printf("Case #%d: %d\n", i+1, res);
	}
	return 0;
}
