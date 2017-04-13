#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 500


long findSS( char *str , char *search)
{
	long **arr;
	int i , j;
	int h = strlen(str) +1;
	int w = strlen(search) ;
	arr = (long **)malloc( h* sizeof(long *) );
	
	for( i = 0 ;i<h ;i++)
		arr[i] = (long *)malloc( w* sizeof(long));
	for( i=0 ; i<h ; i++)
		for(j=0 ; j<w;j++)
			arr[i][j] = 0;
	
	for( i = 0; i< h ;i++)
	{
		for( j= 0; j<w ;j++ )
		{
			if( i==0 )
				arr[i][j] = 0;
			
			else
			{
				if( j!= w-1)
				{	
					if( str[strlen(str) - i ]==search[j] )
						arr[i][j] = arr[i-1][j] + arr[i-1][j+1];
					else
						arr[i][j] = arr[i-1][j];	
				}		
				else
				{
					if( str[strlen(str) - i ]==search[j] )
						arr[i][j] = 1+arr[i-1][j];	
					else
						arr[i][j] = arr[i-1][j];	
				}	
				
			}	
		}	
	
	}
	
//  	for( i=0 ; i<h ; i++)
//  	{	
//  		for(j=0 ; j<w;j++)
//  			printf("%3ld " , arr[i][j]);
//  		printf("\n");
//  	}

	return arr[h-1][0];
}

int main() 
{
	int n , i;
	char *str;
	char *search = "welcome to code jam";
	long result;
	scanf("%d" , &n);
	//printf("n = %d\n" , n );
	str = (char *) malloc( (MAXLEN+1)*sizeof(char));
	fgets(str , MAXLEN , stdin);
	for( i =0 ; i <n ;i++)
	{
		
		fgets(str , MAXLEN , stdin);
		if(str[strlen(str)-1] == '\n')
			str[strlen(str)-1] = '\0';
		//printf( "str = %s\n" , str);
 		result = findSS( str , search );
		
//  		printf("Result :%ld\n\n", result);
		printf("Case #%d: ", i+1);
		int temp = (result/1000)%10;
		printf("%c", 48 +temp);
		temp = (result/100)%10;
		printf("%c", 48 +temp);
		temp = (result/10)%10;
		printf("%c", 48+temp);
		temp = (result)%10;
		printf("%c\r\n", 48 +temp);
	
	}	
	free(str);







}
