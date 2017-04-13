#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{

	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);


	int t;
	cin >> t;
	for(int test = 0; test < t; test++)
	{
		int n;
		cin >> n;
		vector<int> candies(n);
		int sean = 0;
		for(int i=0; i<n; i++)
		{
			cin >> candies[i];
			sean ^= candies[i];
		}
		if(sean)
		{
			cout << "Case #" << test+1 << ": NO\n" ;
			continue;
		}
		sort(candies.begin(), candies.end());
		sean ^= candies[0];
		int patrick = candies[0];
		int i = 1;
		for(i=1; i<n; i++)
		{
			if(sean == patrick)
				break;
			patrick ^= candies[i];
			sean ^= candies[i];
		}
		int result = 0;
		for(i; i<n; i++)
			result += candies[i];
		

		cout << "Case #" << test+1 << ": " << result << "\n";
		
	}

	return 0;
}