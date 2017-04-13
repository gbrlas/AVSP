#include<stdio.h>
int main()
{
	int i,j,t,l,test,n,k,deno,len;
	char s[200][200];
	double wp[200],op[200],owp[200],sum,x;
	freopen("a.in","r",stdin);
	freopen("output.txt","w",stdout);
scanf("%d",&test);
for(t=1;t<=test;t++)
{	scanf("%d",&n);
	for(i=0;i<n;i++)
	 scanf("%s",s[i]);
	 
	for(i=0;i<n;i++)
	  {
	  wp[i]=0.0;
	  deno=0;
	  for(j=0;j<n;j++)
	    {
	    	if(s[i][j]!='.')
		  { wp[i]+=s[i][j]-'0'; deno++;}
					    
		}
		wp[i]/=deno;
	  }
	  
	  for(i=0;i<n;i++)
	  {
		op[i]=0.0;
	len=0;  	 sum=0.0;
		  for(j=0;j<n;j++)
	  	  {
	  	  	x=0.0,deno=0;
	  	  	for(k=0;k<n;k++)
	  	  	{
	  	  			if(s[j][k]!='.' && j!=i && k!=i)
		  			{ x+=s[j][k]-'0'; deno++;}
					    
			}
			if(j!=i && s[i][j]!='.') { len++; sum=sum+x/deno;}
	  	  }
	  	  
	  	op[i]=sum/len; 
		 // printf("%lf\n",sum); 
	  }
	  
	  for(i=0;i<n;i++)
	    {
		owp[i]=0.0; len=0;
		for(j=0;j<n;j++)
            if(s[i][j]!='.') { len++; owp[i]+=op[j];}
        owp[i]/=len;
	    }
	    printf("Case #%d:\n",t);
	    for(i=0;i<n;i++)
	    printf("%0.8lf\n",0.25 * wp[i] + 0.50 * op[i] + 0.25 * owp[i]);
}
return 0;
}

