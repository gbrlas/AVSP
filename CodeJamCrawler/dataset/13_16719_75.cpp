#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
	int t,ctr;
		char junk;
	ctr=1;
	scanf("%d%c",&t,&junk);
	while(t--)
	{
		int rowx[5]={0},rowy[5]={0},colx[5]={0},coly[5]={0};
		int c1,c2,c3,cum,i,ocx,ocy,towx,towy,flag,j;
		char c,a[5][5]={0};
		towx=-1;
		towy=-2;
		for(i=1;i<=4;i++)
		{
			for(j=1;j<=4;j++)
			{
				if(j!=4)
					scanf("%c",&a[i][j]);
				else
				{
					scanf("%c%c",&a[i][j],&junk);
				}

				c=a[i][j];
				if(c=='X')
				{
					rowx[i]++;
					colx[j]++;
				}
				if(c=='O')
				{
					rowy[i]++;
					coly[j]++;
				}
				if(c=='T')
				{
					rowx[i]++;
					rowy[i]++;
					colx[j]++;
					coly[j]++;
					towx=i;
					towy=j;
				}
			}
		}
		c1=0;
		c2=0;
		c3=0;
		flag=0;
		for(i=1;i<=4;i++)
		{
			if(rowx[i]==4)
			{
				flag=1;
				break;
			}
			else if(rowy[i]==4)
			{	flag=2;
				break;
			}
			else if((rowx[i]+rowy[i]==4 && towx!=i)||(rowx[i]+rowy[i]==5 && towx==i))
			{
				c1++;
			}
		}
		if(flag==1)
		{
			printf("Case #%d: X won\n",ctr++);
			scanf("%c",&junk);
			continue;
		}
		else if(flag==2)
		{
			printf("Case #%d: O won\n",ctr++);
			scanf("%c",&junk);
			continue;
		}
		for(i=1;i<=4;i++)
		{
			if(colx[i]==4)
			{
				flag=1;
				break;
			}
			else if(coly[i]==4)
			{	flag=2;
				break;
			}
			else if((colx[i]+coly[i]==4 && towy!=i)||(colx[i]+coly[i]==5 && towy==i))
				c2++;
		}
		if(flag==1)
		{
			printf("Case #%d: X won\n",ctr++);
			scanf("%c",&junk);
			continue;
		}
		else if(flag==2)
		{
			printf("Case #%d: O won\n",ctr++);
			scanf("%c",&junk);
			continue;
		}
		ocx=0;
		ocy=0;

		for(i=1;i<=4;i++)
		{
			if(a[i][i]=='X' || a[i][i]=='T')
				ocx++;
			if(a[i][i]=='O' || a[i][i]=='T')
				ocy++;
		}
		if(ocx==4)
		{
			printf("Case #%d: X won\n",ctr++);
			scanf("%c",&junk);
			continue;
		}
		else if(ocy==4){
			printf("Case #%d: O won\n",ctr++);
			scanf("%c",&junk);
			continue;
		}
		else if((towx==towy&&ocx+ocy==5)||(towx!=towy && ocx+ocy==4))
			c3++;
		ocx=0;
		ocy=0;
		for(i=1;i<=4;i++)
		{
			if(a[i][5-i]=='X' || a[i][5-i]=='T')
				ocx++;
			if(a[i][5-i]=='O' || a[i][5-i]=='T')
				ocy++;
		}
		if(ocx==4){
			printf("Case #%d: X won\n",ctr++);
			scanf("%c",&junk);
			continue;
		}
		else if(ocy==4){
			printf("Case #%d: O won\n",ctr++);
			scanf("%c",&junk);
			continue;
		}
		else if((towx+towy==5&&ocx+ocy==5)||(towx+towy!=5 && ocx+ocy==4))
			c3++;
		cum=c1+c2+c3;
		if(cum==10)
		{
			printf("Case #%d: Draw\n",ctr++);
		}
		else
		{
			printf("Case #%d: Game has not completed\n",ctr++);
		}

		scanf("%c",&junk);
	}
	return 0;
}
