#include <fstream>
#include <stdlib.h>
//#include <iostream>
//#include <conio.h>

using namespace std;

class vale
{
public:
	int val;
};

vale vec1[801],vec2[801];
int n;

int comp(const void* a,const void* b)
{
	if(((vale*)a)->val>=((vale*)b)->val)
	{
		return 1;
	} else {
		return -1;
	}
}

int comp2(const void* a,const void* b)
{
	if(((vale*)a)->val>=((vale*)b)->val)
	{
		return -1;
	} else {
		return 1;
	}
}

int calculate()
{
	int rez=0;
	for(int i=0;i<n;i++)
	{
		rez+=vec1[i].val*vec2[i].val;
	}
	return rez;
}

int main()
{
	ifstream f("input.in");
	ofstream f2("output.out");


	int T;
	f>>T;

	for(int X=0;X<T;X++)
	{

		f>>n;
		for(int i=0;i<n;i++)
		{
			f>>vec1[i].val;
		}
		for(int i=0;i<n;i++)
		{
			f>>vec2[i].val;
		}

		qsort(vec1,n,sizeof(int),comp2);
		qsort(vec2,n,sizeof(int),comp);

		/*for(int i=0;i<n;i++)
		{
			cout<<vec1[i].val<<" ";
		}
		cout<<endl; */

		f2<<"Case #"<<X+1<<": "<<calculate()<<endl;

	}

	f.close();
	f2.close();
	//getch();
	return 0;
}