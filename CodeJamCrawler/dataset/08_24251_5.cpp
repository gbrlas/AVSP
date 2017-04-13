#include<iostream.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>

FILE *read_file=fopen("A-small-attempt0(2).in","r");
FILE *out=fopen("output.doc","w");

int inSize;
int A[1000][2],ind,K,L,P,press,count;
unsigned long int sum;
int max()
{
	int in,m=-1;
	for(int i=0;i<L;i++)
	if(A[i][1]==0 && m<=A[i][0]){m=A[i][0];in=i;}
	
	return in;
}
int main()
{

	fscanf(read_file,"%d",&inSize);	
	
	for(int k=0;k<inSize;k++)
	{
		fscanf(read_file,"%d",&P);	
		fscanf(read_file,"%d",&K);	
		fscanf(read_file,"%d",&L);
		for(int i=0;i<1000;i++)
		A[i][1]=0;
		for(int j=0;j<L;j++)
		fscanf(read_file,"%d",&A[j][0]);
		press=1;count=0;
		for(int i=0;i<L;i++)		
		{
			ind=max();
			A[ind][1]=press;
			count++;
			if(count==K){press++;count=0;}
		}
		sum=0;
		for(int i=0;i<L;i++)
		{
			sum+=A[i][0]*A[i][1];
	   }	
		fprintf(out,"Case #%d: %d\n",k+1,sum);
		
	}
	return 1;	
}