#include<stdio.h>
#include<algorithm>

using namespace std;

long long motes[1000010];

int main(){
	int nt,n;
	long long start;
	
	
	scanf("%d",&nt);
	for(int t=0;t<nt;t++){
		scanf("%lld %d",&start,&n);
		for(int i=0;i<n;i++){
			scanf("%lld",&motes[i]);	
		}	
		sort(motes,motes+n);
		
		int total = 0;
		long long now = start;
		for(int i=0;i<n;i++){
			if(	now > motes[i]){
				now += motes[i];
			}	
			else{
				int maks = n - i;
				int cnt = 0;
				for(int j=0;j<maks;j++){
					now += now - 1;
					cnt++;
					if(now > motes[i]){
						now+=motes[i];
						break;	
					}
				}	
				total+=min(maks,cnt);
				if(cnt == maks){
					break;
				}
			}
		}
		printf("Case #%d: %d\n",t+1,total);
	}
	return 0;
}	