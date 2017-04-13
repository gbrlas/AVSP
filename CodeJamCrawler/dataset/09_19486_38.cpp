#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <set>
#include <string>
#include <fstream>
#include <algorithm>
#include <functional>

using namespace std;

const int inf = 100000000;



map<char,int> mp;

int main()
{

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int N; 
	fin >> N;
	
	

	
	for(int T=0;T<N; ++T)
	{
		string s;
		fin >> s;


		int count = 0; 
		for(int i=0;i<s.length(); ++i)
		{
			if(mp.find(s[i]) == mp.end())
			{
				if(count == 0) mp.insert(std::pair<char,int>(s[i],1)), count++;
				else if(count == 1) mp.insert(std::pair<char,int>(s[i],0)),count++;
				else mp.insert(std::pair<char,int>(s[i],count)),count++;
			}
		}

		unsigned long long result = 0;
		count = max(count,2);
		for(int i = 0; i < s.length(); ++i)
		{
			result = result * count + mp[s[i]];
		}

		fout << "Case #"<<T+1 <<": "<<result <<std::endl;
		mp.clear();
	}




    return 0;
}