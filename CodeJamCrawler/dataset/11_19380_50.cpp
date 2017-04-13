#include<stdio.h>
#include<vector>

using namespace std;

int main(){
	int nt,c,d,n;
	char combine[50][5];
	char opposed[50][5];
	char list[200];
	
	scanf("%d",&nt);
	for(int t=0;t<nt;t++){
		scanf("%d",&c);
		for(int i=0;i<c;i++){
			scanf("%s",&combine[i]);	
		}	
		scanf("%d",&d);
		for(int i=0;i<d;i++){
			scanf("%s",&opposed[i]);
		}
		scanf("%d",&n);
		scanf("%s",&list);
		
		vector<char> result;
		for(int i=0;i<n;i++){
			//printf("---%d\n",result.size());			
			//printf("---%c\n",list[i]);

			if(result.size()==0){
				result.push_back(list[i]);
				//printf("%c\n",result[0]);
			}
			else{
	
				char last1 = result[result.size()-1];
				char last2 = list[i];
				
				result.push_back(list[i]);
					
				bool lanjut = false;
				for(int j=0;j<c;j++){
					if( (last1==combine[j][0] && last2==combine[j][1]) || (last1==combine[j][1] && last2==combine[j][0]) ){
						result.pop_back();
						result.pop_back();
						result.push_back(combine[j][2]);
						lanjut = true;
						break;
					}
				}
				
				if(lanjut) continue;
				last2 = result[result.size()-1];
				
				for(int j=0;j<d;j++){
					for(int k=0;k<(int)result.size()-1;k++){
						if( (result[k]==opposed[j][0] && last2==opposed[j][1]) || (result[k]==opposed[j][1] && last2==opposed[j][0]) )					{
							result.clear();
							lanjut = true;
							break;
						}
					}
					if(lanjut) continue;
				}
			}
			
			/*for(int j=0;j<result.size();j++){
				if(j==0){
					printf("%c",result[j]);
				}
				else{
					printf(", %c",result[j]);	
				}
			}
			printf("\n");*/
		}
		
		printf("Case #%d: [",t+1);
		for(int i=0;i<result.size();i++){
			if(i==0){
				printf("%c",result[i]);
			}
			else{
				printf(", %c",result[i]);	
			}
		}
		printf("]\n");
	}
	return 0;	
}