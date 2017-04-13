//Code Jam 1B

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, cs = 1;
	cin >> N;
	
	while(N--)
	{
		int n, A, B, C, D, x, y, M, ans = 0;
		cin >> n >> A >> B >> C >> D >> x >> y >> M;
		
		vector <int> xx(n), yy(n);
		xx[0] = x;
		yy[0] = y;
		
		for(int i = 1; i < n; i++)
		{
			x = ((long long)A * x + B) % M;
  			y = ((long long)C * y + D) % M;
			xx[i] = x;
			yy[i] = y;
		}
		
		for(int a = 0; a < n - 2; a++)
		{
			for(int b = a + 1; b < n - 1; b++)
			{
				for(int c = b + 1; c < n; c++)
				{
					if( (((long long)xx[a] + xx[b] + xx[c]) % 3 == 0) && (((long long)yy[a] + yy[b] + yy[c]) % 3 == 0) )
						ans++;
				}
			}
		}
		
		cout << "Case #" << cs++ << ": " << ans << endl;
	}
	return 0;
}
