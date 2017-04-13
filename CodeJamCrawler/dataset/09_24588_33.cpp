#include <iostream>
#include <stdio.h>

int main (int argc, char * const argv[]) {
    // insert code here...
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N;
	char st[]="welcome to code jam";
	char in[502];
	scanf("%d",&N);
	int i,j;
	int **a;
	a=new int*[19];
	for(i=0;i<19;i++)
	{
		a[i]=new int[502];
	}
	char qq;
	scanf("%c",&qq);
	for(i=0;i<N;i++)
	{
		int k;
		for(k=0;k<19;k++)
		{
			for(j=0;j<502;j++)
			a[k][j]=0;
		}
		char tmp='a';
		for(j=0;j<502;j++)
			in[j]=0;
		j=0;
		
		while(tmp!='\n'&&scanf("%c",&tmp)!=EOF)
		{
			in[j]=tmp;
			j++;
			//printf("%c",tmp);
		}
		int M;
		M=j-1;
		int tint;
		for(k=0;k<19;k++)
			for(j=0;j<M;j++)
			{
				if(st[k]==in[j])
				{
					if(j==0) tint=0;
					else tint=a[k][j-1];
					if(k==0) tint++;
					if(k>0) tint+=a[k-1][j];
					a[k][j]=tint%10000;
				}
				else
				{
					if(j>0) a[k][j]=a[k][j-1]%10000;
				}
			}
		/*
		for(k=0;k<19;k++)
		{
			for(j=0;j<M;j++)
				printf("%2d",a[k][j]);
			printf("\n");
		}
		 */
			printf("Case #%d: ",i+1);
		
		printf("%d",a[18][M-1]%10000/1000);
		printf("%d",a[18][M-1]%1000/100);
		printf("%d",a[18][M-1]%100/10);
		printf("%d",a[18][M-1]%10);
		printf("\n");
	}
    return 0;
}
