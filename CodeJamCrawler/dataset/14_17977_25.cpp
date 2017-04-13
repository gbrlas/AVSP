#include <iostream>
#include <cstdio>
using namespace std;

int main()
{		int T;
		cin>>T;
		for (int x = 1; x <= T; ++x)
		{
			double cookies_rate = 2;
			double C,F,X;
			cin>>C;
			cin>>F;
			cin>>X;
			double sum = 0,possible_sum,next_sum;
			
			
			while(1)
			{
				possible_sum = sum + C/cookies_rate + X/(cookies_rate + F);
				next_sum = sum + X/cookies_rate;
				if (next_sum > possible_sum)
				{
					sum = sum + C/cookies_rate;
					cookies_rate += F;
				}

				else
				{
					sum = next_sum;
					break;
				}
			}

			printf("Case #%d: %.7lf\n",x,sum );
		}
		


		
}
