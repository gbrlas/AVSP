#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))
void doxor(int &sum,int &temp)
{
	int ctr=0;
	for(int i=0;i<=9;i++)
	{
		int base=(1<<i);
		if(sum>=base || temp>=base)
		{
			if((sum & base)!=(temp & base)) ctr+=base;
		}
	}
	sum=ctr;
}
int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("C:\\Data\\C-small-attempt1.in");
	fout.open("C:\\Data\\outp2.txt");
	int t;
	fin>>t;
	int total=t;
	while(t--)
	{
	 int n;
	 fin>>n;
	 int sum=0;
	 int tot=0;
	 int mini=1e9;
	 FOR(i,0,n)
	 {
		 int temp;
		 fin>>temp;
		 if(mini>temp) mini=temp;
		 doxor(sum,temp);
		 tot+=temp;
	 }
	 if(sum==0)
	 {
		fout<<"Case #"<<total-t<<": "<<tot-mini<<endl;
	 }
	 else
		fout<<"Case #"<<total-t<<": NO"<<endl;  
	 
    }
}
