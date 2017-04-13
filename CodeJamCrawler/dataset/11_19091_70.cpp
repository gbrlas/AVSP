#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<bitset>
using namespace std;





int main()
{
	ifstream fin("C.in");
	ofstream fout("C.out");
	
	int T, N;
	int* C;
	int BinSum=0,sum=0;
	int GoalSum=0, Seansum=0;
	fin>>T;
	for(int i=1; i<=T; i++)
	{
		fin>>N;
		BinSum=0,sum=0;
		C=new int[N];
		for(int j=0; j<N; j++)
		{
			fin>>C[j];
			BinSum^=C[j];
			sum+=C[j];
		}
		int temp;
		fout<<"Case #"<<i<<": ";
		if(BinSum != 0)
		{
			fout<<"NO\n";
		}
		else
		{
			sort(C,C+N);
			Seansum=sum-C[0];

				
			fout<<Seansum<<endl;
		}
		cout<<i<<endl;
		delete[] C;

	}
	return 0;
}


