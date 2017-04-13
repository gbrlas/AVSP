/*
ID: tony22s1
TASK: C_2
LANG: C++
*/

#include <fstream>
#include <math.h>
using namespace std;

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

int compare(const void* a, const void* b)
{
  return (*(int*)a-*(int*)b);
}

ifstream fin ("C_2.in");
FILE*fout=fopen("C_2.out","w");

int mxi,myi,mzi;
int mxv,myv,mzv;
int temp;
int numcase,numpoints;
double t,d;

int main()
{
	fin>>numcase;
	for(int i=0;i<numcase;i++)
	{
		mxi=0;
		myi=0;
		mzi=0;
		mxv=0;
		myv=0;
		mzv=0;
		fin>>numpoints;
		for(int j=0;j<numpoints;j++)
		{
			fin>>temp;
			mxi+=temp;
			fin>>temp;
			myi+=temp;
			fin>>temp;
			mzi+=temp;
			fin>>temp;
			mxv+=temp;
			fin>>temp;
			myv+=temp;
			fin>>temp;
			mzv+=temp;
		}
		double tmxv=mxv;
		double tmyv=myv;
		double tmzv=mzv;
		double tmxi=mxi;
		double tmyi=myi;
		double tmzi=mzi;
		if((mxv*mxv+myv*myv+mzv*mzv)==0)
		{
			t=0.0;
			d=sqrt((t*t*(tmxv*tmxv+tmyv*tmyv+tmzv*tmzv)+2*t*(tmxi*tmxv+tmyi*tmyv+tmzi*tmzv)+tmxi*tmxi+tmyi*tmyi+tmzi*tmzi)/(numpoints*numpoints));
		}
		else{
		t=-(tmxi*tmxv+tmyi*tmyv+tmzi*tmzv)/(tmxv*tmxv+tmyv*tmyv+tmzv*tmzv);
		if(t<=0.0)
		{
			t=0.0;
			d=sqrt((t*t*(tmxv*tmxv+tmyv*tmyv+tmzv*tmzv)+2*t*(tmxi*tmxv+tmyi*tmyv+tmzi*tmzv)+tmxi*tmxi+tmyi*tmyi+tmzi*tmzi)/(numpoints*numpoints));
		}
		else{
			double a=(t*t*(tmxv*tmxv+tmyv*tmyv+tmzv*tmzv)+2*t*(tmxi*tmxv+tmyi*tmyv+tmzi*tmzv)+tmxi*tmxi+tmyi*tmyi+tmzi*tmzi)/(numpoints*numpoints);
			if(a<0.0)
			{
				a=0.0;
			}
			d=sqrt(a);}
		}
		fprintf(fout,"Case #%d: %.8lf %.8lf\n",i+1,d,t);
	}
	return (0);
}
