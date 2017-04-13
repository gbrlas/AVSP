#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <utility>

using namespace std;


#define llong long long 
const double pi = acos(-1.0);


int main(){
	freopen("C-large.in","r",stdin);
	//freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,k,t,nc = 0;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int tt = 0,sum = 0,tmin = 1<<30;
		for(i = 0;i<n;i++){
			int tmp;
			scanf("%d",&tmp);
			tt ^= tmp;
			sum += tmp;
			tmin = min(tmin,tmp);
		}
		if(tt)printf("Case #%d: NO\n",++nc);
		else printf("Case #%d: %d\n",++nc,sum-tmin);
	}
	return 0;
}