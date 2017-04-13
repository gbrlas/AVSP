#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<string>
using namespace std;

int getit(void)
{
	int n;
	scanf("%d", &n);
	vector<int> x;
	vector<int> y;
	int r;
	for (int i=0; i<n; i++) {
		scanf("%d", &r);
		x.push_back(r);
	}	
	for (int i=0; i<n; i++) {
		scanf("%d", &r);
		y.push_back(r);
	}	
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	reverse(y.begin(),y.end());
	int res=0;
	for (int i=0; i<n; i++)
		res += x[i]*y[i];
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
