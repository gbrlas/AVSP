#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int N,n,i;
	char ch;
	scanf("%d",&N);
	scanf("%c",&ch);
	
	char *code = (char *)malloc( sizeof(char)*20);
	code = "welcome to code jam";
	
	for( n=0; n<N; n++ ){

		char *token = (char *)malloc( sizeof(char)*500);
		int *count = (int *)malloc( sizeof(int)*500);
		int tk=0;

		scanf("%c",&ch);
		token[tk] = ch;
		count[tk] = 1;
		
		scanf("%c",&ch);
		while( ch != '\n'&& ch != EOF ){
//			printf("%c",ch);
			
			if( ch == token[tk] ) count[tk]++;
			else{
				tk++;				
				token[tk] = ch;
				count[tk] = 1;					
			}

			scanf("%c",&ch);		
		}
		token[ ++tk ] = 0;

		int tot = foo( token, count, code );

//		printf("--------------- total = %d ---------------\n",tot);
		int r4 = tot%10000;
		int r3 = tot%1000;
		int r2 = tot%100;
		int r1 = tot%10;

		printf("Case #%d: %d%d%d%d\n",n+1,(r4-r3)/1000,(r3-r2)/100,(r2-r1)/10,r1);
		free( token );
		free( count );
	}
	return 0;
}

foo( char *token, int *count, char *code ){

//	printf("entered....\n");
	if(*code == 0){
//		printf("returning 1\n");
		return 1;
	}
	int tot = 0;
	while( *token ){
//		printf("# %c %c ",*token,*code);
		if( *token == *code )
			if( *code != 0 )tot += (*count) * foo( token+1, count+1, code+1 );
			else{
//				printf("returning 1\n");
				return 1;
			}
		token++;
		count++;
	}
//	printf("returning %d\n",tot);
	return tot;
}






