#include<iostream>
#include<fstream>
using namespace std;
double * sort(int N,double *array);
int deceitful(int N,double *array,double *array1);
float optimal(int N,double *array,double *array1);
main()
{
	fstream fin1,fin2;
	fin1.open("D-small-attempt1 (1).in",ios::in);
	fin2.open("out.txt",ios::out);
int testc;
int k,i,N;
double *ptr;
double *ptr1;
int pointd;
float pointo;
	fin1>>testc;
	for(k=1;k<=testc;k++)
	{
	fin1>>N;
	double array[N],array1[N];
		for(i=0;i<N;i++)
		fin1>>array[i];
		for(i=0;i<N;i++)
		fin1>>array1[i];
	ptr=sort(N,array);
	ptr1=sort(N,array1);
	pointd=deceitful(N,array,array1);
	pointo=optimal(N,array,array1);
	fin2<<"Case #"<<k<<": "<<pointd<<" "<<pointo<<"\n";
	}
	fin1.close();
	fin2.close();
return 0;
}

double * sort(int N,double *array)
{
int i,j;
double max;
max=array[0];
	for(j=1;j<=N;j++)
	{
		for(i=0;i<(N-1);i++)
		{
			if(array[i]>array[i+1])
			continue;
			else
			{
				max=array[i+1];
				array[i+1]=array[i];
				array[i]=max;
			}
		}
	}
	
return array;
}

int deceitful(int N,double *array,double *array1)
{
int pointk=0;
int pointn=0;
int i,c=0;
	for(i=0;i<N;i++)
	{
		if(array[N-i-1]<array1[N-i-1+c])
		{
			if(array[N-1-i]<array1[c])
			{
			c++;
			pointk++;
			}
		}
		else
		if(array[N-1-i]>array1[N-i-1+c])
		pointn++;
		
	}
return pointn;
}

float optimal(int N,double *array,double *array1)
{
int pointk=0;
int pointn=0;
int i,c=0;
		for(i=0;i<N;i++)
		{
			if(array[i]<array1[c])
			{
			pointk++;
			c++;
			}
			else
			if(array[i]>array1[N-1-i+c])
			pointn++;
			
		
		}
return pointn;
}
