#include<stdio.h>

int main()
{
int i,j,k,t,n,s,p,ans;

scanf("%d", &t);



for(j=0;j<t;j++)
	{ 
	scanf("%d",&n);
	scanf("%d",&s);
	scanf("%d",&p);

	ans=0;
	while(n--)
		{
		scanf("%d",&i);
		if(p==0) {ans++; continue;}		
		if(i>=(3*p-2)) {ans++; continue;}
		if(p==1) 
			{//printf("YESS\n");
			if((i>=1)&&(s)) {s--;ans++;} 
			continue; 
			}
		if((i>=(3*p-4))&&s) {s--;ans++;}
		}		
	printf("Case #%d: %d\n",j+1,ans);
	}

return 0;
}
