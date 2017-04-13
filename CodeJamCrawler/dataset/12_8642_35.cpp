#include<stdio.h>
int main()
{ int t,n,i,j,k,s,p,c,l,r;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{		c=0;
			scanf("%d",&n);
			scanf("%d",&s);
			scanf("%d",&p);
			for(j=0;j<n;j++)
				{
					scanf("%d",&r);
					l=r%3;
					if(l==1&&r/3+1>=p)
						c++;
					else if(l==2)
						{if(r/3+1>=p)
							c++;
						  else if(r/3+2>=p&&s>0)
							{ c++;
								s--;
							}	
						}
					else 
					{
					 if(r/3>=p)
						c++;
					else if(r/3+1>=p&&s>0&&r/3-1>=0)
						{c++;
						
						s--;
						}
					}				
				}
		printf("Case #%d: %d\n",i+1,c);			
	}
	return 0;
}	
				
