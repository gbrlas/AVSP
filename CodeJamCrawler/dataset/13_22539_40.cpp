#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int pallin(unsigned long long a)
{
	int arr[15],i=0,j;
	while(a>0)
	{
		arr[i++]=a%10;
		a=a/10;
	}
	for(j=0;j<(i/2);j++)
	if(arr[j]!=arr[i-j-1])
		return 0;
        return 1;
}

int main()
{
    FILE * fp1,* fp2;
    unsigned long long t,k=1;
    fp1=fopen("Input.txt","r");
    fp2=fopen("Output.txt","w");
    fscanf(fp1,"%llu",&t);
    unsigned long long a,b;
    while(k<=t)
    {
	unsigned long long count=0,p=0,i,y;
	fscanf(fp1,"%llu %llu",&a,&b);
	while(p*p<a)
	p++;
        for(i=p;(y=i*i)<=b;i++)
        {
            if(pallin(i))
            {
                if(pallin(y))
                    count++;
            }
        }
        fprintf(fp2,"Case #%llu: %llu\n",k,count);
	k++;
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
