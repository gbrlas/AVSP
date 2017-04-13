#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	FILE *op;
	fp=fopen("B-small-attempt0.in","r");
	op=fopen("out.txt","w");
	int i,j,k,count=0;
	int a[100][100],m,n,f_num=0,t,result;
	bool flag[5];
	fscanf(fp,"%d",&t);
	while(count<t)
	{
	
		fscanf(fp,"%d%d",&n,&m);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				fscanf(fp,"%d",&a[i][j]);					
			}

		result=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{

				for(k=1;k<5;k++)
					flag[k]=false;
				for(k=0;k<j;k++)
				{
					if(a[i][k]>a[i][j])
					{	
						flag[1]=true;
						break;
					}
				}
	
	
				for(k=j+1;k<m;k++)
				{
					if(a[i][k]>a[i][j])
					{	
						flag[2]=true;
						break;
					}
				}

		
				for(k=0;k<i;k++)
				{
					if(a[k][j]>a[i][j])
					{
						flag[3]=true;
						break;
					}
				}
				for(k=i+1;k<n;k++)
				{
					if(a[k][j]>a[i][j])
					{
						flag[4]=true;
						break;
					}
				}
			f_num=0;
			for(k=1;k<=4;k++){
				if(flag[k]==true)
					f_num++;
			}
		//		printf("%d\n",f_num);
			if(f_num<=1||(f_num==2&&flag[1]==true&&flag[2]==true)||(f_num==2&&flag[3]==true&&flag[4]==true))
			{	
				continue;
			}else
			{
				result=1;
				break;
			}

			}
			if(result==1)
				break;
		}
		//printf("%d\n",f_num);
		if(result==0)
			fprintf(op,"Case #%d: YES\n",count+1);
		else
			fprintf(op,"Case #%d: NO\n",count+1);


		count++;
	}
	fclose(fp);
	fclose(op);
}