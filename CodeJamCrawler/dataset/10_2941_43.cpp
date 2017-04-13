#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
	//input
	ifstream invoer;
	invoer.open("A-small.in");
	int testcases;
	long int N;
	long int K;
	double power;
	string out;
	char buf[10001];

	invoer >> testcases;
	for (int i =1; i<=testcases; i++)
	{
		invoer >> N;
		invoer >> K;
		power = pow(2.0, N);
		//algorithm
		out.append("Case #");
		out.append(itoa(i,buf,10));
		out.append(":");
		if ((K+1)%(int(power)) == 0)
		{
			out.append(" ON");
		}
		else
		{
			out.append(" OFF");
		}
		out.append("\n");
	}
	invoer.close();
	
	//output
	ofstream uitvoer;
	uitvoer.open("A-small.txt");
	uitvoer << out;
	uitvoer.close();
	return 0;
}