#ifdef WIN32
#pragma warning (disable: 4514 4786)
#endif
#include <iostream>
#include <fstream>
#include <set>
#include <string>
using namespace std;
//*****************
int L,D,caseN;
int num;
set<string> subDic[15];
string input;
char tempWord[16];
void countNum(int tempI,int strI)
{
	string temp;
	int i,pos;
	if (tempI==L)
	{
	    num++;		
	}
	else
	{
		if (input[strI]!='(')
		{
			tempWord[tempI]=input[strI];
			if (subDic[tempI].find(string(tempWord,tempWord+tempI+1))!=subDic[tempI].end()) 
			{
				countNum(tempI+1,strI+1);
			}
		}
		else
		{
			pos=input.find(')',strI);
			for (i=strI+1;i<=pos-1;i++)
			{
				tempWord[tempI]=input[i];
				if (subDic[tempI].find(string(tempWord,tempWord+tempI+1))!=subDic[tempI].end()) 
				{
					countNum(tempI+1,pos+1);
				}
			}
		}
	}
}
void main()
{
	int i,j;
	ifstream fin("A_Problem.in");
	ofstream fout("A_Problem.out");
	fin>>L>>D>>caseN;
	for(i=1;i<=D;i++)
	{
		fin>>input;
		for (j=0;j<L;j++) 
		{
			subDic[j].insert(string(input.begin(),input.begin()+j+1));
		}
	}
	for (i=1;i<=caseN;i++) 
	{
		fin>>input;
		num=0;
		countNum(0,0);
		fout<<"Case #"<<i<<": "<<num<<endl;
	}
	fin.close();
	fout.close();
}