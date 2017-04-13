#include<iostream>
#include<fstream>
#include<cmath>
#include<cstdlib>
#include<deque>
#include<algorithm>
using namespace std;
void solve(int c, int n, std::deque<double> a, std::deque<double> b, ofstream& out)
{
	int war = 0;
	int dwar = 0;
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	std::deque<double> temp_b = b;
	std::deque<double> temp_a = a;
	for(int i  =0; i < n; i++)
	{
		double a_val = a.front();
		double b_val = b.front();
		a.pop_front();
		b.pop_front();
		if(a_val > b_val)
		{
			//lie and win
			dwar++;
		}
		else
		{
			//lie and lose
			b.push_front(b_val);
			b.pop_back();
		}
	}
	b=temp_b;
	a=temp_a;
	//war
	for(int i = 0; i < n; i++)
	{
		double a_val = a.front();
		double b_val = b.back();
		a.pop_front();
		if(b_val < a_val)
		{
			b.pop_front();
			war++;
		}
		else
		{
			for(int j = 0; j < n; j++)
			{
				if(b[j] > a_val)
				{
					b.erase(b.begin()+j);
					break;
				}
			}
		}
	}
		
	out<<"Case #"<<c<<": "<<dwar<<" "<<war<<endl;
}

int main(int argc, char* argv[])
{
	ifstream input(argv[1]);
	ofstream output("war.txt",ios::trunc|ios::out);
	int numCases;
	input>>numCases;
	for(int i = 0; i < numCases; i++)
	{
		int n;
		input>>n;
		std::deque<double> naomi;
		std::deque<double> ken;
		for(int j = 0; j < n; j++)
		{
			double value; input>>value;
			naomi.push_back(value);
		}	
		for(int j = 0; j < n; j++)
		{
			double value; input>>value;
			ken.push_back(value);
		}
		solve(i+1,n,naomi,ken,output);
	}
}
