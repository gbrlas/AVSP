#include <stdio.h>

int main(){
	int ecase,ecount;
	int en;
	char input[10000];
	int info[1000];
	int i,j,k;
	int ans;
	scanf("%d",&ecase);
	for(ecount=1;ecount<=ecase;ecount++){
		scanf("%d",&en);
		for(i=0;i<en;i++){
			scanf("%s",input);
			info[i]=0;
			for(j=0;j<en;j++)
				if(input[j]=='1')
					info[i]=j;
		}
		ans=0;
		for(i=0;i<en;i++){
			for(j=i;j<en;j++)
				if(info[j]<=i)
					break;
			for(k=j;k>i;k--){
				int t=info[k];
				info[k]=info[k-1];
				info[k-1]=t;
				ans++;
			}
		}
		printf("Case #%d: %d\n",ecount,ans);
	}
	return 0;
}
