#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int T;
ll N;
vector<int> num;


int main()
{

	cin >> T;

	for(int t=0; t<T; t++)
	{
		cin >> N;

		num.clear();
		while(N>0)
		{
			num.insert(num.begin(), N%10);
			N /= 10;
		}

		int L = num.size();
		int i;
		int max = 0;
		for (i = L-1; i>=0; i--)
		{
			if (num[i] > max)
				max = num[i];
			else if (num[i] < max) // van nala nagyobb utana
			{
				
				int min = 10;
				int minidx = -1;
				for(int j=i+1; j<L; j++) // legkisebb, ami nagyobb
				{
					if (num[j] > num[i] && num[j] < min)
					{
						min = num[j];
						minidx = j;
					}
				}
				
				int tmp = num[i];
				num[i] = num[minidx];
				num[minidx] = tmp;
				sort(num.begin()+(i+1), num.end());
				break;
			}
		}

		if (i<0) {
			sort(num.begin(), num.end());
			num.insert(num.begin(), 0);
			int j=0;
			while(num[j]==0)
				j++;
			num[0]=num[j];
			num[j]=0;
		}

		
		cout << "Case #" << t+1 << ": ";

		for(int i=0; i<num.size(); i++)
		cout << num[i];

		cout << endl;
	}

	return 0;
}
