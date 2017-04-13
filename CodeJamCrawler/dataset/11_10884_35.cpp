#include<stdio.h>
#include<string.h>
void stringappend(char * str,char c)
{
	int l=strlen(str);
	str[l]=c;
	str[l+1]='\0';
}
int main()
{

	FILE* inp;
	FILE* out;
	inp = fopen("inp.txt","r");
	out = fopen("out.txt","w");
	int T,C,D,N,r,i,j,flag,flag2,n;
	char C1,C2,CR,w,D1,D2;
	char combi[2],opp[2];
	char str[10],res[11];
	fscanf(inp,"%d",&T);
	r=T;
	while(T)
	{
		fscanf(inp,"%d",&C);
		if(C==1)
		{
			fscanf(inp,"%c",&w);
			fscanf(inp,"%c",&C1);
			fscanf(inp,"%c",&C2);
			fscanf(inp,"%c",&CR);
		}
	
		fscanf(inp,"%d",&D);
		
		if(D==1)
		{
			fscanf(inp,"%c",&w);
			fscanf(inp,"%c",&D1);
			fscanf(inp,"%c",&D2);
			
		}
		fscanf(inp,"%d",&N);
		fscanf(inp,"%c",&w);
		res[0]='\0';
		for(i=0;i<N;i++)
		{
			flag2=0;
			flag=0;
			fscanf(inp,"%c",&w);
	
			if((w==C1)||(w==C2))
				{
					n=strlen(res);
					if((w==C1&&res[n-1]==C2)||(w==C2&&res[n-1]==C1))
						{
							res[n-1]=CR;
							flag2=1;
							
						}
				
			
				}
			if(((w==D1)||(w==D2))&&(!flag2))
				{
					n=strlen(res);
					for(j=n;j>=0;j--)
					{
						if((w==D1&&res[j]==D2)||(w==D2&&res[j]==D1))
							{
								res[0]='\0';
								flag=1;
							}
					}
					
				}
			if((!flag)&&(!flag2))
			{
				stringappend(res,w);
			}
		}
	        fprintf(out,"Case #");
		fprintf(out,"%Ld",r-T+1);
		fprintf(out,": [");
		n=strlen(res);
		i=0;
		while(i<n)
		{
			fprintf(out,"%c",res[i]);
			if(i<n-1)
			fprintf(out,", ");
			i++;
		}		
		fprintf(out,"]\n");
	
	T--;
	}
}
