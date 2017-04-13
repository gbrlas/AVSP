#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <math.h>
using namespace std;

double STN (string Text )
{                               
	stringstream ss(Text);
	int x=Text.find('m');
	if (x!=-1) return 0;
	double result;
	return ss >> result ? result : 0;
}
string NTS ( double Number )
{
	stringstream ss;
	ss << Number;
	return ss.str();
}
int  gcd(int a,int b)
    {
		if (a<b)
			swap(a,b);
		if (b == 0)
       return a;
	   else
		return  gcd(b, a % b);
		
	}
bool Palindrome1(string S) 
{
	string S1,S2;
	for (int i=0;i<S.size();i++)
	{
		S1+=S[i];
		S2+=S[S.size()-i-1];
	}
	if (S1==S2)
	return true;
	else return false;
}
bool Palindrome(string S) 
{
	string S1,S2;
	for (int i=0;i<S.size();i++)
	{
		S1+=S[i];
		S2+=S[S.size()-i-1];
	}
	if (S1==S2)
	{
		double x=STN(S);
		x=sqrt(x);
		if (Palindrome1 (NTS(x)))
		return true;
		return false;
	}
	else return false;
}
int main()
{
	ifstream cin ("input.txt");
	ofstream cout("Output.txt");
	int n;
	cin>>n;
	for (int number=1;number<=n;number++)
	{
		int Res=0;
		int begin,end;
		cin>>begin>>end;
		string S;
		while (begin<=end)
		{
			
			S=NTS(begin);
			if ( Palindrome(S))
				Res++;
			begin++; 
			
		}
		cout<<"Case #"<<number<<": "<<Res<<endl;
	}
	return 0;
}