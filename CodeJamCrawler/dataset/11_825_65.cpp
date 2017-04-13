#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <iostream>
#include <cstring>
#include <set>
using namespace std;

#define MAXN 1000010
#define INF (long long)1e15
int dist[MAXN],c[MAXN];

int main(){
	int cases=1,L,N,C;
	long long t,csum,f;
	cin>>cases;
	for(int cas=1;cas<=cases;cas++){
		long long res=INF,sum=0;
		cin>>L>>t>>N>>C;
		for(int i=0;i<C;i++) scanf("%d",&c[i]);
		for(int i=0;i<N;i++){
			dist[i]=c[i%C];
		}
		
		res=0;
		int s=-1,ext;
		for(int i=0;i<N;i++){
			if(res+2*dist[i]>t){
				if(res>t) ext=0;
				else ext=t-res;
				res+=ext;
				dist[i]=dist[i]-ext/2;
				s=i;
				break;
			}
			res+=(2*dist[i]);
		}
		
		if(s!=-1){
			sort(dist+s,dist+N);
			for(int i=N-1,j=0;i>=s;i--,j++){
				if(j<L){
					res+=(dist[i]);
				} else{
					res+=(2*dist[i]);
				}
			}
		}
		printf("Case #%d: %lld\n",cas,res);
	}
	return 0;
}
