#include<stdio.h>
int main()
{
	int t,jk,x1,y1,flag=1,i,j,k,l,x,y,a[300][300],max;
	char b[300][300],p='a';
freopen("a3.in","r",stdin);
	freopen("d.txt","w",stdout);
	scanf("%d",&t);
	for(jk=0;jk<t;jk++)
	{
	p='a';
	scanf("%d%d",&x,&y);
	for(i=1;i<=x;i++)
	  for(j=1;j<=y;j++)
	    scanf("%d",&a[i][j]);
	
	for(i=0;i<200;i++)
	 a[0][i]=a[i][0]=a[x+1][i]=a[i][y+1]=10000000;
	  
     for(i=0;i<200;i++)
       for(j=0;j<200;j++)
         b[i][j]='0';
	
	for(k=1;k<=x;k++)
	  for(l=1;l<=y;l++)
	  {
	    if(b[k][l]=='0')
		{
		 i=k; j=l; flag=1;
		 while(flag==1)
		 {
		  max=a[i][j];
		 if(max>a[i-1][j]) {  x1=i-1; y1=j; max=a[i-1][j]; }
		if(max>a[i][j-1])  { x1=i; y1=j-1; max=a[i][j-1];}
 		if(max>a[i][j+1])  {  x1=i; y1=j+1; max=a[i][j+1];}
        if(max>a[i+1][j])  { x1=i+1; y1=j; max=a[i+1][j];}	
		 //if(k==4 && l==4) printf("%d %d\n",i,j);
		 if(max!=a[i][j]) {  i=x1; j=y1;} 
		 else {flag=0; if(b[i][j]=='0') {  b[i][j]=p; p++;} }  	
		 }
		 b[k][l]=b[i][j]; //printf("%d %d %c\n",i,j,b[i][j]);
		}
	  }
	  printf("Case #%d:\n",jk+1);
	  for(i=1;i<=x;i++)
        {
		for(j=1;j<=y;j++)
        {
        if(j!=1) printf(" %c",b[i][j]);
        else  printf("%c",b[i][j]);
		}
        printf("\n");
       }
	}
}
