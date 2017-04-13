#include<stdio.h>

int main(){
	int nt,n;
	int data[1010];
	
	scanf("%d",&nt);
	for(int t=0;t<nt;t++){
		int res = 0;
		int min = 100000000;
		int sum = 0;		
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&data[i]);	
			res^=data[i];
			sum+=data[i];
			if(min>data[i]){
				min=data[i];	
			}
		}	

		int result = -1;
		if(res==0){
			result = sum-min;
		}
	
		if(result==-1){		
			printf("Case #%d: NO\n",t+1);
		}
		else{
			printf("Case #%d: %d\n",t+1,result);
		}

	}
	return 0;	
}