#include<stdio.h>

int main(){
	int nt,n,m;
	int data[110][110];

	scanf("%d",&nt);
	for(int t=0;t<nt;t++){
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d",&data[i][j]);	
			}	
		}	
		
		bool canCut = true;
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				// kolom
				bool okKolom = true;
				for(int k=0;k<n;k++){
					if(data[k][j] > data[i][j]){
						okKolom = false;	
					}
				}

				// baris
				bool okBaris = true;
				for(int k=0;k<m;k++){
					if(data[i][k] > data[i][j]){
						okBaris = false;	
					}
				}
				
				if(!okBaris && !okKolom) canCut = false;
				
				if(!canCut) break;
			}	
			if(!canCut) break;
		}
		
		printf("Case #%d: ",t+1);
		if(canCut) printf("YES\n");
		else printf("NO\n");
		
	}
	return 0;	
}