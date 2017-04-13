#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <stdio.h>
using namespace std;

ifstream in;    //input
FILE *out;         //output

#define ZERO 1e-7

char fs[]="A-small-practice.in";
char fl[]="B-small-attempt0.in";

int main()
{
	in.open(fl);
	if (!in)
		return 0;
	if(fopen_s(&out,"fout.in","w")!=0)
		return 0;

	int num;	
	in>>num;

	for (int i=0;i<num;++i)   //each case
	{
		double C,F,X;
		in>>C>>F>>X;
		double timemax=1e10,last=0.0,now=0.0;
		last=now=X/2.0;
		double t1=0.0,t2=0.0;
		int n=1;
		while(true)
		{
			
			double v=2.0;
			
			t1+=C/(2.0+(double)(n-1)*F);
			
			t2=X/(2.0+n*F);
			now=t1+t2;
			if (now-last<ZERO)
			{
				n++;
				last=now;
			}
 			else
			{
				fprintf_s(out,"Case #%d: %f\n", i+1,last);	
				break;
			}			
		}
	}
	in.close();
	fclose(out);

	return 0;
}