#include<iostream>
#include<cstdlib>
#include<cmath>
#include<fstream>

using namespace std;
void solve(int n, double c, double f, double x, ofstream& out)
{
	double num_seconds = 0;
	double def_rate = 2.0;
	int    num_farms = 0;

//minimize	num_seconds = num_farms*c/def_rate + x/(def_rate+f*num_farms);
	
	double farm_time = c/def_rate;
	num_farms = 1;
	num_seconds = x/def_rate;
	double prev = num_seconds;
	do
	{
		prev = num_seconds;
		num_seconds = farm_time + x/(def_rate+f*num_farms);
//		cout<<"num_farms: "<<num_farms<<" num_secs: "<<num_seconds<<" prev: "<<prev<<endl;
		farm_time += c/(def_rate + f*num_farms);
		num_farms++;

	}while(num_seconds < prev);
	

	
	out<<"Case #"<<n<<": "<<prev<<endl;
}
int main(int argc, char* argv[])
{
	ifstream input(argv[1]);
	ofstream output("cookie.txt",ios::trunc|ios::out);
	output.precision(10);
	int numCases;
	input>>numCases;
	for(int i = 0; i < numCases; i++)
	{
		double c,f,x;
		input>>c;input>>f;input>>x;
		solve(i+1,c,f,x,output);
	}
}
