#include <stdio.h>

char einfo[5010][20];

int main(){
	int el,ed,en;
	char erule[100000];
	int i,j,k;

	while(scanf("%d%d%d",&el,&ed,&en)==3){
		for(i=0;i<ed;i++)
			scanf("%s",einfo[i]);
		for(i=0;i<en;i++){
			int ans=0;
			scanf("%s",erule);
			for(j=0;j<ed;j++){
				int offset=0;
				bool flag;
				for(k=0;k<el;k++){
					flag=false;
					if(erule[offset]!='('){
						if(erule[offset]==einfo[j][k])
							flag=true;
			//			printf("==> %d %d %c\n",j,k,erule[offset]);
						offset++;
					}
					else{
						offset++;
						while(erule[offset]!=')'){
			//				printf("===> %d %d %c\n",j,k,erule[offset]);
							if(erule[offset]==einfo[j][k])
								flag=true;
							offset++;
						}
						offset++;
					}
					if(!flag)
						break;
				}
				if(k==el)
					ans++;
			}
			printf("Case #%d: %d\n",i+1,ans);
		}
	}
	return 0;
}
