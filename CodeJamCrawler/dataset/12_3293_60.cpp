/* Google Code Jam 2012 - Qualification Round
 * Problema: B - Dancing With the Googlers
 * Categoria: Ad hoc
 * 
 * Israel Leiva - 14-04-2012
 */
#include <cstdio>

int main(){
	int T, N, S, p, j, googler, resto, resp, i=0, t[100];
	
	scanf("%d\n", &T);
	while(T>0){
		i++;
		printf("Case #%d: ", i);
		
		scanf("%d %d %d\n", &N, &S, &p);
		for(j=0;j<N;j++)
			scanf("%d", &t[j]);
			
		resp=0;
		for(j=0;j<N;j++){
			googler=t[j]/3;
			resto=t[j]%3;
			if(googler>=p)
				resp++;
			else if(resto>0 && googler+1>=p)
				resp++;
			else{
				if(S>0){ 
					if(!resto){
						if(googler+1==p && googler>0){
							resp++;
							S--;
						}
					}else if(resto>1){
						if(googler+2>=p){
							resp++;
							S--;
						}
					}
				}
			}
		}
					
		printf("%d\n", resp);
		T--;
	}
}
