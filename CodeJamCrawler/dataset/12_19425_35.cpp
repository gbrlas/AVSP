#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int main(){
	int nt,N,S,p;
	
	scanf("%d",&nt);
	for(int t=0;t<nt;t++){
		scanf("%d %d %d",&N,&S,&p);
		int nBest = 0;
		int nSurprise = 0;
		for(int i=0;i<N;i++){
			int temp;
			scanf("%d",&temp);
			
			if(p==0){
				if(temp>=0) nBest++;
			}
			else if(p==1){
				if(temp>=1) nBest++;
			}
			else{
				if(temp>=p*3-2){
					nBest++;	
				}	
				else if(temp>=p*3-4){
					nSurprise++;
				}
			}
		}	
		int result = nBest + min(nSurprise,S);
		printf("Case #%d: %d\n",t+1,result);
	}
	
	return 0;
}