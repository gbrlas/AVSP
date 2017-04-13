#include<stdio.h>
int main()
{
int t,f,count,s,a[5][5],b[5][5],i,j,k,c[5];
scanf("%d",&t);
for(i=1;i<=t;i++)
{
count=0;
scanf("%d",&f);
for(j=1;j<=4;j++)
{	
for(k=1;k<=4;k++)
scanf("%d",&a[j][k]);
}
scanf("%d",&s);
for(j=1;j<=4;j++)
{
for(k=1;k<=4;k++)
scanf("%d",&b[j][k]);
}
for(j=1;j<=4;j++)
{
	for(k=1;k<=4;k++)
	{
		if(a[f][j]==b[s][k])
		{
		count=count+1;
		c[count]=a[f][j];	
		}
	}
}
switch(count)
{

case 0:printf("Case #%d: Volunteer cheated!\n",i);
	break;
case 1:printf("Case #%d: %d\n",i,c[1]);
	break;
default:printf("Case #%d: Bad magician!\n",i);
	break;
}
}
return 0;
}
