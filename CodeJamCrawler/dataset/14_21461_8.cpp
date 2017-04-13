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

class PartElf
{
	long P;
	long Q;
public:
	void start()
	{
		int numInput=0;
		cin>>numInput;

		for(int i=0; i<numInput; i++)
		{
			readInput();
			cout<<"Case #"<<i+1<<": ";
			solve();
		}
	}

	void readInput()
	{
		char c;
		cin>>P>>c>>Q;
		//cout<<P<<" "<<Q<<" ";
	}

	void solve()
	{
		if(isPosibleToResovle(Q)==false)
			cout<<"impossible"<<endl;
		else
		{
			for(int i=1; i<40; i++)
			{
				P=P*2;
				if(P>=Q)
				{
					cout<<i<<endl;
					return;
				}
			}
		}
	}

	bool isPosibleToResovle(long Q)
	{
		if(Q%P==0)
		{
			Q=Q/P;
		}
		if(Q>1000000 || P>Q)
			return false;
		int i=0;
		for(int j=0; j<36; j++)
		{
			if(Q%2==1)
				i++;
			if(i>1)
				return false;
			Q=Q>>1;
			//std::cout<<Q<<endl;
		}
		//cout<<endl;
		return true;
	}
};

int main()
{
	PartElf PE;
	PE.start();
	return 0;
}
