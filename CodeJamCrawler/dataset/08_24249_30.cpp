#include<iostream.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>

FILE *read_file=fopen("B-small-attempt2.in","r");
FILE *out=fopen("output.doc","w");
int main()
{
	int stA[200][2],stB[200][2],nA,nB,c=0,ntA=0,ntB=0,store,min,dif;
	int inSize,tTime=0,block[100];
	char st[100];
	fscanf(read_file,"%d",&inSize);
	//printf("%d\n",inSize);
	fgets(st,100,read_file);
	for(int i=0;i<inSize;i++)
	{
		for(int j=0;j<100;j++)block[j]=0;
		fscanf(read_file,"%d",&tTime);fgets(st,100,read_file);
		fscanf(read_file,"%d",&nA);
		fscanf(read_file,"%d",&nB);fgets(st,100,read_file);
		c=0;ntA=0;ntB=0;store=0;min=1440;dif=0;
		while(c<nA+nB)
		{
			if(c<nA)
			{
			fscanf(read_file,"%d:%d",&stA[c][0],&stA[c][1]);
			fscanf(read_file,"%d:%d",&stB[c][0],&stB[c][1]);
			fgets(st,100,read_file);
			}
			if(c>=nA)
			{
			fscanf(read_file,"%d:%d",&stB[c][0],&stB[c][1]);
			fscanf(read_file,"%d:%d",&stA[c][0],&stA[c][1]);
			fgets(st,100,read_file);
			}
			c++;
		}
		for(int j=nA;j<nA+nB;j++)
		{
			stA[j][1]+=tTime;
			while(stA[j][1]>59){stA[j][1]-=60;stA[j][0]+=1;}
		}
		for(int j=0;j<nA;j++)
		{
			stB[j][1]+=tTime;
			while(stB[j][1]>59){stB[j][1]-=60;stB[j][0]+=1;}
		}
		for(int j=nA;j<nA+nB;j++)
		{
			min=1440;
			for(int k=0;k<nA;k++)
			{
				dif=( (60*stA[k][0])+stA[k][1] )-( (60*stA[j][0])+stA[j][1] );
				if(dif>=0 && block[k]!=1 && dif<min){store=k;min=dif;}
			}
			if(min!=1440)
			{
				ntA++;
				block[store]=1;
			}
		}
		ntA=nA-ntA;
		for(int j=0;j<100;j++)block[j]=0;
		for(int j=0;j<nA;j++)
		{
			min=1440;
			for(int k=nA;k<nB+nA;k++)
			{
				dif=( (60*stB[k][0])+stB[k][1] )-( (60*stB[j][0])+stB[j][1] );
				if(dif>=0 && block[k]!=1 && dif<min){store=k;min=dif;}
			}
			if(min!=1440)
			{
				ntB++;
				block[store]=1;
			}
		}
		ntB=nB-ntB;
		fprintf(out,"Case #%d: %d %d\n",i+1,ntA,ntB);
	}
	return 0;
}