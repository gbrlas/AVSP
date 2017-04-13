#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int ntest,n,s,p,t,ans;
	scanf("%d",&ntest);
	for(int itest=1;itest<=ntest;itest++){
		ans=0;
		scanf("%d%d%d",&n,&s,&p);
		for(int i=0;i<n;i++){
			scanf("%d",&t);
			if(t==0){
				if(p==0) ans++;
			}
			else
				switch(t%3){
				case 0:
					if(t/3>=p) ans++;
					else
						if(s>0 && t/3+1>=p){
							ans++;
							s--;
					}
					break;
				case 1:
					if(t/3+1>=p) ans++;
					break;
				case 2:
					if(t/3+1>=p) ans++;
					else
						if(s>0 && t/3+2>=p){
							ans++;
							s--;
					}
				}
		}
		printf("Case #%d: %d\n",itest,ans);
	}
    return 0;
}
