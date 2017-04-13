#include<stdio.h>
main()
{
	int j,a[4][4],b[4],k,p,c=0;
	long int i,t,r1,r2;
	
	FILE *fp,*fp1;
	fp=fopen("A-small-attempt0.in","r");
	
	fp1=fopen("magicout.txt","w");
	
	fscanf(fp,"%ld",&t);
	
	for(i=0;i<t;i++)
	{
		c=0;
		
		fscanf(fp,"%d",&r1);
		
		for(j=0;j<4;j++)
		for(k=0;k<4;k++)
		fscanf(fp,"%d",&a[j][k]);		
		
		
		for(j=0;j<4;j++)
		b[j]=a[r1-1][j];
		
	/*	printf("\n");
		
		for(j=0;j<4;j++)
		printf("%d ",b[j]);
	*/	
		
		fscanf(fp,"%d",&r2);
		
		
		for(j=0;j<4;j++)
		for(k=0;k<4;k++)
		fscanf(fp,"%d",&a[j][k]);
		
		
		for(j=0;j<4;j++)
		for(k=0;k<4;k++)
		{
			if(b[j]==a[r2-1][k])
			{
				p=k;
				c++;
				break;
			}
		}
		
		if(c==0)
		fprintf(fp1,"Case #%d: Volunteer cheated!\n",i+1);
		
		else if(c==1)
		fprintf(fp1,"Case #%d: %d\n",i+1,a[r2-1][p]);
		
		else if(c>1)
		fprintf(fp1,"Case #%d: Bad magician!\n",i+1);
		
		
		
	}
	
	
	fclose(fp1);
		system("magicout.txt");
	
}
