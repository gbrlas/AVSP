#include <stdio.h>
#include <malloc.h>
#include <string.h>


int contains(char *str, char c)
{
	//printf("into contains \n");
	fflush(stdout);
	int k =0;
	while(str[k] != '\0')
	{
		//printf("c=%c str[%d] = %c\n" , c , k , str[k]);
		if(c==str[k++]) return 1;
	}	
	return 0;

}




int main()
{
	int L, d , n, i , j , k , state , m , l;
	char **words;
	char *temp;
	char **pattern;
	int match = 0;
	int nummatches;
	
	scanf("%d %d %d" , &L , &d , &n);
	//printf("l=%d d=%d n=%d\n" , L , d, n );
	words = (char **) malloc( d* sizeof(char *));
	for( i =0; i< d ; i++)
	{
		words[i] = (char *)malloc((L+1)*sizeof(char) );
		scanf("%s" , words[i]);
		//printf("words[%d] = %s\n" , i , words[i]);
	}	
	temp = (char *)malloc(1500);
	for(i=0;i<n;i++)
	{	
		scanf("%s", temp);
		//printf("temp = %s\n" , temp);
		j=0; k =0; state = 0;
		l=0;
		pattern = (char **)malloc(L*sizeof(char *) );
		char *temp2 = (char *)malloc(1500*sizeof(char) );
		for(k=0;k<strlen(temp) ;k++ )
		{
			//printf("State = %d c=%c\n" , state , temp[k]);
			switch(state)
			{
				case 0:
				{
					if(temp[k] == '(' ) 
						state = 1;
					else
					{
						pattern[j] = (char *)malloc(2*sizeof(char) );
						pattern[j][0] = temp[k];
						pattern[j][1] = '\0';
						//printf("pattern[%d]=%s \n",j, pattern[j] );
						j++;
					}	
					break;
				}	
				case 1:
				{
					if(temp[k] == ')' ) 
					{	
						state = 0;
						temp2[l] = '\0';
						pattern[j] = (char *)malloc(( strlen(temp2)+1 )*sizeof(char) );
						//printf("temp2 = %s strlen = %d\n" , temp2 , strlen(temp2));
						strcpy(pattern[j++] , temp2);
						//printf("pattern[%d]=%s \n",j-1, pattern[j-1] );
						l=0;
					}	
					else
						temp2[l++] = temp[k];
					break;
				}
			}
		}
		
		
		//printf("\tpattern[0] = %s\n " , pattern[0]);
		nummatches = 0;
		match = 1;
		for( m =0;m< d ; m++)
		{
			match = 1;
			//for each word check whether it matches the pattern
			//printf("word = %s\n" , words[m]);
			k=0;
			//printf("l=%d k= %d \n" , L , k);
			while(match  == 1 && k<L)
			{
				//printf("pattern[%d] = %s\n" , k , pattern[k] );
				match = contains(pattern[k] , words[m][k]);
				//printf("match = %d\n" , match);
				k++;
			}	
			if(match == 1 && k==L) 
				nummatches++;
			
		}
		
		printf("Case #%d: %d" , i+1 , nummatches);
		if( i < n-1) printf("\r\n");
		free(pattern);
		free(temp2);
		
	}


}
