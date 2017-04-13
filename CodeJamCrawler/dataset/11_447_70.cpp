#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	ifstream fi("C-small-attempt1.in");
	ofstream fo("output.txt");
	
	unsigned long int T;fi >> T;
	for(unsigned long int i=0; i<T; i++)
	{
		unsigned long int N,sum=0,min=2000000,idiot=0,c;
		fi >> N;
		for(unsigned long int j=0; j<N; j++)
		{
			fi >> c;
			if(min > c) min = c;
			sum += c;
			idiot ^= c;
		}
		fo << "Case #" << i+1 << ": ";
		if(idiot==0)
			fo << sum-min << endl;
		else
			fo << "NO\n";
	}
}