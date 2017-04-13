#include<stdio.h>

int main()
{
	int arr[26]={24,7,4,18,14,2,21,23,3,20,8,6,11,1,10,17,25,19,13,22,9,15,5,12,0,16};
	char str[27]="abcdefghijklmnopqrstuvwxyz";
	int t,i,temp;
	char ch,c[101];
	int count=1;
	scanf("%d\n",&t);
	while(t--)
	{
		i=0;
		
		while(1)
		{	
		ch=getchar();
		if(ch=='\n')
		{	
			c[i]=0;
			break;
		}
		else 
		{
			if(ch!=' ')	
			{
			temp=arr[(int)ch-97];
			c[i]=str[temp];
			}
			else c[i]=' ';
			i++;
		}
		}
		i=0;
		
		/*while(c[i]!='0')
		{
			printf("%c",c[i]);
			i++;
		}*/
		printf("Case #%d: %s\n",count,c);
		count++;
	}
	return 0;
}
