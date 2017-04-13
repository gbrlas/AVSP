#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <stdio.h>

using namespace std;

int main()
{
	int tc;
	cin>>tc;
	int count=1;
	while (tc--)
	{
		vector<int> v;
		int a, temp;
		int sama = 0;
		int ans = 0;
		cin>>a;
		for (int i=0;i<4;i++)
		{
			for (int j=0;j<4;j++)
			{
				cin>>temp;
				if (i==a-1)
					v.push_back(temp);
			}
		}
		cin>>a;
		for (int i=0;i<4;i++)
		{
			for (int j=0;j<4;j++)
			{
				cin>>temp;
				if (i==a-1)
				{
					for (int k=0;k<v.size();k++)
						if (v[k]==temp)
						{
							sama++;
							ans = temp;
						}
				}
			}
		}
		
		cout<<"Case #"<<count++<<": ";
		if (sama==1)
			cout<<ans<<endl;
		else if (sama==0)
			cout<<"Volunteer cheated!"<<endl;
		else
			cout<<"Bad magician!"<<endl;
	}
	return 0;
}

