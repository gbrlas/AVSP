#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>

using namespace std;

int main()
{
	ifstream in;
	//in.open("A-small-attempt2.in");
	//in.open("A-small.in");
	in.open("A-large.in");
	ofstream out;
	out.open("A.out");

	long long N, K, cnt = 0, num;
	in >> num;
	while( num-- )
	{
		string ret; 
		cnt++;
		in >> N >> K;

		long long div = (long long) pow((double)2,(double)N); 

		if( K % div == div - 1 ) ret = "ON";
		else ret = "OFF";

		cout << "Case #" << cnt <<":" << " " << ret << endl;
		out << "Case #" << cnt <<":" << " " << ret << endl;
	}

	return 0;
}