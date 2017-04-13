#include<fstream>
#include<algorithm>
#include<vector>
#include <iomanip>  
using namespace std;

ifstream in("b.in");
ofstream out("b.out");


int main()
{
	int t, i, j;
	double f, x, c;
	in>>t;
	for (i=1; i<=t; i++)
	{
		in>>c>>f>>x;
		double time=0, r=2;
		while (1)
		{
			if (x/r < c/r+x/(f+r))
			{
				time+=x/r;
				break;
			}
			else
			{
				time+=c/r;
				r=r+f;
			}
		}
		out<<"Case #"<<i<<": ";
		out<< fixed << setprecision(7)<<time<<endl;
	}
}