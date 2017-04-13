#include <stdio.h>

int main()
{
	int t,n,s,p,ti;
	int score1,score2,count;
	int i,j,k;
	FILE *fp1,*fp2;
	fp1= fopen("e:\\B-large.in","r+");
	fp2= fopen("e:\\B-large.out","w+");
	fscanf(fp1,"%d",&t);
	for (i = 1; i<=t; i++ )
	{
		count = 0;
		fscanf(fp1,"%d %d %d",&n,&s,&p);
		score1 = 3*p-4;
		score2 = 3*p-2;
		for (j=0;j<n;j++)
		{
			fscanf(fp1,"%d",&ti);
			if (p>1)
			{

			
				if (ti>=score2)
					count++;
				else if ( ti>=score1 && s>0)
				{
					count++;
					s--;
				}
			}
			else if (p ==1)
			{
				if (ti>=1) count++;
			}
			else if (p ==0)
			{
				count++;
			}
		}
		fprintf(fp2,"Case #%d: %d\n",i,count);
	}
	fclose(fp1);
	fclose(fp2);

}