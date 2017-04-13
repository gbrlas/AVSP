#ifdef WIN32
#pragma warning (disable: 4514 4786)
#endif
#include <iostream>
#include <fstream>
using namespace std;
int caseN;
int len;
int ret;
char line[510];
char total[5];
string strline;
const string str="welcome to code jam";
void compute(int i,int pos)
{
	int curpos;
	if (i==19) 
	{
		ret++;
		if (ret>=10000) {
			ret=0;
		}
		return;
	}
	else
	{
		while ((curpos=strline.find(str[i],pos))!=-1)
		{
			compute(i+1,curpos+1);
			pos=curpos+1;
		}
	}

}
void main()
{
	int i;
	ifstream fin("CProblem.in");
	ofstream fout("CProblem.out");
	fin>>caseN;
	fin.getline(line,510);
	for (i=1;i<=caseN;i++)
	{
		fin.getline(line,510);
		ret=0;
		strline=line;
		compute(0,0);
		for (int j=0;j<4;j++) 
		{
			total[3-j]=ret%10+'0';
			ret=ret/10;
		}
		total[4]='\0';
		fout<<"Case #"<<i<<": "<<total<<endl;
	}
	fin.close();
	fout.close();
}