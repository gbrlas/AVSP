#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <stdio.h>
using namespace std;

ifstream in;    //input
FILE *out;         //output

char fs[]="A-small-practice.in";
char fl[]="A-large-practice.in";
int a[4];
int b[4];

int main()
{
	in.open("A-small-attempt0.in");
	if (!in)
		return 0;
	if(fopen_s(&out,"fout.in","w")!=0)
		return 0;

	int num;	
	in>>num;

	for (int i=0;i<num;++i)   //each case
	{
		int row=0,t;
		in>>row;
		for (int k=0;k<4;++k)
		{
			if (k==row-1)
			{
				in>>a[0]>>a[1]>>a[2]>>a[3];
			}
			else
				in>>t>>t>>t>>t;
		}
		
		in>>row;
		for (int k=0;k<4;++k)
		{
			if (k==row-1)
			{
				in>>b[0]>>b[1]>>b[2]>>b[3];
			}
			else
				in>>t>>t>>t>>t;
		}
		int count=0,the=0;
		int j;
		for (j=0; j<4; ++j)
			for (int k=0;k<4;++k)
			{
				if (a[j]==b[k])
				{
					the=j;
					count++;
				}
			}
		if (count==1)
		{
			fprintf_s(out,"Case #%d: %d\n", i+1,a[the]);	
		}
		else if (count>1)
		{
			fprintf_s(out,"Case #%d: ", i+1);	
			fprintf_s(out,"Bad magician!\n");	
		}
		else
		{
			fprintf_s(out,"Case #%d: ", i+1);	
			fprintf_s(out,"Volunteer cheated!\n");	
		}
		
	}
	in.close();
	fclose(out);

	return 0;
}