#include<stdio.h>
#include<math.h>
int main()
{
	int T,count,a,b,i,rem,revn,revr,j,root,k,counter=1;
	FILE *ip,*op;
	ip=fopen("C-small-attempt0.in","r");
	op=fopen("Output.out","w");
	fscanf(ip,"%d",&T);
	do
	{
		count=0;
		fscanf(ip,"%d",&a);
		fscanf(ip,"%d",&b);
		for(i=a;i<=b;i++){
			j=i;revn=0;
			while(j>0)
			{
				rem=j%10;
				revn=revn*10+rem;
				j/=10;
			}
			if(revn==i)
			{
				float temp=sqrt(i);
				if(ceil(temp)==floor(temp))	
				{
					root=temp;k=root;
					revr=0;
					while(k>0)
					{
						rem=k%10;
						revr=revr*10+rem;
						k/=10;
					}
					if(revr==root) count++;
				}
			}
		}
		fprintf(op,"Case #%d: %d\n",counter++,count);
	}while(--T);
	return 0;
}
