#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int T, A, B, digit, multiplier, count;
	bool used[2000000];
	
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		memset(used, false, sizeof(used));
		count = 0;
		
		cin >> A >> B;
		digit = (int)floor(log10(A)) + 1;
		multiplier = pow(10, digit - 1);
		for (int i = A; i <= B; i++)
		{
			if (!used[i])
			{
				used[i] = true;
				
				int shift = i;
				int found = 1;
				for (int d = 1; d < digit; d++)
				{
					shift = (shift / 10) + ((shift % 10) * multiplier);
					if (A <= shift && shift <= B && !used[shift])
					{
						used[shift] = true;
						found++;
					}
				}
				
				// foundC2 - combination of 2 from "found" number of objects
				if (found >= 2)
				{
					int num = 1;
					for (int n = found; n > found - 2; n--)
					{
						num *= n;
					}
					num /= 2;
					count += num;
				}
			}
		}
		
		cout << "Case #" << (t + 1) << ": " << count << endl;
	}
	
	return 0;
}
