#include <iostream>

using namespace std;
#define CLR(a) memset(a,0,sizeof(a))

long T;
long M[3][3];
long long sum;
long long n, A, B, C, D, x, y, m;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d", &T);
	//printf("%d", T);
	for (long a = 0; a < T; a ++)
	{
		CLR(M);
		cin >> n >> A >> B >> C >> D >> x >> y >> m;
		for (long b = 0; b < n; b ++)
		{
			M[x%3][y%3]++;

			x = (x*A+B)%m;
			y = (y*C+D)%m;
		}

		sum = 0;
		long tt;
		for (long x1 = 0; x1 < 3; x1 ++)
			for (long y1 = 0; y1 < 3; y1 ++)
				for (long x2 = 0; x2 < 3; x2 ++)
					for (long y2 = 0; y2 < 3; y2 ++)
						for (long x3 = 0; x3 < 3; x3 ++)
							for (long y3 = 0; y3 < 3; y3 ++)
								if (((x1+x2+x3)==0 || (x1+x2+x3)==3 || (x1+x2+x3)==6 || (x1+x2+x3)==9) &&
									((y1+y2+y3)==0 || (y1+y2+y3)==3 || (y1+y2+y3)==6 || (y1+y2+y3)==9))
								{
									tt = M[x1][y1];
									M[x1][y1]--;
									tt *= M[x2][y2];
									M[x2][y2]--;
									tt *= M[x3][y3];
									sum += tt;
									M[x2][y2]++;
									M[x1][y1]++;
								}

		cout << "Case #" << (a+1) << ": " << sum/6 << "\n";
	}

	return 0;
}