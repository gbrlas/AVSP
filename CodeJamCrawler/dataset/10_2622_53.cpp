#include <stdio.h>
#include <memory.h>
#include <iostream.h>

int main(int argc, char ** argv)
{
	int	T,
		R,
		K,
		N;
	int i, j, k;
	const int NMax = 10;
	int g[NMax],
		board[NMax],
		gain[NMax];

	int total;

	freopen("p3is.txt", "r", stdin);
	freopen("p3os.txt", "w", stdout);

	cin >> T;
	for ( i=0; i<T; i++ )
	{
		cin >> R >> K >> N;
		for ( j=0; j<N; j++ )
			cin >> g[j];

		memset(gain, 0, sizeof(gain));
		for ( j=0; j<N; j++)
			for (k=0; k<N; k++)
				if ( gain[j] + g[(j+k)%N] <= K )
				{
					gain[j] += g[(j+k)%N];
					board[j] = k + 1;
				}
				else
				{
					break;
				}

		total = 0;
		j = 0;
		for ( k=0; k<R; k++ )
		{
			total += gain[j];
			j = ( j+ board[j] ) % N;
		}
		cout << "Case #" << i+1 << ": " << total << endl;
	}

	return 0;
}