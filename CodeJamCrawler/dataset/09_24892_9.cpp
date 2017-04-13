#include<stdio.h>
#include<math.h>
#include<string.h>
//#include<conio.h>

FILE *fp,*fo;


long long solve(long long n)
{
                         
int 	count=0;
int i,j,k,l,maxi;
int dig[21],dig2[21];

for(i=0;i<21;i++){dig[i]=0;dig2[i]=0;}


long long temp1=n;
while(temp1)
{
	dig[count++]=(int)temp1%10;
	dig2[count-1]=dig[count-1];
	temp1=(int)temp1/10;
}

//printf("c=%d ",count);

//for(i=0;i<21;i++)
//printf("%d ",dig[i]);


for(j=1;j<count;j++)
{
	for(i=0;i<j;i++)
	{
		if(dig[i]>dig[j])
		{
			
			dig2[i]=dig[j];
			dig2[j]=dig[i];
			
			dig[i]=dig2[i];
			dig[j]=dig2[j];
			//printf("%d", j);

			
			for(k=0;k<j;k++)
			{
				maxi=0;
				for(l=0;l<j;l++)
				{
					if(dig[l]!=-1)if(dig[maxi]<dig[l])maxi=l;
				}
				dig2[k]=dig[maxi];
				dig[maxi]=-1;
			//	printf("%d ",dig2[k]);
			}
			temp1=0;
			for(k=count-1;k>=0;k--)
			temp1=(temp1*10)+dig2[k];
			
			
			return temp1;	
		}
	}
}
int flag,temp2=count-1;
	for(k=0;k<count;k++)
			{
				maxi=0;flag=0;
				for(l=0;l<count;l++)
				{
					if(dig[l]!=-1)if(dig[maxi]<dig[l])
					{
						if(!(l==temp2 && dig[maxi]==0))
						maxi=l;
						if(l==temp2 && dig[maxi]==0)flag=1;
					}
				}
				dig2[k]=dig[maxi];
				dig[maxi]=-1;
				if(maxi==temp2)
				{
					for(i=count-1;i>=0;i--)if(dig[i]!=-1){temp2=i;break;}
				}
			
			//	printf("%d ",dig2[k]);
			}
			dig2[count]=dig2[count-1];
			dig2[count-1]=0;

	temp1=0;
			for(k=count;k>=0;k--)
			temp1=(temp1*10)+dig2[k];
			
			
			return temp1;	
            return temp1;	
}



int main()
{
	int i,T;

	long long num, ans;
	//char temp;
	

	fp=fopen("B-small-attempt4.in","r");
	fo=fopen("out.txt","w");	

	fscanf(fp,"%d",&T);
	for(i=0;i<T;i++)
	{
		
		
		fscanf(fp,"%lld",&num);	
		
		
		
		ans=solve(num);	
		fprintf(fo,"Case #%d: %lld\n",i+1,ans);
		printf("Case #%d: %lld\n",i+1,ans);
	}//T
	
	fclose(fp);
	fclose(fo);
	printf("over");
	return 0;
}