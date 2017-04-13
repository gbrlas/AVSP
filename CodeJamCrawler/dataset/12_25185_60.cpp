#include <fstream>
#include <iostream>
#include <set>
using namespace std;

ofstream f;

int get_multi_value(int n)
{
	int ret = 10;
	while(n/10 > 0)
	{
		n /= 10;
		ret *= 10;
	}
	return ret;
}

int get_m(int n, int factor)
{
	int high_num = n%factor;
	int low_num = n/factor;
	return get_multi_value(low_num)*high_num + low_num;
}

int check(int n, int max)
{
	set<int> ms;
	int factor = 10;
	while (n/factor > 0)
	{
		int m = get_m(n, factor);
		if (m > n && m <= max)
		{
			ms.insert(ms.begin(), m);
		}

		factor *= 10;
	}
	return ms.size();;
}

int main()
{
	ifstream in_file("inputC.txt");
	ofstream out_file("outputC.txt");
	int T;
	in_file>>T;
	for (int i=1; i<=T; i++)
	{
		int A, B;
		int num = 0;
		in_file>>A>>B;
		for (int j=A; j<B; j++)
		{
			num += check(j, B);
		}
		out_file<<"Case #"<<i<<": "<<num<<endl;
	}
	in_file.close();
	out_file.close();
	return 0;
}