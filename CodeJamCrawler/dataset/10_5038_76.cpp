#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int pow(int a, int b)
{
	if(b == 1)
		return a;
	else
		return a * pow(a, b - 1);
}

int main(int argc, char *argv[])
{
	ifstream input("A-large.in");
	ofstream output("A-large.out");
	int T, N, K;
	input>>T;

	for(int i = 0; i < T; i++)
	{
		input>>N;
		input>>K;
		//vector<int> snappers(N);
		//int iter = 1;
		//for(int j = 0; j < K; j++)
		//{
		//	int carry = 0;
		//	for(int k = 0; k < N; k++)
		//	{
		//		if(snappers[k] == 1)
		//		{
		//			carry = 1;
		//			snappers[k] = 0;
		//		}
		//		else
		//		{
		//			carry = 0;
		//			snappers[k] = 1;
		//		}
		//	}
		//}
		
		output<<"Case #"<<i+1<<": ";
		if((K+1)%pow(2,N) == 0)
		{
			output<<"ON"<<endl;
		}
		else
		{
			output<<"OFF"<<endl;
		}
		//bool flag = true;
		//for(int j = 0; j < snappers.size(); j++)
		//{
		//	if(snappers[j] == 0)
		//	{
		//		flag = false;
		//		break;
		//	}
		//}
		//if(flag)
		//{
		//	output<<"ON"<<endl;
		//}
		//else
		//{
		//	output<<"OFF"<<endl;
		//}
	}
	return 0;
}