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
		int n;
		cin>>n;
		vector<double> v1,v2,v3,v4;
		for (int i=0;i<n;i++)
		{
			double temp;
			cin>>temp;
			v1.push_back(temp);
			v3.push_back(temp);
		}
		for (int i=0;i<n;i++)
		{
			double temp;
			cin>>temp;
			v2.push_back(temp);
			v4.push_back(temp);
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		sort(v3.begin(), v3.end());
		sort(v4.begin(), v4.end());
		
		int ans1=0, ans2=0;
		for (int i=n-1;i>=0;i--)
		{
			for (int j=n-1;j>=0;j--)
			{
				if (v1[i]>v2[j] && v2[j]!=-1.0)
				{
					ans1++;
					v2[j] = -1.0;
					break;
				}
			}
		}
		
		for (int i=n-1;i>=0;i--)
		{
			int temp = -1;
			for (int j=n-1;j>=0;j--)
			{
				if (v3[i]<v4[j])
				{
					temp = j;
					continue;
				}
			}
			if (temp==-1)
			{
				for (int j=0;j<n;j++)
				{
					if (v4[j]!=-1.0)
					{
						if (v3[i]>v4[j]) {
							//cout<<v3[i]<<" "<<v4[j]<<endl;
							ans2++;
						}
						v4[j]=-1.0;
						break;
					}
				}
			}
			else
			{
				if (v3[i]>v4[temp]) {
					//cout<<v3[i]<<" "<<v4[temp]<<endl;
					ans2++;
				}
				v4[temp]=-1;
			}
		}
		cout<<"Case #"<<count++<<": ";
		cout<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}

