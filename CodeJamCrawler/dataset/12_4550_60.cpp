#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <fstream>
#include <set>

using namespace std;

int len(int n, int & mask)
{
	int ans = 1;
	mask = 1;
	while(n/10 > 0)
	{
		mask*=10;
		n/=10;
		ans++;
	}
	return ans;
}

int recycle(const int n, int MAX, vector<bool> & seen)
{
	int mask;
	int size = len(n, mask), ans = 1;
	seen[n] = true;		
	
	int cur = n;
	for(int i=0;i<size-1;i++)
	{
		int digit = cur%10;
		cur/=10;
		cur+=mask*digit;
		if(cur>n && cur<=MAX && !seen[cur])
		{
			seen[cur] = true;
			ans++;
		}
	}

	return (ans*(ans-1)/2);
}

void main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int T;
	fin>>T;
	for(int c=1;c<=T;c++)
	{
		int A, B;
		fin>>A>>B;
		int ans = 0;
		vector<bool> seen(B+10, false);
		for(int i=A;i<=B;i++)
		{
			if(seen[i])
				continue;
			ans += recycle(i,B,seen);
		}
		fout<<"Case #"<<c<<": "<<ans<<endl;
	}
	fout.close();	
	fin.close();
}