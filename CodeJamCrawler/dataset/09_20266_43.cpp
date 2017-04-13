#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int L,D,N;	
	char ch;
      
      scanf("%d%d%d",&L,&D,&N);      
      scanf("%c",&ch);
      
	int i,j;
	char A[D][L];
	for(i=0;i<D;i++){
		for(j=0;j<L;j++){
			scanf("%c",&A[i][j]);
//                  printf("%c",A[i][j]);
            }
		scanf("%c",&ch);
//            printf("\n");
	}
      
      int n;
	for(n=0;n<N;n++){
//		char *str = (char *)malloc( sizeof(char) *L*D );
//		scanf("%s",str);   
            scanf("%c",&ch);      
            
		char flags[D];
		for(i=0;i<D;i++) flags[i] = 1;

		int j = 0;
		
		while( ch != '\n' && ch!=EOF ){
//			printf("%c",ch);
			if(ch == '('){
                        scanf("%c",&ch);
				while( ch != ')'){
                            for(i=0;i<D;i++)
                                 if( flags[i] == 1 | flags[i] == 3 )
                                     if( A[i][j] == ch ){ 
//                                        printf(" twiced @ %d,%d with A[%d][%d] = %c\n",i,j,i,j, A[i][j]);
                                        flags[i] = 2; 
                                     }
                                 scanf("%c",&ch);                      
                        }
                        for(i=0;i<D;i++){
                          	if( flags[i] == 1 | flags[i] == 3 ){
//                          		printf(" flag[%d] or zeroed @ j=%d \n",i,j);
                          		flags[i] = 0;
                          	}
                          	else if( flags[i] == 2 ) flags[i] = 3;	
                        }                        
			}
			
			else{
				for(i=0;i<D;i++){
					if( flags[i] > 0)
						if( A[i][j] != ch ){
//                                       printf(" zeroed @ %d,%d with A[%d][%d] = %c\n",i,j,i,j, A[i][j]);
                                        flags[i] = 0;
                                    }                                    
				}
			}
			j++;
			scanf("%c",&ch);
		}
            
//		printf("\n\nflags -> [ ");
            int tot = 0;
		for(i=0;i<D;i++){
//                  printf("%d ",flags[i] );
                  if( flags[i] ) tot++;
            }

//		printf("]\n\n-----------------------------------------------------------------\n");
            printf("Case #%d: %d\n",n+1,tot);
	}     

	return 0;
}

