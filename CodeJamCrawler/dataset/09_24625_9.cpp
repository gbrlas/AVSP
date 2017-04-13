#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
int main()
{
	fstream fin("B-small-attempt1.in");
	fstream fout("out.txt",fstream::out);
	int cases;
	fin>>cases;
	for(int i = 0;i<cases;i++)
	{
		int num;
		fin>>num;
		vector<int> n;
		while(num!=0)
		{
			n.push_back(num%10);
			num/=10;
		}
		reverse(n.begin(),n.end());
		if(!next_permutation (n.begin(), n.end()))
		{
			n.insert(n.begin()+1,0);
			while(n[0]==0)
				next_permutation (n.begin(), n.end());
		}
		fout << "Case #"<<i+1<<": ";
		for(int j=0; j<n.size(); j++)
		{
			fout<<n[j];
		}
		fout<<endl;
	}
	fin.close();
	fout.close();
}