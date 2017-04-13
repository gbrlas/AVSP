#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	int T;
	ifstream in_file("input.txt");
	ofstream out_file("output.txt");
	in_file>>T;
	for (int i=1; i<=T; i++)
	{
		int num = 0;
		int	N, S, p;
		in_file>>N>>S>>p;
		for (int j=0; j<N; j++)
		{
			int t;
			in_file>>t;
			int each = t/3;
			if (t%3 == 0)
			{
				if (each >= p)
				{
					num++;
				}
				else if (each+1 >= p && each-1 >=0 && S > 0)
				{
					S--;
					num++;
				}
			}
			else if (t%3 == 1)
			{
				if (each+1 >= p)
					num++;
			}
			else if (t%3 == 2)
			{
				if (each+1 >= p)
				{
					num++;
				}
				else if (each+2 >= p && S > 0)
				{
					S--;
					num++;
				}
			}
			cout<<"After "<<t<<":"<<num<<endl;
		}
		cout<<endl;
		out_file<<"Case #"<<i<<": "<<num<<endl;
	}
	out_file.close();
	in_file.close();
	return 0;
}