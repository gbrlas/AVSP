#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
bool isP(char c)
{
	return !(c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}
int main()
{
	FILE *fp,*op;
	int len,T,count=0,left_cur,left_next,left,sum,tp,tmp,n,right;
	char str[1000001];
	fp=fopen("in","r");
	op=fopen("output","w");
	//scanf("%d",&T);
	fscanf(fp,"%d",&T);
	while(count<T)
	{
	//scanf("%s%d",str,&n);
	fscanf(fp,"%s%d",str,&n);
	left_cur=0;
	sum=0;

	len=strlen(str);
	bool first=true;
	for(int i=0;i<len;i++)
	{
		if(isP(str[i]))
		{

			tp=0;
			tmp=i;
			int j=i;
			do{
				
				tp++;
				if(tp==n)
					break;
				j++;
			}while(j<len&&isP(str[j]));
			
			//printf("tp=%d\n",tp);
			if(tp==n)
			{
			left=tmp;
			//printf("%d\n",left);
			right=j;
			//printf("%d\n",right);
			if(first){
				sum+=((left-left_cur+1)*(len-right));
				first=false;
			}
			else
				sum+=((left-left_cur-1+1)*(len-right));
			left_cur=left;

			if(right==len-1)
				break;
			}
		}
	}
	printf("Case #%d: %d\n",count+1,sum);
	fprintf(op,"Case #%d: %d\n",count+1,sum);
	count++;
	}
	//getchar();
return 0;
}