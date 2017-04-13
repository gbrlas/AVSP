#include "iostream"
#include "fstream"
#include "string"
#include "sstream"
#include "math.h"
using namespace std;

bool palindrome(long long num)
{/*
	ostringstream convert;   
	convert << num;      
	string Result = convert.str();*/

	long long n = num, rev = 0;
	int dig = 0;
	 while (num > 0)
	 {
		  dig = num % 10;
		  rev = rev * 10 + dig;
		  num = num / 10;
	 }
	 if(n == rev)
		 return true;
	 else
		 return false;
}

int main()
{
	string line;
	ifstream input("C-small-attempt0.in");
	ofstream output("output.txt", ios::out | ios::trunc);
	if(input.is_open() && output.is_open())
	{
			getline(input,line);
			int T = atoi(line.c_str());
			for(int i=1;i<=T;i++)
			{
				long long A,B;
				int y=0;
				//string sa,sb;
				getline(input,line);

				stringstream ss(line);
				while(ss.good())
				{
				ss >> A >> B;
				}
				/*A=atol(sa.c_str());
				B=atol(sb.c_str());*/
				for(long long j=A;j<=B;j++)
				{
					if(palindrome(j))
					{
						long double d_sqrt = sqrt((long double) j );
						long long i_sqrt = d_sqrt;
						if ( d_sqrt == i_sqrt )
						{
							if(palindrome(i_sqrt))
								y++;
						}
					}
				}
				
				output<<"Case #"<<i<<": "<<y<<endl;
			}
	}
}