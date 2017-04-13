#include <iostream>
#include <vector>
#include <algorithm>

#define ALL(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()
#define PB(a) push_back(a)

using namespace std;

int main()
{
	int N;
	cin >> N;
	
	for(int cs = 1; cs <= N; cs++)
	{
		int P, K, L;
		cin >> P >> K >> L;
		vector <int> freq(L);
		
		for(int i = 0; i < L; i++)
		{
			cin >> freq[i];
		}
		
		sort(freq.rbegin(), freq.rend());
		int round = 1, c = 0;
		long long ans = 0;
		bool poss = true;
		for(int i = 0; i < L; i++)
		{
			//cout << "freq" << freq[i] << endl;
			ans += ((long long)freq[i] * round);
			c++;
			if(c == K)
			{
				round++;
				c = 0;
			}
			if(round > P && i != L - 1)
			{
				poss = false;
				break;
			}
		}
		
		if(poss)
			cout << "Case #" << cs << ": " << ans << endl;
		else
			cout << "Case #" << cs << ": " << "Impossible" << endl;
	}
	return 0;
}
