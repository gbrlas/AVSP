#include <iostream>
#include <conio.h>
#include <fstream>
#include <cmath>
using namespace std;

#define ULL unsigned long long
bool is_perfect_square(ULL n) 
{
    ULL root = floor(sqrt(n));
    return (n == root * root);
}
ULL rev(ULL n)
{
	ULL ret=0;
	while (n>0)
	{
		ret = ret*10 + n%10;
		n/=10;
	}
	return ret;
}
int main()
{
	ofstream cout ("CSmall.out");
	ifstream cin ("CSmall.in");

	int t;
	cin>>t;
	for (int i=1; i<=t; i++)
	{
		cout<<"Case #"<<i<<": ";

		int a,b,count=0;
		cin>>a>>b;
		for (int num=a; num<=b; num++)
			if (is_perfect_square(num) && num==rev(num) && sqrt(num)==rev(sqrt(num)))
				count++;
		cout<<count;

		cout<<endl;
	}
	return 0;
}