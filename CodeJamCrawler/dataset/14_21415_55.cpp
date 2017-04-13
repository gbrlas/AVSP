#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int T,l;
	cin>>T;
	for (l=1;l<=T;l++)
	{
		double F,C,X,s=2,t=0,ans,ans1;
		cin>>C>>F>>X;
		ans=X/s;
		while (1)
		{
			t+=C/s;
			s+=F;
			ans1=t+X/s;
			if (ans1<ans)
			{
				ans=ans1;
			}
			else
			{
				break;
			}
		}
		printf("Case #%d: %.10f\n",l,ans);
	}
}
