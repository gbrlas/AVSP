#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool comp(long long a, long long b)
{
	if( a > b ) return true;
	else return false;
}

int main()
{
	ifstream in;
//	in.open("A.in");
//	in.open("A-small-attempt0.in");
	in.open("A-large.in");
	ofstream out;
	out.open("A.out");
	vector<long long> dat;

	int a, num, cnt, tmp, P, K, L;
	long long ret;

	cnt = 0;
	in >> num;
	while( num-- )
	{
		ret = 0;
		dat.clear();
		in >> P >> K >> L;
		for( a = 0; a < L; a++ )
		{
			in >> tmp;
			dat.push_back(tmp);
		}

		sort(dat.begin(), dat.end(), comp); 
		int N = 0, ct = 0;

		while(ct < dat.size())
		{
			N++;
			int tt = ct;
			for( a = tt; a < tt+K; a++ )
			{
				if( a >= dat.size() ) break;
				ret += dat[a] * N;
				ct++;
			}
		}
		cnt++;

		cout << "Case #" << cnt <<":" << " " << ret << endl;
		out << "Case #" << cnt <<":" << " " << ret << endl;
	}

	return 0;
}