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
	vector<long long>vec;
	for(long long  i=1;i<=10000000LL;i++){
		int root[50]={};
		long long int g=i; int s=0;
		while(g){
			root[s]=g%10;
			g/=10;
			s++;
		}
		int l=0,r=s-1;
		bool v=true;
		while(l<=r){
			if(root[l]!=root[r]) v=false;
			l++;
			r--;
		}
		if(v){
			s=0;
			long long se=i*i;
			g=se;
		while(g){
			root[s]=g%10;
			g/=10;
			s++;
		}
		int l=0,r=s-1;
		bool v=true;
		while(l<=r){
			if(root[l]!=root[r]) v=false;
			l++;
			r--;
		}
		if(v){vec.pb(se);}
		}
	}
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		long long s,e;
		scanf("%lld %lld",&s,&e);
		int sr=lower_bound(vec.begin(),vec.end(),s)-vec.begin();
		int er=upper_bound(vec.begin(),vec.end(),e)-vec.begin();
		printf("Case #%d: %d\n",i,er-sr);
	}
}