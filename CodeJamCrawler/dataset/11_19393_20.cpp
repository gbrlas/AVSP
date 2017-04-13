#include<stdio.h>

int main(){
	int nt,pd,pg;
	long long n;
	
	scanf("%d",&nt);
	for(int t=0;t<nt;t++){
		scanf("%lld %d %d",&n,&pd,&pg);
		
		bool ok = false;
		if(n<100){
			if(pd==0) ok = true;
			else{
				for(int i=1;i<=n;i++){
					for(int j=0;j<=i;j++){
						if(j*100 == pd*i) { ok = true; break; }
					}	
				}
			}
			
		}
		else{
			ok = true;	
		}
		
		if(ok){
			//printf("%d %d %d",n,pd,pg);
			if(pg==100 && pd!=100) ok = false;
			if(pg==0 && pd!=0) ok = false;
		}
		
		if(ok) printf("Case #%d: Possible\n",t+1);
		else printf("Case #%d: Broken\n",t+1);
	}
	return 0;	
}