#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
using namespace std;
int mark[1024];
int prime[1024],cnt=0;
int main(){
	int cases;
	scanf("%d",&cases);
	memset(mark,0,sizeof(mark));
	for(int i=2;i<1024;++i){
		if(mark[i]==0){
			prime[cnt++]=i;
//			printf("%d\n",i);
			for(int j=i+i;j<1024;j+=i){
				mark[j]=1;
			}
		}
	}
	for(int T=1;T<=cases;++T){
		int N;
		memset(mark,0,sizeof(mark));
		scanf("%d",&N);
		int ans=0;
		if(N>1){
			ans=1;
			for(int i=0;i<cnt&&prime[i]<=N;++i){
				int M=N;
				int tmp=0;
				while(prime[i]<=M){
					M/=prime[i];
					++tmp;
				}
				ans+=tmp-1;
			}
		}
		printf("Case #%d: %d\n",T,ans);
	}
	return 0;
}
