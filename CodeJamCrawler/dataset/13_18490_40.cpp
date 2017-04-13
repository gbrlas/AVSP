#include <iostream>
#include <math.h>

using namespace std;
int main()
{
	freopen("C-small-attempt0.in","rt",stdin);
	freopen("C-small-attempt0.out","wt",stdout);

	int T;
	cin>>T;

	int palindrome[]={1,2,3,11,22};
	for(int i=1;i<=T;i++)
	{
		int A,B;
		cin>>A>>B;

		int Al=(int)ceil(sqrt(double(A)));
		int Bl=(int)floor(sqrt(double(B)));

		int m=0;
		int n=5-1;
		while((Al>palindrome[m])&&(m<5))
		{
			m++;
		}
		while((Bl<palindrome[n])&&(n>=0))
		{
			n--;
		}
		cout<<"Case #"<<i<<": ";
		if(n<m)
		{
			cout<<0<<endl;
		}
		else
		{
			cout<<n-m+1<<endl;
		}
	}
	return 0;
}