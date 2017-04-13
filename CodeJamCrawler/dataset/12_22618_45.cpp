#include <stdio.h>
int CalLen(int num)
{
	int l = 1;
	num = num / 10;
	while( num > 0)
	{
		num = num / 10;
		l++;
	}
	return l;
}
int main()
{
	int t,a,b;
	int src,dst,tmp;
	int i,j,i1,j1;
	int length,tenth;
	int count;
	int len[10];
	bool con;
	FILE *fp1,*fp2;
	fp1 =fopen("e:\\C-small-attempt0.in","r+");
	fp2 =fopen("e:\\C-small-attempt0.out","w+");
	fscanf(fp1,"%d",&t);
	for ( i = 1;i <=t; i ++)
	{
		fscanf(fp1,"%d %d",&a,&b);
		count =0;
		length = CalLen(a);
		tenth =1;
		for (j =1; j<length; j++)
		{
			tenth *= 10;
		}
		for (src = a; src<=b; src++ )
		{
			i1=0;
			tmp =src;
			con = false;
			for(j=1;j<length;j++)
			{
				tmp = (tmp%10)*tenth +tmp/10;
				if ( tmp> src && tmp<=b)
				{	
					for(j1=0;j1<i1&&!con;j1++)
						if(tmp == len[i1]) con=true; 
					if (!con)
					{
						count++;
						len[++i1]=tmp;
					}
					con =false; 
					//printf("%d %d %d\n",count,src,tmp);

					
				}
			}
		}
		fprintf(fp2,"Case #%d: %d\n",i,count);
	}
	fclose(fp1);
	fclose(fp2);
}