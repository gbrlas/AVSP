#include <iostream>

using namespace std;

int main()
{
	int T, N, S, p;
	int scores[100];
	int best[100];
	int tmp[100];
	
	int bestScoreWithoutSurprise[31] = {0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 10};
	int bestScoreWithSurprise[31] = {0, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10, 10};
	
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> S >> p;
		for (int n = 0; n < N; n++)
		{
			cin >> scores[n];
		}
		
		// generate best without surprise
		best[0] = bestScoreWithoutSurprise[scores[0]] >= p ? 1 : 0;
		for (int n = 1; n < N; n++)
		{
			best[n] = best[n - 1] + (bestScoreWithoutSurprise[scores[n]] >= p ? 1 : 0);
		}
		
		// iterate best with S surprise
		for (int s = 0; s < S; s++)
		{
			// copy best to tmp
			memcpy(tmp, best, 100 * sizeof(int));
			
			best[0] = bestScoreWithSurprise[scores[0]] >= p ? 1 : 0;
			for (int n = 1; n < N; n++)
			{
				best[n] = max(best[n - 1], tmp[n - 1] + (bestScoreWithSurprise[scores[n]] >= p ? 1 : 0));
			}
		}
		
		cout << "Case #" << (t + 1) << ": " << best[N - 1] << endl;
	}
	
	return 0;
}
