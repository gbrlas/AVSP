#include<iostream>
#include<fstream>

using namespace std;

/*
void determine(int n1,int n2,int arr1[][4],int arr2[][4],ofstream fout)
{
int cnt=0;
int rst;
for(int i=0;i<4;i++)
{
for(int j=0;j<4;j++)
{
if(arr1[n1-1][i]==arr2[n2-1][j])
{
cnt++;
rst=arr1[n1-1][i];
}
}
}

if(cnt==0)
{
fout<<"Volunteer cheated!\n";
}
else if(cnt==1)
{
fout<<"%d\n"<<rst;
}
else
{
fout<<"Bad magician!\n";
}
}*/

int main()
{
	int T;
	ifstream fin;
	ofstream fout;

	fin.open("A-small-attempt1.in");

	fout.open("result.txt");

	fin>>T;

	for(int i=1; i<=T ; i++)
	{
		int num1;
		int num2;

		int arr1[4][4];
		int arr2[4][4];

		fin>>num1;
		for(int j=0;j<4;j++)
		{
			for(int k=0;k<4;k++)
			{
				fin>>arr1[j][k];
			}
		}

		fin>>num2;
		for(int j=0;j<4;j++)
		{
			for(int k=0;k<4;k++)
			{
				fin>>arr2[j][k];
			}
		}

		fout<<"Case #"<<i<<": ";

		int cnt=0;
		int rst;
		for(int j=0;j<4;j++)
		{
			for(int k=0;k<4;k++)
			{
				if(arr1[num1-1][j]==arr2[num2-1][k])
				{
					cnt++;
					rst=arr1[num1-1][j];
				}
			}
		}

		if(cnt==0)
		{
			fout<<"Volunteer cheated!\n";
		}
		else if(cnt==1)
		{
			fout<<rst<<"\n";
		}
		else
		{
			fout<<"Bad magician!\n";
		}
	}

	fin.close();
	fout.close();


	return 0;
}