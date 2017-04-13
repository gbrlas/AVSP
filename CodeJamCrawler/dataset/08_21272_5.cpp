#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>

using namespace std;

int caseNum;
int engineNum;
int queryNum;
char searchEngine[10][100];
char caseArray[100][100];
int nextUse[10][100];

void initNextUse()
{
	for(int i=0;i<10;i++)
		for(int j=0;j<100;j++)
			nextUse[i][j]=100;
}

void findUse(int qn)
{
	int i,j,k,low,high;
	for(i=0;i<engineNum;i++)
	{
		low = 0;
		for(j=0;j<qn;j++)
		{
			if( !strcmp( searchEngine[i], caseArray[j] ) )
			{
				high = j;
				for(k=low; k<=high; k++)
				{
					nextUse[i][k] = high;
				}
				low = high+1;
			}
		}
	}
}

void printNextUse(int qn)
{
	for(int i=0; i<engineNum; i++)
	{
		cout<<searchEngine[i]<<": ";
		for(int j=0; j<qn; j++)
		{
			cout<<nextUse[i][j]<<" ";
		}
		cout<<endl;
	}
}

int saveUniverse(int qn)
{
	int i,j,maxq=0,maxc,count=0;
	for(i=0; i<qn; )
	{
		for(j=0; j<engineNum; j++)
		{
			if(nextUse[j][i]>maxq)
			{
				maxq = nextUse[j][i];
				maxc = j;
			}
		}
		i = maxq;
		count++;
		//cout<<"Use Search Engine "<<searchEngine[maxc]<<" to "<<maxq<<endl;
	}
	return count-1;
}

int main()
{
	int i,j;
	char temp[100];
	//ifstream in("Sample.in");
	//ofstream out("Sample.out");
	ifstream in("A-small-attempt5.in");
	ofstream out("A-small-attempt5.out");
	in.getline(temp, 100);
	caseNum = atoi(temp);
	//cout<<"Case Num: "<<caseNum<<endl;
	for(i=0;i<caseNum;i++)
	{
		in.getline(temp, 100);
		engineNum=atoi(temp);
		//cout<<"Engine Num: "<<engineNum<<endl;
		for(j=0;j<engineNum;j++)
		{
			in.getline(searchEngine[j], 100);
			//cout<<searchEngine[j]<<endl;
		}
		in.getline(temp, 100);
		queryNum=atoi(temp);
		//cout<<queryNum<<endl;
		for(j=0;j<queryNum;j++)
		{
			in.getline(caseArray[j], 100);
			//cout<<caseArray[j]<<endl;
		}
		if(queryNum==0)
		{
			out<<"Case #"<<i+1<<": 0"<<endl;
			continue;
		}
		initNextUse();
		findUse(queryNum);
		//printNextUse(queryNum);
		int res = saveUniverse(queryNum);
		out<<"Case #"<<i+1<<": "<<res<<endl;
	}
	return 0;
}
