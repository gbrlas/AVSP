#include<iostream>
#include<fstream>
#include<set>
#include<algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	ifstream input(argv[1]);
	ofstream output("magic.txt",ios::trunc|ios::out);
	int numCases;
	input>>numCases;
	for(int i = 0; i < numCases; i++)
	{
		int ans1, ans2;
		int arr1[4][4],arr2[4][4];
		input>>ans1;
		for(int x = 0; x <4; x++)
		{
			for(int y = 0; y < 4; y++)
			{
				input>>arr1[x][y];
			}
		}
		input>>ans2;
		
		for(int x = 0; x <4; x++)
		{
			for(int y = 0; y < 4; y++)
			{
				input>>arr2[x][y];
			}
		}
		//solve
		set<int> set1,set2;
		for(int c = 0; c < 4; c++)
		{
			set1.insert(arr1[ans1-1][c]);
			set2.insert(arr2[ans2-1][c]);
		}
		std::set<int>result;
		set_intersection(set1.begin(),set1.end(),set2.begin(),set2.end(),std::inserter(result,result.begin()));
		if(result.size()==1)
		{
			output<<"Case #"<<i+1<<": "<<*(result.begin())<<endl;
		}
		else if(result.size() >1)
		{
			output<<"Case #"<<i+1<<": "<<"Bad magician!"<<endl;	
		}
		else if(result.size() ==0)
		{
			output<<"Case #"<<i+1<<": "<<"Volunteer cheated!"<<endl;	
		}

		
	}
}
