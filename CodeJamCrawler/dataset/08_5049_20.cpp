#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp ( const void *a , const void *b ) 
{ 
        return *(int *)a - *(int *)b; 
} 
int main()
{
	char ch[5000];
	int i,j,k,cas,CASNO,n,a[1000],b[1000],ans;

	freopen("A-small-attempt1.in","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&CASNO);

	for (cas=1;cas<=CASNO;cas++)
	{
		scanf("%d",&n);

		for (i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for (i=0;i<n;i++)
		{
			scanf("%d",&b[i]);
		}
		qsort(b,n,sizeof(b[0]),cmp);
		qsort(a,n,sizeof(a[0]),cmp);
		ans=0;

		for (i=0;i<n;i++)
		{
			ans+= a[i]*b[n-i-1];
		}


		printf("Case #%d: %d\n",cas,ans);
	}
	return 1;
}
	