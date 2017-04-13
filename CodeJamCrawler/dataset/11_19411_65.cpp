#include<stdio.h>

int main(){
	int nt,n,l,h;
	int data[110];
	scanf("%d",&nt);
	for(int t=0;t<nt;t++){
		scanf("%d %d %d",&n,&l,&h);
		for(int i=0;i<n;i++){
			scanf("%d",&data[i]);			
		}	
		int ans = -1;
		for(int i=l;i<=h;i++){
			bool ok = true;
			for(int j=0;j<n;j++){
				if(i>data[j]){
					if(i%data[j]!=0){
						ok = false;
						break;	
					}
				}
				else{
					if(data[j]%i!=0){
						ok = false;
						break;	
					}
				}
			}	
			if(ok){
				ans=i;
				break;
			}
		}
		
		printf("Case #%d: ",t+1);
		if(ans==-1){
			printf("NO\n");	
		}
		else{
			printf("%d\n",ans);
		}
	}
	return 0;
}	