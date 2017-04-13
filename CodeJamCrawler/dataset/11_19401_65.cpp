#include<stdio.h>

int main(){
	int nt,r,c;
	char data[60][60];
	
	scanf("%d",&nt);
	for(int t=0;t<nt;t++){
		scanf("%d %d",&r,&c);
		for(int i=0;i<r;i++){
			scanf("%s",data[i]);	
		}	
		
		for(int i=0;i<r-1;i++){
			for(int j=0;j<c-1;j++){
				if(data[i][j]=='#' && data[i+1][j]=='#' && data[i][j+1]=='#' && data[i+1][j+1]=='#'){
					data[i][j]='/'; data[i+1][j]='\\'; data[i][j+1]='\\'; data[i+1][j+1]='/'; 	
				}
			}	
		}
		
		bool impossible = false;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(data[i][j]=='#'){
					impossible = true;
					break;	
				}
			}	
			if(impossible) break;
		}
		/*for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				printf("%c",data[i][j]);	
			}
			printf("\n");
		}*/	
		
		printf("Case #%d:\n",t+1);
		if(impossible){
			printf("Impossible\n");	
		}
		else{
			for(int i=0;i<r;i++){
				for(int j=0;j<c;j++){
					printf("%c",data[i][j]);	
				}
				printf("\n");
			}	
		}
	}
	return 0;
}	