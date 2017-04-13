#include<iostream.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>

FILE *read_file=fopen("A-large(2).in","r");
FILE *out=fopen("output.doc","w");

char strings[1200][100];
int inSize=0,tap1=0,tap2=0,counter=0;

int abc(int p)
{
	int max=p,j;
	
	for(int i=0;i<tap1;i++)
	{
		j=p;
		while(strcmp(strings[i],strings[j])!=0)
		{
			j++;
			if(j==tap2+tap1)return 0;
		}		
				
		if(max<j)max=j;
	}
	if(max==tap1+tap2-1)
	return 1;
	while(strcmp(strings[max],strings[max+1])==0)
	{
		max++;
		if(max==tap1+tap2-1)return 1;
	}
	
	return 1+abc(max);	
}

int main()
{
	fscanf(read_file,"%d",&inSize);	
	
	for(int j=0;j<inSize;j++)
	{		
	counter=0;
	fscanf(read_file,"%d",&tap1);
	fgets(strings[counter],100,read_file);
	
	while(counter<tap1)
	{
	fgets(strings[counter++],100,read_file);
	}
	
	fscanf(read_file,"%d",&tap2);	
	fgets(strings[counter],100,read_file);
	
	while(counter<tap1+tap2)
	{	
	fgets(strings[counter++],100,read_file);	
	}

	if(tap2!=0)
	fprintf(out,"Case #%d: %d\n",j+1,abc(tap1));
	else fprintf(out,"Case #%d: 0\n",j+1);	
	}
	return 1;	
}