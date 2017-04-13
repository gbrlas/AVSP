#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	string name;
	name="input.txt";
	ifstream ist(name.c_str());
	string name2="output.txt";
	ofstream ost(name2.c_str());
	int n;
	ist>>n;
	for (int i=0;i<n;i++)
	{
		int m1,m2;
		int a1[4][4],a2[4][4];
		int temp[17];
		for (int j=1;j<=16;j++){
			temp[j]=0;
		}
		ist>>m1;
		for (int j=0;j<4;j++)
			for (int k=0;k<4;k++)
			{
				ist>>a1[j][k];
			}
		for (int j=0;j<4;j++)
		{
			temp[a1[m1-1][j]]++;
		}
		ist>>m2;
		for (int j=0;j<4;j++)
			for (int k=0;k<4;k++)
			{
				ist>>a2[j][k];
			}
		for (int j=0;j<4;j++)
		{
			temp[a2[m2-1][j]]++;
		}
		int count=0;
		int record=-1;
		for (int j=1;j<=16;j++)
		{
			if (temp[j]==2){
				count++;
				record=j;
			}
		}
		ost<<"Case #"<<i+1<<": ";
		switch (count)
		{
		case 1:
			ost<<record;
			break;
		case 0:
			ost<<"Volunteer cheated!";
			break;
		default:
			ost<<"Bad magician!";
			break;
		}
		ost<<"\n";
	}
}