#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define VI vector<int>
#define PII pair<int,int>
#define MP make_pair

int test ,  i , j,  n, k;

int main()
{
	freopen("c:/input.txt" , "r" , stdin);
	freopen("c:/output.txt" , "w" , stdout);
	
	cin>>test;
	
	for (int t = 1 ; t <= test; t++)
	{
		int o = 1 , b = 1;
		int to = 0 , bo = 0;
		cin>>n;
		for (i= 0; i < n; i++)
		{
			char c;
			int k;
			cin>>c>>k;
			if (c == 'O')
			{
				to = to + abs(k - o) + 1;
				if (to <= bo)
					to = bo + 1;
				o = k;
			} else
			{
				bo  = bo + abs(k - b) + 1;
				if (bo <= to)
					bo = to + 1;
				b = k;
			}
		}




		cout<<"Case #"<<t<<""<<": "<<max(to , bo)<<endl;
	}

	return 0;
}