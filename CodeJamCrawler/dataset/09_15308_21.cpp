#include<iostream> 
#include<algorithm>
#include<queue>
#include<stack>
#include<numeric>
#include<vector>
#include<sstream>
#include<strstream>
#include<string>
#include<cmath>
#include<cstdlib>
#include<map>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int t = 0; t < T; t++)
	{
		int N;
		cin >> N;
		vector<int> nums(N, 0);
		for(int i=0; i<N; i++)
		{
			cin >> ws;
			for (int j = 0; j<N; j++)
			{
				char ch;
				cin >> ch;
				if (ch == '1')
					nums[i] = j;
			}
		}

		int res = 0;
		for(int i=0; i<N; i++)
		{
			if (nums[i]>i)
			{
				int j;
				for(j=i+1; j<N && nums[j]>i; j++)
					;
				int good = nums[j];
				for(;j>i;j--)
				{
					nums[j]=nums[j-1];
					res++;
				}
				nums[i] = good;
			}
		}

		cout << "Case #" << (t+1) << ": " << res << endl;
	}


	return 0;
}