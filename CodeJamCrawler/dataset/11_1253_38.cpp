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

const int N = 1005;
struct Node{
	double b,e,w;
}node[N];
int X,S,R,T,n;


bool cmp(const Node &x,const Node &y){
	return (x.w+R)*x.w<(y.w+R)*y.w;
}
int main(){
	freopen("A-large.in","r",stdin);
	//freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,k,t,nc = 0;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d%d",&X,&S,&R,&T,&n);
		int len = X;
		for(i = 0;i<n;i++){
			scanf("%lf%lf%lf",&node[i].b,&node[i].e,&node[i].w);
			len -= node[i].e-node[i].b;
			node[i].e -= node[i].b;
			node[i].w += S;
		}
		node[n].b = 0;
		node[n].e = len;
		node[n].w = S;
		n++;
		sort(node,node+n,cmp);
		R -= S;
		double now = 0;
		for(i = 0;i<n;i++){
			double t0 = node[i].w+R;
			double t1 = node[i].e/t0;
			if(t1+now<T){
				now += t1;
				node[i].e = 0;
			}else{
				node[i].e *= 1-(T-now)/t1;
				now = T;
				break;
			}
		}
		double ans = now;
		for(i = 0;i<n;i++){
			ans += node[i].e/node[i].w;
		}
		printf("Case #%d: %.8lf\n",++nc,ans);
	}
	return 0;
}