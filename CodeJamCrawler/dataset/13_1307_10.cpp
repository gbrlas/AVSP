#include<stdio.h>
#include<string.h>

	int main()
	{
		int t,i,n=4;
		char a[5][5],c;
	
		scanf("%d",&t);
		for(int k=1;k<=t;k++)	
			{
			getchar();
			for(i=0;i<4;i++)
			scanf("%s",a[i]);
			int flag=0,count;
			for(i=0;i<4;i++)
			{			
			for(int j=0;j<4;j++)
			{
			c=a[i][j];
			if(c=='.')			
			flag=1;
			else
			if(c!='T')
			{
			count=0;
			int ii=i,jj=j;
			while(a[ii][jj]==c&&ii<4&&jj<4)
			{
			count++;
			ii++;
			jj++;
			}
			if(count==4||(count==3&&a[ii][jj]=='T'&&ii<4&&jj<4))
			{printf("Case #%d: %c won\n",k,c);goto hell;}
			
			ii=i;jj=j;count=0;
			while(a[ii][jj]==c&&jj<n)
			{
			count++;
			ii;
			jj++;
			}
			if(count==4||(count==3&&a[ii][jj]=='T'&&jj<n))
			{printf("Case #%d: %c won\n",k,c);goto hell;}
			count=0;
			ii=i;jj=j;count=0;
			while(a[ii][jj]==c&&ii<n)
			{
			count++;
			ii++;
			jj;
			}
			if(count==4||(count==3&&a[ii][jj]=='T'&&ii<n))
			{printf("Case #%d: %c won\n",k,c);goto hell;}
	
			count=0;

			 ii=i,jj=j;
			while(a[ii][jj]==c&&ii<n&&jj>=0)
			{
			count++;
			//printf("%c %d %d %d %d %d\n",c,count,i,j,ii,jj);
			ii++;
			jj--;
			}
			if(count==4||(count==3&&a[ii][jj]=='T'&&ii<n&&jj>=0))
			{printf("Case #%d: %c won\n",k,c);goto hell;}
			}
			}				
			}
			if(flag==1)
			printf("Case #%d: Game has not completed\n",k);
			else
			printf("Case #%d: Draw\n",k);

			hell:
				;
				}
				return 0;
				}












	
