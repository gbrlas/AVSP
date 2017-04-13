#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
	ifstream input("C-small-attempt0.in");
	ofstream output("C-small.out");
	int T, R, k, N;
	input>>T;
	for(int i = 0; i < T; i++)
	{
		input>>R>>k>>N;
		vector<int> groups(N);
		for(int j = 0; j < N; j++)
		{
			int temp;
			input>>groups[j];
		}
		int curGroup = 0;
		int euros = 0;
		for(int times = 0; times < R; times++)
		{
			int capacity = 0;
			int numGroups = 0;
			while(true)
			{
				if(capacity + groups[curGroup] <= k)
				{
					capacity += groups[curGroup++];
					numGroups++;
					if(curGroup >= N)
					{
						curGroup = 0;
					}
					if(numGroups == N)
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
			euros += capacity;
		} 
		output<<"Case #"<<i+1<<": "<<euros<<endl;;
	}
	return 0;
}