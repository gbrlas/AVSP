#include <iostream>
using namespace std;
#define MAX 100
int R,K,N;
int g[MAX];
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int tc;
	scanf("%d",&tc);
	for (int ii=1;ii<=tc;ii++){
		printf("Case #%d: ",ii);
		scanf("%d%d%d",&R,&K,&N);
		for (int i=0;i<N;i++) scanf("%d",&g[i]);
		int head=0;
		int ans=0;
		while (R--){
			int tmp=g[head];
			int headtmp=(head+1)%N;
			while (headtmp!=head&&tmp+g[headtmp]<=K) {
				tmp+=g[headtmp];
				headtmp=(headtmp+1)%N;
			}
			ans+=tmp;
			head=headtmp;
		}
		printf("%d\n",ans);
	}
	return 0;
}