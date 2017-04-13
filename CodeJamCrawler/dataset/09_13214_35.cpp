/*
ID: tony22s1
TASK: B_2
LANG: C++
*/

#include <fstream>
#include <algorithm>
#include <string.h>
using namespace std;

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

FILE*fin =fopen("B_2.in","r");
ofstream fout ("B_2.out");
int numcases,numdigits;
char temp;
int array[21];
int use[21];
int permu[21];
int qsorts[21];

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}


int main()
{
	fscanf(fin,"%d",&numcases);
	fscanf(fin,"%c",&temp);
	for(int i=0;i<numcases;i++)
	{
		numdigits=0;
		do
		{
			fscanf(fin,"%c",&temp);
			if(temp!='\n')
			{
				array[numdigits]=temp-'0';
				numdigits++;
			}
		}while(temp!='\n');
		for(int j=0;j<numdigits;j++)
		{
			use[j]=array[j];
		}
		next_permutation(use,use+numdigits);
		for(int j=0;j<numdigits;j++)
		{
			permu[j]=use[j];
		}
		for(int j=0;j<numdigits;j++)
		{
			use[j]=array[j];
		}
		qsort(use,numdigits,sizeof(int),compare);
		for(int j=0;j<numdigits;j++)
		{
			qsorts[j]=use[j];
		}
		if(memcmp(permu,qsorts,numdigits*sizeof(int))==0)
		{
			bool firstDig=false;
			int numZero=0;
			for(int j=0;j<numdigits;j++)
			{
				if(qsorts[j]==0)
				{
					numZero++;
				}
			}
			for(int j=0;j<numdigits;j++)
			{
				if(permu[j]==0)
				{
				}
				else if(firstDig==false)
				{
					fout<<"Case #"<<i+1<<": "<<permu[j];
					for(int z=0;z<=numZero;z++)
					{
						fout<<'0';
					}
					firstDig=true;
				}
				else
				{
					fout<<permu[j];
				}
			}
			fout<<"\n";
		}
		else
		{
			fout<<"Case #"<<i+1<<": ";
			for(int j=0;j<numdigits;j++)
			{
				fout<<permu[j];
			}
			fout<<"\n";
		}
		for(int j=0;j<21;j++)
		{
			permu[j]=0;
			use[j]=0;
			array[j]=0;
			qsorts[j]=0;
		}
	}
}
