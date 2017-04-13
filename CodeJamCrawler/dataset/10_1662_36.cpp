#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>

using namespace std;

struct wire
{
	wire(int b1,int b2)
	{
		h1 = b1;
		h2 = b2;
	}
	int h1,h2;
};

bool compare(wire w1 , wire w2)
{
	if(w1.h1 < w2.h1)
		return false;
	else
		return true;
}

int main()
{
	ifstream fin("a.in");
	ofstream fout("a.out");
	int t;
	fin >>t;
	for(int i = 0 ; i< t; i++)
	{
		int n;
		int counter = 0;
		fin >> n;
		vector<wire> wires;
		for(int j = 0 ; j<n; j++)
		{
			int b1 ,b2;
			fin >> b1 >> b2;
			wire w(b1,b2);
			wires.push_back(w);
		}
		sort(wires.begin(),  wires.end() , &compare);
		for(int j = 0 ;j < n-1; j++)
		{
			for(int k = j+1; k < n; k++)
			{
				if(wires[k].h2 > wires[j].h2)
				{
					counter++;
				}
			}
		}
		fout << "Case #" <<i+1 << ": " <<counter << endl;
	}
}
