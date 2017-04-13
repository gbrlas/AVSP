#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    int p=t;
    while(t--)
    {
	int n,m,i,j,arr[100][100],count=0,k,flag1=0,flag2=0,flag=0;
	scanf("%d%d",&n,&m);
	for(i=0; i<n; i++)
	{
	    for(j=0; j<m; j++)
		scanf("%d",&arr[i][j]);
	}
	for(i=0; i<n; i++)
	{
	    for(j=0; j<m; j++)
	    {
		flag1=0,flag2=0;
		for(k=0; k<m; k++)
		{
		    if(arr[i][k]>arr[i][j])
		    {
			flag1=1;
			break;
		    }
		}
		if(flag1==1)
		{
		    for(k=0; k<n; k++)
		    {
			if(arr[k][j]>arr[i][j])
			{
			    flag2=1;
			    break;
			}
		    }
		}
		if(flag1==1 && flag2==1)
		{
		    flag=1;
		    break;
		}
	    }
	    if(flag==1)
		break;
	}
	if(flag==0)
	    printf("Case #%d: YES\n",p-t);
	else
	    printf("Case #%d: NO\n",p-t);
    }
    return 0;
}
