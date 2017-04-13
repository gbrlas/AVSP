#include<iostream>
#include"math.h"
using namespace std;

void main()
{
	FILE *input,*output;
	input=freopen("A-small-attempt0.in","r",stdin);
	output=freopen("output.txt","w",stdout);
	int num;
	long long r,t;
	cin>>num;
	for(int k=0;k<num;k++)
	{
	cin>>r;
	cin>>t;
	long long n=0;
	n=(-(2*r-1)+sqrt((2*r-1)*(2*r-1)+8*t))/4;
	cout<<"Case #"<<k+1<<": "<<n<<endl;
	}
}