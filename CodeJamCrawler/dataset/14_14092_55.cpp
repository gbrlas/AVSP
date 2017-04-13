#include<fstream>
#include<iomanip>
using namespace std;

int main()
{
	string name1="input.txt";
	string name2="output.txt";
	ifstream ist(name1.c_str());
	ofstream ost(name2.c_str());
	int n;
	ist>>n;
	for (int i=0;i<n;i++)
	{
		double c,f,x,time,c_now,farm_now;
		time=0;
		c_now=0;
		farm_now=0;
		ist>>c>>f>>x;
		if (x<c) time=x/2;
		else
		while (true)
		{
			time=time+c/(2+farm_now*f);
			c_now=c_now+c;
			double solve1=(x-c_now)/(farm_now*f+2);
			double solve2=(x-c_now+c)/((farm_now+1)*f+2);
			if (solve1<=solve2)
			{
				time=time+solve1;
				break;
			}else
			{
				farm_now++;
				c_now=c_now-c;
			}
		}
		ost<<"Case #"<<i+1<<": "<<fixed<<setprecision(7)<<time<<"\n";
	}
}