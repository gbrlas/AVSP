#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
using namespace std;

int x=0;

int main()
{
	FILE *f;
	f=fopen("C:\\Users\\Simy\\Downloads\\A-small-attempt3.in","r");
	if(f==NULL)
	{
		cout << "hello" << endl;
	}
	ofstream out("a.out");


	int a[]={24,7,4,18,14,2,21,23,3,20,8,6,11,1,10,17,25,19,13,22,9,15,5,12,0,16};

	int T;
	fscanf(f,"%d",&T);
	for(;x<=T;x++)
	{
		char b[102]={};
		fgets(b,102,f);
		for(int i=0;i<strlen(b);i++)
		{
			if(b[i] == 10 || b[i] ==13)
				break;
			if(b[i]!=' ')
			{
				b[i]='a'+a[b[i]-'a'];
			}
		}
		if(x==0)
			;
		else
			out << "Case #" << x << ": "<< b;
	}

	return 0;
}