#include<iostream>
#include<cstdio>
#include<cstring>
#include<stdlib.h>
using namespace std;
__int64 R,K,N;//R£º´ÎÊý
__int64 T;
__int64	sum[1005];
__int64 cc[1005];
__int64 a[1005];
__int64 total;
int OK(int a){
	if(a>N) return 1;
	return a;
}
int main(){
//	freopen("ACM.txt","r",stdin);
//	freopen("ACM.out","w",stdout);
	switch(1){
	case 1:{
				scanf("%I64d",&T);
				__int64 cas = 1;
				__int64 i,j,k,tmp,c,kk;
				__int64 maxt;
				while(T--){
					memset(sum,-1,sizeof(sum));
					memset(cc,0,sizeof(cc));
					scanf("%I64d%I64d%I64d",&R,&K,&N);
					sum[0] = 0;
					maxt = 0;
					for(i=1; i<=N; i++)
					{
						scanf("%lld",&a[i]);
						maxt += a[i];
					}
					if(maxt<=K){
						printf("Case #%I64d: %I64d\n",cas++,R*maxt);
						continue;
					}
					i = 0;
					c = 0;
					while(true){
						k = K;
						j = 0;
						kk = i;
						c++;
						while(k>=a[OK(i+1)]){
							k -= a[OK(i+1)];
							j += a[OK(i+1)];
							i = OK(i+1);
						}
						if(sum[i]!=-1)
						{
							tmp = i;
							c = c-cc[i];
							total = j+sum[kk]-sum[i];
							break;
						}
						cc[i] = c;
						sum[i] = j+sum[kk];
					}
					R-=cc[tmp];
					__int64 ans = sum[tmp]+total*(R/c);
					R = R%c;
					i = tmp;
					while(R--){
						k = K;
						j = 0;
						while(k>=a[OK(i+1)]){
							j += a[OK(i+1)];
							k -= a[OK(i+1)];
							i = OK(i+1);
						}
						ans += j;
					}
					printf("Case #%I64d: %I64d\n",cas++,ans);
				}
				return 0;
		   }
	case 2:{
			scanf("%I64d",&T);
			__int64 cas = 1;
			__int64 i,j,k;
			__int64 maxt;
			while(T--){
				memset(sum,-1,sizeof(sum));
				memset(cc,0,sizeof(cc));
				scanf("%I64d%I64d%I64d",&R,&K,&N);
				sum[0] = 0;
				maxt = 0;
				for(i=1; i<=N; i++)
				{
					scanf("%I64d",&a[i]);
					maxt += a[i];
				}
				if(maxt<=K){
					printf("Case #%I64d: %I64d\n",cas++,R*N);
					continue;
				}
				__int64 ans = 0;
				i = 0;
				while(R--){
					k = K;
					j = 0;
					while(k>=a[OK(i+1)]){
						j += a[OK(i+1)];
						k -= a[OK(i+1)];
						i = OK(i+1);
					}
					ans += j;
				}
				printf("Case #%I64d: %I64d\n",cas++,ans);
			}
			return 0;
		   }
	}
	return 0;
}
