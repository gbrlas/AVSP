#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int num;

int main()
{
	ifstream in("F:\\Users\\Simy\\Downloads\\C-small-attempt2.in");
	if(in == NULL)
	{
		cout << "hello" << endl;
	}
	ofstream out("a.out");
	in >> num;
	for(int i = 0;i<num;i++)
	{
		int j;
		in >> j;
		vector<int> a(j);
		for(int k = 0;k<j;k++)
		{
			in >> a[k];
		}
		int result = 0;
		for(int m = 0;m<j;m++)
		{
			result = result ^ a[m];
		}
		out << "Case #" << i+1 << ": ";
		if(result == 0)
		{
			unsigned min = 1000000;
			for(int n = 0;n<j;n++)
			{
				min = ( (min<a[n]) ? min:a[n] );
			}
			unsigned long sum = 0;
			for(int l = 0;l<j;l++)
			{
				sum += a[l];
			}
			sum -= min;
			out << sum << endl;
		}
		else
		{
			out << "NO" << endl;
		}
	}
	return 0;
}