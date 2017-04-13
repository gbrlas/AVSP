#include<iostream>
#include<fstream>

using namespace std;

int main(void)
{
	ifstream fin;
	ofstream fout;
	fin.open("input2.txt");
	fout.open("output2.txt");
	
	int t;
	fin>>t;
	int cas=1;
	while(t-->0)
	{
		fout<<"Case #"<<cas<<": ";
		int n,s,p;
		fin>>n>>s>>p;
		int arr[n];
		
		int count=0;
		int i;
		for(i=0;i<n;i++)
		{
			fin>>arr[i];
		}
		
		if(p==0)
		{
			count=n;
		}
		else
		{
			for(i=0;i<n;i++)
			{
				if(arr[i]==0)
				{
					continue;
				}
				else
				if(arr[i]>=((p*3)-2))
				{
					count++;
				}
				else
				if(arr[i]>=((p*3)-4))
				{
					if(s>0)
					{
						count++;
						s--;
					}
				}
			}
		}
		fout<<count<<"\n";
		cas++;
	}	
	return 0;
}
	
		
		
		
		
