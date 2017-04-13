#include<stdio.h>
int main()
{
    int i,j,k,test,a[5000],b[5000],n,x;
	freopen("a.in","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&test);
	for(k=0;k<test;k++)
	{
		x=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d%d",&a[i],&b[i]);
	
	for(i=0;i<n;i++)
	  for(j=i+1;j<n;j++)
	  {
	  	if((a[i]<a[j]&& b[i]>b[j] )|| (a[i]>a[j] && b[i] < b[j])) x++;
	  }
	  printf("Case #%d: %d\n",k+1,x);
	}
}
