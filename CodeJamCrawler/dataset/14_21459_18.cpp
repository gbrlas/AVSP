//============================================================================
// Name        : Jam.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

class LotteryGame
{
	int A;
	int B;
	int K;
public:
	void start()
	{
		int testCases;
		std::cin>>testCases;
		for(int i=0; i<testCases; i++)
		{
			std::cin>>A>>B>>K;
			cout<<"Case #"<<i+1<<": ";
			solve();
		}
	}

	void solve()
	{
		int count=0;

		for(int a=0; a<A; a++)
		{
			for(int b=0; b<B; b++)
			{
				if((a&b)<=K)
					count++;
			}
		}

		std::cout<<count<<endl;
	}
};

int main() {
	LotteryGame SR;
	SR.start();
	return 0;
}
