#include <stdio.h>

void main()
{
	FILE *ip, *op;
	int t, a[4][4],i,j,k,x,b,check;
	char z;
	ip=fopen("A-small-attempt0.in","r");
	op=fopen("output.txt","w");
	fscanf(ip,"%d\n",&t);
	for (i=0;i<t;i++)
	{
		if (i!=0)
			fscanf(ip,"%c",&z);
		check=0;
		x=0;
		{
		for(j=0;j<4;j++)
			for(k=0;k<4;k++)
			{
				fscanf(ip,"%c",&z);
				if(z=='.')
					a[j][k]=0;
				else if (z=='X')
					a[j][k]=1;
				else if (z=='O')
					a[j][k]=5;
				else
					a[j][k]=21;
				if(k==3)
					fscanf(ip,"%c",&z);
			}
		}
		for(j=0;j<4;j++)
		{
			b=a[j][0]+a[j][1]+a[j][2]+a[j][3];
			if (b==4 || b==24)
			{
				fprintf(op,"Case #%d: X won\n",i+1);
				x=1;
				break;
			}
			if (b==20 || b==36)
			{
				fprintf(op,"Case #%d: O won\n",i+1);
				x=1;
				break;
			}
		}
		if (x==1)
			continue;
		for(j=0;j<4;j++)
		{
			b=a[0][j]+a[1][j]+a[2][j]+a[3][j];
			if (b==4 || b==24)
			{
				fprintf(op,"Case #%d: X won\n",i+1);
				x=1;
				break;
			}
			if (b==20 || b==36)
			{
				fprintf(op,"Case #%d: O won\n",i+1);
				x=1; 
				break;
			}
		}
		if (x==1)
			continue;
		b=a[0][0]+a[1][1]+a[2][2]+a[3][3];
		if (b==4 || b==24)
		{
			fprintf(op,"Case #%d: X won\n",i+1);
			x=1;
		}
		if (b==20 || b==36)
		{
			fprintf(op,"Case #%d: O won\n",i+1);
			x=1;
		}
		if (x==1)
			continue;
		b=a[0][3]+a[1][2]+a[2][1]+a[3][0];
		if (b==4 || b==24)
		{
			fprintf(op,"Case #%d: X won\n",i+1); 
			x=1;
		}
		if (b==20 || b==36)
		{
			fprintf(op,"Case #%d: O won\n",i+1);
			x=1;
		}
		if (x==1)
			continue;
		for (j=0;j<4;j++)
		{
			for (k=0;k<4;k++)
			{
				if (a[j][k]==0)
					check=1;
			}
		}
		if (check==0)
			fprintf(op,"Case #%d: Draw\n",i+1);
		else
			fprintf(op,"Case #%d: Game has not completed\n",i+1);
	}
	fclose(ip);
	fclose(op);
}