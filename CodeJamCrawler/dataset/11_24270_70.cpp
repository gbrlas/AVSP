#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int T; cin >> T;
	for(int No = 1; No <= T; No++)
	{
		int N; cin >> N;
		int ans = 0;
		int bPos = 1, oPos = 1, bWait = 0, oWait = 0;
		while(N--)
		{
			char R;
			int P;
			cin >> R >> P;
			if(R == 'O')
			{
				int spend = max(0, abs(P-oPos) - oWait) + 1;
				ans += spend;
				bWait += spend;
				oWait = 0;
				oPos = P;
			}
			else
			{
				int spend = max(0, abs(P-bPos) - bWait) + 1;
				ans += spend;
				oWait += spend;
				bWait = 0;
				bPos = P;
			}
		}
		cout << "Case #" << No << ": " << ans << endl;
	}
}
