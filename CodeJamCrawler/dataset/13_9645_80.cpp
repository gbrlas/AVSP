#include<stdio.h>
bool is(int a)
{
	int str[1000];
	int i=0;
	while(a>0)
	{
		str[i]=a%10;
		a/=10;
		i++;
	}
	bool flag=true;
	for(int j=0;j<i/2;j++)
		if(str[j]!=str[i-j-1])
		{
			flag=false;
			break;
		}
	return flag;
}
int main()
{
	int t,a,b,i,j,k,result,count=0;
	FILE *fp,*op;
	fp=fopen("C-small-attempt0.in","r");
	op=fopen("output3","w");
	fscanf(fp,"%d",&t);
	int u=1;
//	if(is(u))
//		printf("aaa\n");
	while(count<t)
	{
		fscanf(fp,"%d%d",&a,&b);
		k=1;
		result=0;
		for(i=a;i<=b;i++)
		{
			for(j=k;j*j<=i;j++);
			j--;
			if(j*j==i)
			{
				k=j;
				if(is(i)&&is(j))
					result++;
			}
			
		}
		fprintf(op,"Case #%d: %d\n",count+1,result);
		count++;
	}

	return 0;
}