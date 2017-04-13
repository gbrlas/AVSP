#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#define FOR(i, n) for(int (i) = 0; (i) < (int) (n); (i)++)

int main(int argc, char *argv)
{
	ifstream input("A-large.in");
	ofstream output("A-large.out");
	int T;
	input>>T;
	FOR(cases, T)
	{
		int N;
		input>>N;
		vector<int> A;
		vector<int> B;
		FOR(i, N)
		{
			int Ai, Bi;
			input>>Ai>>Bi;
			A.push_back(Ai);
			B.push_back(Bi);
		}
		int intersectionPoints = 0;
		int currentA, currentB;
		FOR(i, N)
		{
			currentA = A[i];
			currentB = B[i];
			for(int j = i + 1; j < N; j++)
			{
				int anotherA = A[j];
				int anotherB = B[j];
				if(currentA < anotherA && currentB < anotherB)
				{
					;
				}
				else if(currentA > anotherA && currentB > anotherB)
				{
					;
				}
				else
				{
					intersectionPoints++;
				}
			}
		}
		output<<"Case #"<<cases+1<<": "<<intersectionPoints<<endl;
	}
}