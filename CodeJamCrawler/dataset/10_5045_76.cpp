#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int gcd(int a, int b)
{
	if(b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int gcdn(vector<int> num, int length)
{
	if(length == 1)
		return num[0];
	else
	{
		return gcd(num[length - 1], gcdn(num, length - 1));
	}
}

int main(int argc, char *argv[])
{
	int C,N;
	ifstream input("B-small-attempt0.in");
	ofstream output("B-small.out");
	input>>C;
	for(int i = 0; i < C; i++)
	{
		input>>N;
		vector<int> t;
		for(int j = 0; j < N; j++)
		{
			int temp;
			input>>temp;
			t.push_back(temp);
		}
		vector<int> diffs;
		for(int j = 0; j < t.size(); j++)
		{
			for(int k = j + 1; k < t.size(); k++)
			{
				diffs.push_back(t[j] - t[k]);
			}
		}
		int T = gcdn(diffs, diffs.size());
		if(T < 0)
			T *= -1;
		output<<"Case #"<<i+1<<": ";
		if(T == 1)
		{
			output<<0<<endl;
		}
		else
		{
			int num = t[0];
			if(num % T == 0)
			{
				output<<0<<endl;
			}
			else
			{
				int y = (num / T + 1) * T - num;
				output<<y<<endl;
			}
		}
	}
	return 0;
}