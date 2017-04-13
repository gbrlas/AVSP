#include<stdio.h>

int main()
{
int mapping[27]={0,25,8,5,19,15,3,22,24,4,21,9,7,12,2,11,18,26,20,14,23,10,16,6,13,1,17},i,j,k,t,flag[27]={0};
char c='\n',ch[120];
scanf("%d", &t);



for(j=0;j<t;j++)
	{ 
	printf("Case #%d: ",j+1);	
	while(c=='\n' ||c=='\r')
		scanf("%c",&c);
		
	for(i=0;(c!='\n')&&(c!='\r');)
		{
		if(c!=' ')
			printf("%c",mapping[c-'a'+1]+'a'-1);
		else 	printf(" ");	
		scanf("%c",&c);	
		}	

	printf("\n");
	}

return 0;
}
