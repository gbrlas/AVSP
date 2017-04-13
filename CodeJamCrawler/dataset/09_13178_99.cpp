#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>s

char a,b;
int L,D,N,x,y,z,s,t;
bool temp;
char dict[5000][15];
bool test[500][26];
int queries[500];
FILE*fin=fopen("codejam.in","r");
FILE*fout=fopen("codejam.out","w");

int main()
{
	fscanf(fin,"%d %d %d",&L,&D,&N);
	for(x=0;x<D;x++)
	{
		fscanf(fin,"%s",&dict[x]);
	}
	fscanf(fin,"%c",&a);
	for(x=0;x<N;x++)
	{
		for(y=0;y<=L;y++)
		{
			fscanf(fin,"%c",&a);
			if(a=='\n')
			{
				for(s=0;s<D;s++)
				{
					temp=true;
					for(t=0;t<L;t++)
					{
						if(test[t][dict[s][t]-'a']==false)
						{
							temp=false;
							break;
						}
					}
					if(temp==true)
					{
						queries[x]++;
					}
				}
				for(s=0;s<500;s++)
				{
					for(t=0;t<26;t++)
					{
						test[s][t]=false;
					}
				}
			}
			else if(a=='(')
			{
				do{
					fscanf(fin,"%c",&b);
					if(b!=')')
					{
						test[y][b-'a']=true;
					}
				}while(b!=')');
			}
			else
			{
				test[y][a-'a']=true;
			}
		}
	}
	for(x=0;x<N;x++)
	{
		fprintf(fout,"Case #%d: %d\n",x+1,queries[x]);
	}
	return (0);
}
