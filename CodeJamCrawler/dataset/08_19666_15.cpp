#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	for (int i=0; i<N; ++i)
	{
		int P, K, L;
		cin >> P >> K >> L;
		
		vector<int> freqs(L);
		for (int j=0; j<L; ++j)
			cin >> freqs[j];
			
		sort(freqs.begin(), freqs.end());
		reverse(freqs.begin(), freqs.end());
		
		int presses=0;
		long long ret=0;
		for (int j=0; j<L; ++j)
		{
			if (j%K == 0)
				presses++;
			ret += (presses*freqs[j]);
			
//			cout << "freqs[" << j << "]: " << freqs[j] << endl;
//			cout << "presses: " << presses << endl;
//			cout << "ret: " << ret << endl << endl;
		}
		cout << "Case #" << i+1 << ": " << ret << endl;
	}
}
