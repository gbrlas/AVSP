#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
int main(){
	int t;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		int n;
		long long a1,a2;
		long long m;
		cin >> n >> m;
		vector<int>vec;
		long long e=1;
		int g=0;
		for(int j=0;j<n;j++) e*=2;
		long long hk=e;
		while(e>m){e/=2;g++;}
		long long hj=1;
		while(g--) hj*=2;
		hj--;
		a2=hk-hj-1;
		if(m==hk) a1=a2;
		else
		{
		long long p=m;
		int fk=0;
		while(p>0)
		{
			p-=hk/2;
			hk/=2;
			fk++;
		}
		hj=1;
		while(fk--) hj*=2;
		hj-=2;
		a1=hj;
		}
		printf("Case #%d: %lld %lld\n",i+1,a1,a2);
	}
}