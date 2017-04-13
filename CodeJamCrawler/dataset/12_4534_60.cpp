#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

void main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int T;
	fin>>T;
	for(int c=1;c<=T;c++)
	{
		int su, p, n;
		fin>>n>>su>>p;
		vector<int> scores(n);
		for(int i=0;i<n;i++)
			fin>>scores[i];

		int ans = 0;
		if(p==0)
			ans = n;
		else
		{
			for(int i=0;i<n;i++)
			{
				if(p==1)
				{
					if(scores[i] >= 1)
						ans++;
				}
				else if(scores[i] >= p*3-2)
					ans++;
				else if(scores[i] >= p*3-4 && su>0)
				{
					su--;
					ans++;
				}
			}
		}
		fout<<"Case #"<<c<<": "<<ans<<endl;
	}

}