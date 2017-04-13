#include<stdio.h>
#include<string.h>

void func(int,int,int);

int ans=0,qw[27][501];
char key[]="welcome to code jam";

int main()
{
		int dataset,i,length,j,k,temp,tt,t;
		scanf("%d",&dataset);
		char alok[2],input[500];
		for(i=0;i<27;i++)
					qw[i][0]=0;
		gets(alok);
		for(i=0;i<dataset;i++)
		{
				gets(input);
				ans=0;
				tt=0;
				length=strlen(input);
				for(j=0;j<length;j++)
				{
						if(input[j]!=' ')
 							k=(int)input[j]-97;
 						else
 							k=26;
 						t=++qw[k][0];
 						qw[k][t]=j;
 						
				}
				for(k=1;k<=qw[22][0];k++)
				{
						func(1,qw[22][k]+1,length);
				}
				temp=ans;
				while(temp!=0)
				{
					tt++;
					temp=temp/10;
				}
				printf("Case #%d: ",i+1);
				for(k=0;(k<4-tt)&&k<3;k++)
				printf("0");
				printf("%d\n",ans);
				for(k=0;k<27;k++)
				qw[k][0]=0;
		}
}



void func(int cha,int from,int length)
{
		int i,k,t;
		if(key[cha]==' ')
						k=26;
		else
						k=(int)key[cha]-97;
		t=qw[k][0];
		for(i=1;i<=t;i++)
		{
				if(qw[k][i]>=from)
				{
					if(cha!=18)
						func(cha+1,qw[k][i]+1,length);
					else
						{
								ans++;
								ans=ans%10000;
						}
				}
		}
}
